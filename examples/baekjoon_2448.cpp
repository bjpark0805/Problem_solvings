#include <cstdio>
#include <vector>
std::vector<std::vector<char> > board;

void star11(int size, int start_r, int start_c){
	if(size == 3){
		board[start_r][start_c] = '*';
		board[start_r + 1][start_c - 1] = '*';
		board[start_r + 1][start_c + 1] = '*';
		for(int i = -2; i < 3; ++i){
			board[start_r + 2][start_c + i] = '*';
		}
		return;
	}
	int sub_size = size/2;
	star11(sub_size, start_r, start_c);
	star11(sub_size, start_r + sub_size, start_c - sub_size);
	star11(sub_size, start_r + sub_size, start_c + sub_size);
}

void draw_stars(){
	for(int i = 0; i < board.size(); ++i){
		for(int j = 0; j < board[0].size(); ++j){
			printf("%c", board[i][j]);
		}
		if(i != board.size() - 1) printf("\n");
	}
}

int main(){
	int N;
	scanf("%d",&N);
	board.resize(N, std::vector<char>(2 * N - 1, ' '));
	star11(N, 0, N - 1);
	draw_stars();
	return 0;
}