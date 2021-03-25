#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, mn = 11;

int max_h(int a, int b){
	return a >= b ? a : b;
}
int min_h(int a, int b){
	return a < b ? a : b;
}
int recEscape(vector<string> board, int row, int col, int b_row, int b_col, int prev_d, int cnt){
	if (cnt >= 11)
		return 11;
	vector<int> ans(4, 11);
	
	for (int d = 0; d < 4; ++d){
		if(d == prev_d) continue;
		bool end = false;
		// 0 : west, 1: north, 2: east, 3: south
		int c_mul = (d - 1) * (abs(d - 1)%2);
		int r_mul = (d - 2) * (abs(d - 2)%2);
		int row_t, col_t, b_row_t, b_col_t;
		vector<string> board_e(board);
		bool blue = false;
		for (int i = 1; i < max_h(M, N); ++i){
			if (board_e[row + i * r_mul][col + i * c_mul] == 'B') blue = true;
			else if (board_e[row + i * r_mul][col + i * c_mul] == 'O'){
				end = true;
				if (not blue){
					ans[d] = cnt + 1;
					board_e[row][col] = '.';
				}
				break;
			}
			else if (board_e[row + i * r_mul][col + i * c_mul] == '#'){
				if (blue) i -= 1;
				row_t = row + (i - 1) * r_mul;
				col_t = col + (i - 1) * c_mul;
				board_e[row][col] = '.';
				board_e[row_t][col_t] = 'R';
				break;
			}				
		}
		if (blue && not end){
			b_row_t = row_t + r_mul;
			b_col_t = col_t + c_mul;
		}
		else{
			for (int i = 1; i < max_h(M, N); ++i){
				if (board_e[b_row + i * r_mul][b_col + i * c_mul] == 'O'){
					end = true;
					ans[d] = 11;
					break;
				}
				else if (board_e[b_row + i * r_mul][b_col + i * c_mul] == '#' || 
					board_e[b_row + i * r_mul][b_col + i * c_mul] == 'R'){
					b_row_t = b_row + (i - 1) * r_mul;
					b_col_t = b_col + (i - 1) * c_mul;
					break; 
				}
			}
		}	

		if (end){
			if(ans[d] == 11) continue;
			else break;
		}
		board_e[b_row][b_col] = '.';
		board_e[b_row_t][b_col_t] = 'B';
		
		ans[d] = recEscape(board_e, row_t, col_t, b_row_t, b_col_t, d, cnt + 1);
	}
	
	return *min_element(ans.begin(), ans.end());
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	vector<string> board(N);
	for(int i = 0; i < N; ++i){
		string s;
		cin >> s;
		board[i] = s;
	}
	int row, col, b_row, b_col;
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < M; ++j){
			if (board[i][j] == 'R'){
				row = i;
				col = j;
			}
			else if(board[i][j] == 'B'){
				b_row = i;
				b_col = j;
			}
		}
	}
	int ans = recEscape(board, row, col, b_row, b_col, -1, 0);
	if (ans == 11) ans = -1;
	cout << ans << "\n";
	return 0;
}