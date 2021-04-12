#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int dr[4] = {0, -1, 0, 1}, dc[4] = {-1,0,1,0};
vector<vector<int> > heights;
vector<vector<bool> > visited;

void dfs(int r, int c, int h){
	visited[r][c] = true;
	for(int d = 0; d < 4; ++d){
		int nr = r + dr[d], nc = c + dc[d];
		if(nr >= 0 and nr < N and nc >= 0 and nc < N and not visited[nr][nc] and heights[nr][nc] > h)
			dfs(nr, nc, h);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	heights.resize(N);
	int minh = 101, maxh = 0;
	for(int i = 0; i < N; ++i){
		heights[i].resize(N);
		for(int j = 0; j < N; ++j){
			cin >> heights[i][j];
			minh = min(minh, heights[i][j]);
			maxh = max(maxh, heights[i][j]);
		}
	}
	int ans = 1;
	for(int h = minh; h < maxh; ++h){
		visited.clear();
		visited.resize(N);
		for(int i = 0; i < N; ++i){
			visited[i].resize(N, false);
		}
		int tmp = 0;
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < N; ++j){
				if(not visited[i][j] and heights[i][j] > h){
					dfs(i, j, h);
					tmp += 1;
				}
			}
		}
		ans = max(ans, tmp);
	}

	cout << ans << "\n";
	return 0;
}