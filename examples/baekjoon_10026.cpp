#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int dr[4] = {0, -1, 0, 1}, dc[4] = {-1, 0, 1, 0};
vector<vector<bool> > visited, visited_rg;
vector<string> grid, grid_rg;
int N;

void dfs(int r, int c, bool rg){
	if(rg) visited_rg[r][c] = true;
	else visited[r][c] = true;
	for(int d = 0; d < 4; ++d){
		int nr = r + dr[d], nc = c + dc[d];
		if(nr < 0 or nr >= N or nc < 0 or nc >= N) continue;
		if(rg){
			if(not visited_rg[nr][nc] and grid_rg[r][c] == grid_rg[nr][nc]) dfs(nr, nc, true);
		}
		else{
			if(not visited[nr][nc] and grid[r][c] == grid[nr][nc]) dfs(nr, nc, false);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	grid.resize(N);
	grid_rg.resize(N);
	for(int i = 0; i < N; ++i){
		cin >> grid[i];
		string s = "";
		for(int j = 0; j < N; ++j){
			if(grid[i][j] == 'G') s += 'R';
			else s += grid[i][j];
		}
		grid_rg[i] = s;
	}

	visited.resize(N);
	visited_rg.resize(N);
	for(int i = 0; i < N; ++i){
		visited[i].resize(N, false);
		visited_rg[i].resize(N, false);
	}
	int ans1 = 0, ans2 = 0;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if(not visited[i][j]) {dfs(i, j, false); ans1 += 1;}
			if(not visited_rg[i][j]) {dfs(i, j, true); ans2 += 1;}
		}
	}

	cout << ans1 << " " << ans2 << "\n";
	return 0;
}