// 1시간 38분 소요
// 시뮬레이션
// 디버깅에서 걸렸는데 옮겨쓸 때 오타였음
// 이런건 진짜 어쩔수 없으니 꼼꼼하게 하길.


#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int dr[5] = {0, -1, 1, 0, 0};
int dc[5] = {0, 0, 0, 1, -1};
vector<vector<pair<int, pair<int, int> > > > board;
int R, C;
void Print(){
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			cout << board[i][j].first << " ";
		}
		cout << endl;
	}
	cout << "------------------------------\n";
}
void fishing(){
	//shark
	// size, (speed, direction)
	int answer = 0;
	
	for(int j = 0; j < C; ++j){
		// fishing
		for(int r = 0; r < R; ++r){
			if(board[r][j].first > 0){
				// cout << board[r][j].first << endl;
				answer += board[r][j].first;
				board[r][j] = make_pair(0, make_pair(0, 0));
				break;
			}
		}
		// shark move
		vector<vector<pair<int, pair<int, int> > > > board_temp(R);
		for(int i = 0; i < R; ++i){
			board_temp[i].resize(C);
			for(int j = 0; j < C; ++j){
				board_temp[i][j] = make_pair(0, make_pair(0, 0));
			}
		}
		for(int r = 0; r < R; ++r){
			for(int c = 0; c < C; ++c){
				// cout << r << " " << c << endl;
				// Print();
				if(board[r][c].first == 0) continue;
				int d = board[r][c].second.second;
				int s = board[r][c].second.first;
				int nr = r, nc = c;
				if(d == 1){
					if(s <= r) nr = r - s;
					else{
						int div = (s - r)/(R-1);
						if(div % 2 == 0){
							d = 2;
							nr = (s - r)%(R-1);
						}
						else{
							nr = R - 1 - (s - r) % (R - 1);
						}
					}
				}
				else if(d == 2){
					if(s <= R - 1 - r) nr = r + s;
					else{
						int div = (s - R + 1 + r)/(R - 1);
						if(div % 2 == 0){
							d = 1;
							nr = R - 1 - (s - R + 1 + r)%(R-1);
						}
						else{
							nr = (s - R + 1 + r) % (R - 1);
						}
					}
				}
				else if(d == 3){
					if(s <= C - 1 - c) nc = c + s;
					else{
						int div = (s - C + 1 + c)/(C-1);
						if(div % 2 == 0){
							d = 4;
							nc = C - 1 - (s - C + 1 + c)%(C-1);
						}
						else{
							nc = (s - C + 1 + c)%(C-1);
						}
					}
				}
				else{ // d == 4
					if(s <= c) nc = c - s;
					else{
						int div = (s - c)/(C - 1);
						if(div % 2 == 0){
							d = 3;
							nc = (s - c) % (C - 1);
						}
						else{
							nc = C - 1 - (s - c) % (C - 1);
						}
					}
				}
				pair<int, pair<int, int> > shark_temp = make_pair(board[r][c].first, make_pair(s, d));
				board[r][c] = make_pair(0, make_pair(0,0));
				if(board_temp[nr][nc].first < shark_temp.first) board_temp[nr][nc] = shark_temp;
			}
		}
		board = board_temp;
	}
	cout << answer << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M;
	cin >> R >> C >> M;
	board.resize(R);
	for(int i = 0; i < R; ++i){
		board[i].resize(C, make_pair(0, make_pair(0, 0)));
	}
	for(int i = 0; i < M; ++i){
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		board[r-1][c-1] = make_pair(z, make_pair(s, d));
	}
	fishing();
	return 0;
}

