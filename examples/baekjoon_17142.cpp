// 55분 정도 소요
// 완전탐색(dfs), bfs(최단경로)
// 1. 문제 이해를 제대로 못해서 약간 시간 썼고, 2. 최대값 설정 잘못해서 디버깅 한번

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

int min_v = 1000000;
int target_num;
int N, M;
vector<bool> choose_virus;
vector<pair<int, int> > viruses;
vector<vector<int> > lab;

void bfs(){
	if(target_num == 0) {
		min_v = 0;
		return;
	}
	int temp_num = target_num;
	vector<vector<int> > lab_copy(lab);

	queue<pair<int, int> > q;
	for(int i = 0; i < choose_virus.size(); ++i){
		if(choose_virus[i]){
			lab_copy[viruses[i].first][viruses[i].second] = 3;
			q.push(viruses[i]);
		}
	}
	int level = 1;
	while(!q.empty()){
		int qsize = q.size();
		for(int i = 0; i < qsize; ++i){
			int r = q.front().first, c = q.front().second;
			q.pop();
			for(int d = 0; d < 4; ++d){
				int nr = r + dr[d], nc = c + dc[d];
				if(nr < 0 or nr >= N or nc < 0 or nc >= N or lab_copy[nr][nc] == 1 or lab_copy[nr][nc] == 3)
					continue;
				if(lab_copy[nr][nc] == 0) {
					temp_num--;
					if(temp_num == 0) {
						min_v = min(min_v, level);
						return;
					}
				}
				q.push(make_pair(nr, nc));
				lab_copy[nr][nc] = 3;
			}
		}
		level++;		
	}

}	

void dfs(int curr, int cnt){
	if(cnt == M){
		bfs();
		return;
	}
	if(curr == choose_virus.size()) return;
	dfs(curr + 1, cnt);
	choose_virus[curr] = true;
	dfs(curr + 1, cnt + 1);
	choose_virus[curr] = false;
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	lab.resize(N);
	for(int i = 0; i < N; ++i){
		lab[i].resize(N);
		for(int j = 0; j < N; ++j){
			cin >> lab[i][j];
			if(lab[i][j] == 2) viruses.push_back(make_pair(i, j));
			else if(lab[i][j] == 0) target_num++;
		}
	}
	choose_virus.resize(viruses.size(), false);
	dfs(0, 0);
	if(min_v == 1000000) min_v = -1;
	cout << min_v << "\n";
	return 0;
}
