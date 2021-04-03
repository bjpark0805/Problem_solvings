#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, r, c, d, next_d, next_c, next_r;
	cin >> N >> M;
	cin >> r >> c >> d;
	vector<vector<int> > board(N, vector<int>(M, 0));
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j){
			cin >> board[i][j];
		}
	}
	
	bool pass = false;
	int cnt = 0;
	while(true){
		if(board[r][c] == 0){cnt += 1; board[r][c] = 2;}
		pass = false;
		for(int i = 3; i >= 0; --i){
			next_d = (d + i)%4;
			next_r = r; next_c = c;
			if(next_d % 2) next_c += 2 - next_d;
			else next_r += next_d - 1;
			if(next_r >= 0 && next_r < N && next_c >= 0 && next_c < M && board[next_r][next_c] == 0){
				r = next_r;
				c = next_c;
				d = next_d;
				pass = true;
				break;
			}
		}
		if(pass) continue;
		next_d = (d + 2)%4;
		if(next_d % 2) c += 2 - next_d;
		else r += next_d - 1;
		if(board[r][c] == 1) break;
	}

	cout << cnt << "\n";
	return 0;
}