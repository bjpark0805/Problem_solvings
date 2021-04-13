// 약 30분 정도 소요
// 컴포넌트 별로 다뤄주는 dfs 문제
// 난이도 무난

#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>
using namespace std;

int N, L, R, cnt, sum;
vector<vector<int> > country;
vector<vector<bool> > visited;
vector<pair<int, int> > alignment;
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

void dfs(int r, int c){
	cnt += 1;
	sum += country[r][c];
	visited[r][c] = true;
	alignment.push_back(make_pair(r, c));
	for(int d = 0; d < 4; ++d){
		int nr = r + dr[d], nc = c + dc[d];
		if(nr >= 0 and nr < N and nc >= 0 and nc < N 
			and not visited[nr][nc] 
			and abs(country[r][c] - country[nr][nc]) >= L 
			and abs(country[r][c] - country[nr][nc]) <= R
			){
			dfs(nr, nc);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L >> R;
	country.resize(N);
	for(int i = 0; i < N; ++i){
		country[i].resize(N, 0);
		for(int j = 0; j < N; ++j){
			cin >> country[i][j];
		}
	}
	bool move = true;
	int ans = 0;
	while(move){
		move = false;
		visited.resize(0);
		visited.resize(N);
		for(int i = 0; i < N; ++i){
			visited[i].resize(N, false);
		}
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < N; ++j){
				if(not visited[i][j]){
					alignment.clear();
					cnt = 0; 
					sum = 0;
					dfs(i, j);
					if(cnt == 1) continue; 
					move = true;
					for(int i = 0; i < alignment.size(); ++i){
						country[alignment[i].first][alignment[i].second] = sum/cnt;
					}
				}
			}
		}
		if(move) ans += 1;
	}
	cout << ans << "\n";
	return 0;
}