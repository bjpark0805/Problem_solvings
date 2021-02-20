#include <iostream>
#include <string>

using namespace std;

int cache[95][101][101];
string board[101];
string word;
int N, M, K;

int counting(int word_index, int x, int y){
	if(word_index == word.size()) return 1;
	int& ref = cache[word_index][x][y];
	if(ref != -1) return ref;

	int path = 0;
	for(int i = -K; i <= K; ++i){
		if(i == 0 || i + x < 0 || i + x >= N) continue;
		else if(board[x + i][y] == word[word_index]) {
			path += counting(word_index + 1, x + i, y);
			// cout << x + i << " " << y << " " << board[x + i][y] << endl;
		}
	}
	for(int j = -K; j <= K; ++j){
		if(j == 0 || j + y < 0 || j + y >= M) continue;
		else if(board[x][y + j] == word[word_index]) {
			path += counting(word_index + 1, x, y + j);
			// cout << x << " " << y + j << " " << board[x][y + j] << endl;
		}
	}

	return ref = path;
}

int main(){
	cin >> N >> M >> K;

	for(int i = 0; i < N; ++i){
		cin >> board[i];
	}
	cin >> word;

	for(int i = 0; i < 95; ++i){
		for(int j = 0; j < 101; ++j){
			for(int k = 0; k < 101; ++k){
				cache[i][j][k] = -1;
			}
		}
	}

	int path = 0;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j){
			if(board[i][j] == word[0]){
				path += counting(1, i, j);
			}
		}
	}
	cout << path << endl;
	return 0;
}