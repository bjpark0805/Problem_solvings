#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>

std::vector<int> color_papers = {5, 5, 5, 5, 5};
int cnt = 0;
int minv = 26;
std::vector<std::vector<bool> > v(10, std::vector<bool>(10, false));

void backtracking(int r, int c){
	// printf("%d %d %d\n", r, c, cnt);
	if(cnt == 0){
		int unused = 0;
		for(int i = 0; i < 5; ++i){
			unused += color_papers[i];
		}
		minv = std::min(minv, 25 - unused);
		return;
	}
	if(v[r][c]){
		for(int s = 0; s < 5; ++s){
			if(color_papers[s] == 0) continue;
			bool possible = true;
			for(int i = 0; i < s + 1; ++i){
				for(int j = 0; j < s + 1; ++j){
					if(r+i >= 10 or c + j >= 10 or not v[r+i][c+j]) {
						possible = false;
						break;
					}
				}
			}
			if(possible){
				for(int i = 0; i < s + 1; ++i){
					for(int j = 0; j < s + 1; ++j){
						v[r+i][c+j] = false;
					}
				}
				cnt -= (s + 1) * (s + 1);
				color_papers[s] -= 1;
				if(c + s == 9 and r == 9) backtracking(r + 1, c + s + 1);
				else if(c + s == 9) backtracking(r + 1, 0);
				else backtracking(r, c + s + 1);
				cnt += (s + 1)*(s + 1);
				color_papers[s] += 1;
				for(int i = 0; i < s + 1; ++i){
					for(int j = 0; j < s + 1; ++j){
						v[r+i][c+j] = true;
					}
				}
			}
		}

	}
	else{
		if(c == 9 and r == 9) return;
		else if(c == 9){
			backtracking(r+1, 0);
		}
		else{
			backtracking(r, c+1);
		}
	}
}

int main(){
	for(int i = 0; i < 10; ++i){
		for(int j = 0; j < 10; ++j){
			int tmp = 0;
			scanf("%d", &tmp);
			v[i][j] = (tmp == 1);
			if(tmp) cnt++;
		}
	}
	if(cnt < 5 * (25 + 16 + 9 + 4 + 1)){
		backtracking(0, 0);
	}
	if(minv == 26) minv = -1;
	printf("%d\n", minv);
	return 0;
}