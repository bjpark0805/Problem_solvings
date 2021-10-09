#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> maps;
std::vector<std::vector<bool> > visited;
int R, C, K, cnt = 0;
int dr[4] = {0,0,-1,1};
int dc[4] = {-1,1,0,0};

void backtracking(int r, int c, int length){
	if(r == 0 and c == C - 1){
		if(length == K) cnt++;
		return;
	}
	for(int i = 0; i < 4; ++i){
		int nr = r + dr[i], nc = c + dc[i];
		if(nr < 0 or nr >= R or nc < 0 or nc >= C or visited[nr][nc] or maps[nr][nc] == 'T') continue;
		visited[nr][nc] = true;
		backtracking(nr, nc, length+1);
		visited[nr][nc] = false;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> R >> C >> K;
	maps.resize(R);
	visited.resize(R, std::vector<bool>(C, false));
	for(int i = 0; i < R; ++i){
		std::cin >> maps[i];
	}
	visited[R-1][0] = true;
	backtracking(R-1, 0, 1);
	std::cout << cnt << "\n";
	return 0;
}