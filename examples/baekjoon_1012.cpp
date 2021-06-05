#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int N, M, cnt;
vector<vector<int> > cabbage;
vector<vector<bool> > visited;
void dfs(int r, int c){
	for(int d = 0; d < 4; ++d){
		int r_diff = 0, c_diff = 0;
		if(d % 2) r_diff = d - 2;
		else c_diff = d - 1;
		int new_r = r + r_diff, new_c = c + c_diff;
		if(new_c >= 0 and new_c < M and new_r >= 0 and new_r < N and cabbage[new_r][new_c] and not visited[new_r][new_c]){
			visited[new_r][new_c] = true;
			dfs(new_r, new_c);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	int K, X, Y;
	for(int i = 0; i < T; ++i){
		cin >> M >> N >> K;
		cnt = 0;
		cabbage.resize(0);
		cabbage.resize(N);
		visited.resize(0);
		visited.resize(N);
		for(int j = 0; j < N; ++j){
			cabbage[j].resize(M, 0);
			visited[j].resize(M, false);
		}
		for(int k = 0; k < K; ++k){
			cin >> X >> Y;
			cabbage[Y][X] = 1;
		}
		for(int j = 0; j < N; ++j){
			for(int k = 0; k < M; ++k){
				if(cabbage[j][k] and not visited[j][k]){
					visited[j][k] = true;
					cnt += 1;
					dfs(j, k);
				}
			}
		}
		cout << cnt << "\n";
	}
	
	return 0;
}