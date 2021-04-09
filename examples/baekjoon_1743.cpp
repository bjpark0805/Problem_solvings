#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int> > floors;
vector<pair<int, int> > trash;
vector<vector<bool> > visited;
int dr[4] = {0,-1,0,1};
int dc[4] = {-1,0,1,0};

int dfs(int r, int c){
	visited[r][c] = true;
	int cnt = 1;
	for(int d = 0; d < 4; ++d){
		int r1 = r + dr[d], c1 = c + dc[d];
		if(r1 > 0 and r1 <= N and c1 > 0 and c1 <= M and not visited[r1][c1] and floors[r1][c1]) cnt += dfs(r1, c1);
	}
	return cnt;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K;
	cin >> N >> M >> K;
	int r, c;
	floors.resize(N + 1);
	visited.resize(N + 1);

	trash.resize(K);
	for(int i = 1; i < N + 1; ++i){
		floors[i].resize(M + 1, 0);
		visited[i].resize(M + 1, false);
	}
	for(int i = 0; i < K; ++i){
		cin >> r >> c;
		floors[r][c] = 1;
 		trash[i] = make_pair(r, c);
	}
	int ans = 0;
	for(int i = 0; i < K; ++i){
		r = trash[i].first;
		c = trash[i].second;
		if(not visited[r][c]) {
			ans = max(ans, dfs(r, c));
		}
	}
	cout << ans << "\n";
	return 0;
}