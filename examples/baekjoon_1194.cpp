#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
std::vector<std::string> maze;
int N, M;
int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

struct state{
	int r, c, key;
	state(int key_, int r_, int c_) : r(r_), c(c_), key(key_){};
};

int bfs(int i, int j){
	std::vector<std::vector<std::vector<int> > > visited(1<<6, std::vector<std::vector<int> > (N, std::vector<int>(M, false)));
	std::queue<state> q;
	state s(0, i, j);
	q.push(s);
	visited[0][i][j] = true;
	int level = 1;
	while(not q.empty()){
		int qsize = q.size();
		for(int i = 0; i < qsize; ++i){
			state front = q.front();
			q.pop();
			for(int d = 0; d < 4; ++d){
				int nr = front.r + dr[d], nc = front.c + dc[d], nk = front.key;
				if(nr < 0 or nr >= N or nc < 0 or nc >= M or visited[nk][nr][nc] or maze[nr][nc] == '#') continue;
				if(maze[nr][nc] >= 'A' and maze[nr][nc] <= 'F' and ((nk & (1 << (maze[nr][nc] - 'A'))) == 0)) continue;
				if(maze[nr][nc] == '1') return level;
				if(maze[nr][nc] >= 'a' and maze[nr][nc] <= 'f' and ((nk & (1 << (maze[nr][nc] - 'a'))) == 0)){
					nk = front.key | (1 << (maze[nr][nc] - 'a'));
				}
				state new_state(nk, nr, nc);
				visited[nk][nr][nc] = true;
				q.push(new_state);
			}
		}
		level++;
	}
	return -1;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;
	int r = -1, c = -1;
	maze.resize(N);
	for(int i = 0; i < N; ++i){
		std::cin >> maze[i];
		for(int j = 0; j < M; ++j){
			if(maze[i][j] == '0'){
				r = i;
				c = j;
			}
		}
	}
	std::cout << bfs(r, c) << "\n";
	return 0;
}