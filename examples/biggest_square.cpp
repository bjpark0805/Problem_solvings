#include <iostream>
#include <vector>
using namespace std;

int board[1001][1001] = {0};
int cache[1001][1001];
int row1[1001][1001];
int col1[1001][1001];
int max_value = -1;
int N, M;

int biggest_squre(int n, int m){
	int& ref = cache[n][m];
	if(ref != -1) return ref;

	if(n == 1 || m == 1) ref = board[n][m];
	else if(board[n][m] == 1){
		int& r = row1[n][m];
		int& c = col1[n][m];
		
		ref = min(min(r, c), biggest_squre(n - 1, m - 1) + 1); 
	}
	else ref = 0;
	
	if(ref > max_value) max_value = ref;
	return ref;
}

void fill_row(){
	int temp = 0;
	for(int i = 1; i <= N; ++i){
		for(int j = 1; j <= M; ++j){
			int& r = row1[i][j];
			if(board[i][j] == 0) {
				r = temp;
				temp = 0;
			}
			else {
				temp++;
				r= temp;
			}
		}
	}
}

void fill_col(){
	int temp = 0;
	for(int j = 1; j <= M; ++j){
		for(int i = 1; i <= N; ++i){
			int& c = col1[i][j];
			if(board[i][j] == 0) {
				c = temp;
				temp = 0;
			}
			else {
				temp++;
				c= temp;
			}
		}
	}
}

int main(){
	cin >> N >> M;
	for(int i = 1; i <= N; ++i){
		string s;
		cin >> s;
		for(int j = 1; j <= M; ++j){
			board[i][j] = s[j - 1] - 48;
		}
	}
	for(int i = 0; i <= N; ++i){
		for(int j = 0; j <= M; ++j){
			cache[i][j] = -1;
			row1[i][j] = -1;
			col1[i][j] = -1;
		}
	}
	fill_row();
	fill_col();
	for(int i = 1; i <= N; ++i){
		for(int j = 1; j <= M; ++j){
			biggest_squre(i, j);
		}
	}
	
	cout << max_value * max_value << endl;
	return 0;
}