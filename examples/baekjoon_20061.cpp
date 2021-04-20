// 1시간 반 정도 소요
// 시뮬레이션
// 인덱스 하나 잘못 생각한거 디버깅
// 전체적인 난이도는 그렇게 높게 느껴지지 않음.

#include <iostream>
#include <vector>

using namespace std;

int N, score = 0;
vector<vector<bool> > blue(4, vector<bool>(7, false));
vector<vector<bool> > green(7, vector<bool>(4, false));


void Print(){
	cout << "-------------------------------\n";
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 6; ++j){
			cout << blue[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for(int i = 0; i < 6; ++i){
		for(int j = 0; j < 4; ++j){
			cout << green[i][j] << " ";
		}
		cout << endl;
	}
}
void keep_last_true(){
	blue[0][6] = true;
	blue[1][6] = true;
	blue[2][6] = true;
	blue[3][6] = true;
	green[6][0] = true;
	green[6][1] = true;
	green[6][2] = true;
	green[6][3] = true;
}
void rotate_b(int i){
	for(int j = i; j >= 0; --j){
		blue[0][j+1] = blue[0][j];
		blue[1][j+1] = blue[1][j];
		blue[2][j+1] = blue[2][j];
		blue[3][j+1] = blue[3][j];
	}
	blue[0][0] = false;
	blue[1][0] = false;
	blue[2][0] = false;
	blue[3][0] = false;
}

void rotate_g(int i){
	for(int j = i; j >= 0; --j){
		green[j+1] = green[j];
	}
	green[0][0] = false;
	green[0][1] = false;
	green[0][2] = false;
	green[0][3] = false;
}

void check_b(){
	for(int i = 2; i <= 5; ++i){
		if(blue[0][i] and blue[1][i] and blue[2][i] and blue[3][i]) {
			rotate_b(i - 1);
			score++;
		}
	}

	if(blue[0][0] or blue[1][0] or blue[2][0] or blue[3][0]) rotate_b(5);
	if(blue[0][1] or blue[1][1] or blue[2][1] or blue[3][1]) rotate_b(5);
}

void check_g(){
	for(int i = 2; i <= 5; ++i){
		if(green[i][0] and green[i][1] and green[i][2] and green[i][3]) {
			rotate_g(i - 1);
			score++;
		}
	}
	if(green[0][0] or green[0][1] or green[0][2] or green[0][3]) rotate_g(5);
	if(green[1][0] or green[1][1] or green[1][2] or green[1][3]) rotate_g(5);
}

void monominodomino(int t, int x, int y){
	if(t == 1){
		// check blue
		for(int c = 2; c <= 6; ++c){
			if(blue[x][c]){
				blue[x][c-1] = true;
				break;
			}
		}
		// check green
		for(int r = 2; r <= 6; ++r){
			if(green[r][y]){
				green[r-1][y] = true;
				break;
			}
		}
	}
	else if(t == 2){
		for(int c = 2; c <= 6; ++c){
			if(blue[x][c]){
				blue[x][c-1] = true;
				blue[x][c-2] = true;
				break;
			}
		}
		for(int r = 2; r <= 6; ++r){
			if(green[r][y] or green[r][y+1]){
				green[r-1][y] = true;
				green[r-1][y+1] = true;
				break;
			}
		}
	}
	else{ // t == 3
		for(int c = 2; c <= 6; ++c){
			if(blue[x][c] or blue[x+1][c]){
				blue[x][c-1] = true;
				blue[x+1][c-1] = true;
				break;
			}
		}
		for(int r = 2; r <= 6; ++r){
			if(green[r][y]){
				green[r-1][y] = true;
				green[r-2][y] = true;
				break;
			}
		}
	}

	check_g();
	check_b();
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int t, x, y;
	for(int i = 0; i < N; ++i){
		cin >> t >> x >> y;
		keep_last_true();
		monominodomino(t, x, y);
	}

	int cnt = 0;
	for(int i = 0; i < 4; ++i){
		for(int j = 2; j < 6; ++j){
			if(blue[i][j]) cnt++;
		}
	}
	for(int i = 2; i < 6; ++i){
		for(int j = 0; j < 4; ++j){
			if(green[i][j]) cnt++;
		}
	}

	cout << score << "\n" << cnt << "\n";

	return 0;
}

