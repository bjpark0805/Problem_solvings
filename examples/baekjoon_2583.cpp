#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N;
vector<vector<bool> > maps;
vector<vector<bool> > visited;

int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

int dfs(int r, int c){
	visited[r][c] = true;
	int cnt = 1;
	for(int d = 0; d < 4; ++d){
		int nr = r + dr[d], nc = c + dc[d];
		if(nr >= 0 and nr < M and nc >= 0 and nc < N and not visited[nr][nc] and not maps[nr][nc]) cnt += dfs(nr, nc);
	}
	return cnt;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K;
	cin >> M >> N >> K;
	maps.resize(M);
	visited.resize(M);
	for(int i = 0; i < M; ++i){
		maps[i].resize(N, false);
		visited[i].resize(N);
	}
	int c1, r1, c2, r2;
	for(int k = 0; k < K; ++k){
		cin >> c1 >> r1 >> c2 >> r2;
		for(int i = r1; i < r2; ++i){
			for(int j = c1; j < c2; ++j){
				maps[i][j] = true;
			}
		}
	}
	vector<int> ans;
	for(int i = 0; i < M; ++i){
		for(int j = 0; j < N; ++j){
			if(not maps[i][j] and not visited[i][j]) ans.push_back(dfs(i, j));
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); ++i){
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}