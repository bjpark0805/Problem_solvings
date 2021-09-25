#include <iostream>
#include <vector>
#include <utility>

std::vector<std::vector<int> > sudoku(9, std::vector<int>(9, 0));
std::vector<std::pair<int, int> > empty_rc;
int cnt = 0;
bool finished = false;

void Print_sudoku(){
	for(int i = 0; i < 9; ++i){
		for(int j = 0; j < 9; ++j){
			std::cout << sudoku[i][j] << " ";
		}
		std::cout << "\n";
	}
}

void backtracking(int idx){
	// std::cout << idx << "finished: " << finished<< std::endl;
	if(finished) return;
	if(idx == cnt) {
		Print_sudoku();
		finished = true;
		return;
	}
	std::vector<bool> possible(10, true);
	int r = empty_rc[idx].first, c = empty_rc[idx].second;
	int rs = r/3, cs = c/3;
	for(int i = 0; i < 9; ++i){
		possible[sudoku[i][c]] = false;
		possible[sudoku[r][i]] = false;
	}
	for(int i = 3 * rs; i < 3 * rs + 3; ++i){
		for(int j = 3 * cs; j < 3 * cs + 3; ++j){
			possible[sudoku[i][j]] = false;
		}
	}
	for(int i = 1; i < 10; ++i){
		if(possible[i]) {
			sudoku[r][c] = i;
			backtracking(idx + 1);
			sudoku[r][c] = 0;
		}
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	for(int i = 0; i < 9; ++i){
		for(int j = 0; j < 9; ++j){
			std::cin >> sudoku[i][j];
			if(sudoku[i][j] == 0) {
				empty_rc.push_back(std::make_pair(i, j));
				cnt++;
			}
		}
	}

	backtracking(0);
	return 0;
}

