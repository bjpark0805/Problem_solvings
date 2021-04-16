// 45분 소요
// 시뮬레이션
// 딱히 구현하는데 어려운 느낌은 없었고 적당히 잘 설정해주면 쉽게 풀 수 있었다.

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int dr[5] = {0, 0, 0, -1, 1};
int dc[5] = {0, 1, -1, 0, 0};
int opposite_d[5] = {0, 2, 1, 4, 3}; 

void chess(){
	int N, K;
	cin >> N >> K;
	// 각 보드칸의 말들의 번호와 방향
	vector<vector<vector<pair<int, int> > > > board(N, vector<vector<pair<int, int> > >(N));
	vector<vector<int> > color(N, vector<int>(N));
	vector<pair<int, int> > horse(K); // 각 말의 좌표
	
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cin >> color[i][j];
		}
	}

	for(int i = 0; i < K; ++i){
		int r, c, d;
		cin >> r >> c >> d;
		r--;
		c--;
		horse[i] = make_pair(r, c);
		board[r][c].push_back(make_pair(i, d));
	}

	int cnt = 0;

	while(cnt <= 1000){
		cnt++;
		for(int i = 0; i < K; ++i){
			int r = horse[i].first, c = horse[i].second;
			vector<pair<int, int> > temp;
			while(board[r][c].back().first != i){
				temp.push_back(board[r][c].back());
				board[r][c].pop_back();
			}
			pair<int, int> horse_i = board[r][c].back();
			board[r][c].pop_back();
			int d = horse_i.second;
			int nr = r + dr[d], nc = c + dc[d];
			if(nr < 0 or nr >= N or nc < 0 or nc >= N or color[nr][nc] == 2){
				d = opposite_d[d];
				nr = r + dr[d];
				nc = c + dc[d];
				horse_i.second = d;
			}
			if(nr < 0 or nr >= N or nc < 0 or nc >= N or color[nr][nc] == 2){
				board[r][c].push_back(horse_i);
				while(!temp.empty()){
					board[r][c].push_back(temp.back());
					temp.pop_back();
				}
			}
			else if(color[nr][nc] == 0){ // color: white
				board[nr][nc].push_back(horse_i);
				horse[i].first = nr;
				horse[i].second = nc;
				while(!temp.empty()){
					board[nr][nc].push_back(temp.back());
					horse[temp.back().first].first = nr;
					horse[temp.back().first].second = nc;
					temp.pop_back();
				}
				if(board[nr][nc].size() >= 4){
					cout << cnt << "\n";
					return;
				}
			}
			else{ // color == red
				for(int i = 0; i < temp.size(); ++i){
					board[nr][nc].push_back(temp[i]);
					horse[temp[i].first].first = nr;
					horse[temp[i].first].second = nc;
				}
				board[nr][nc].push_back(horse_i);
				horse[i].first = nr;
				horse[i].second = nc;
				if(board[nr][nc].size() >= 4){
					cout << cnt << "\n";
					return;
				}
			}
		}
	}
	cout << -1 << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	chess();
	return 0;
}