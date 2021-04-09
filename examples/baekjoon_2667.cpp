#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};
int N;
vector<vector<int> > maps;

int dfs(int r, int c){
	int cnt = 1;
	maps[r][c] = 2;
	for(int d = 0; d < 4; ++d){
		int r_ = r + dr[d], c_ = c + dc[d];
		if(r_ >= 0 and r_ < N and c_ >= 0 and c_ < N and maps[r_][c_] == 1) cnt += dfs(r_, c_);
	}
	return cnt;
}

int main(){
	scanf("%d", &N);
	maps.resize(N);
	for(int i = 0; i < N; ++i){
		maps[i].resize(N);
	}
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			scanf("%1d", &maps[i][j]);
		}
	}
	vector<int> ans;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if(maps[i][j] == 1) ans.push_back(dfs(i, j));
		}
	}
	sort(ans.begin(), ans.end());
	printf("%lu\n", ans.size());
	for(int i = 0; i < ans.size(); ++i){
		printf("%d\n", ans[i]);
	}

	return 0;
}