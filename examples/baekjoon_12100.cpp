#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rec_1024(vector<vector<int> > board, int N, int cnt = 0){
	// After 5 movement, return the max value of the board
	if(cnt == 5){
		int maxv = 0;
		for(auto &x: board){
			maxv = max(maxv, *max_element(x.begin(), x.end()));
		}
		return maxv;
	}
	// Move board for 4 direction:
	// W: 0, N: 1, E: 2, S: 3
	// Find max return of 4 direction
	int maxv = 0;
	for(int d = 0; d < 4; ++d){
		vector<vector<int> > board_d = board;
		vector<vector<bool> > bool_board(N, vector<bool>(N, false));
		int r_move = (d - 2)*(d%2);
		int c_move = (d - 1)*((d+1)%2);
		int start = N - 1;
		if(d < 2) start = 0;
		for(int i = 0; i < N; ++i){ // i: row
			for(int j = 0; j < N; ++j){ // j: col
				int r = start - i * (r_move + c_move), c = start - j * (r_move + c_move); 
				if(board_d[r][c] == 0) continue; // if element is 0, pass
				for(int n = 1; n < N; ++n){
					int new_r = r + r_move, new_c = c + c_move;
					if(new_r >= N || new_r < 0 || new_c >=	 N || new_c < 0 || bool_board[new_r][new_c]) break;
					else if(board_d[new_r][new_c] == 0){
						board_d[new_r][new_c] = board_d[r][c];
						board_d[r][c] = 0;
						r = new_r;
						c = new_c;
					}
					else if(board_d[new_r][new_c] == board_d[r][c]){
						board_d[new_r][new_c] *= 2;
						board_d[r][c] = 0;
						bool_board[new_r][new_c] = true;
						break;
					}
					else break;
				}
			}	
		}
		maxv = max(maxv, rec_1024(board_d, N, cnt + 1));
	}
	return maxv;
}
int main(){
	int N;
	cin >> N;
	vector<vector<int> > board(N, vector<int>(N, 0));
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cin >> board[i][j];
		}
	}

	cout << rec_1024(board, N, 0) << endl;
}