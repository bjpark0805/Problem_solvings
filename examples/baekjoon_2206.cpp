#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

int dr[4] = {0,0,-1,1};
int dc[4] = {-1,1,0,0};
int N, M;
std::vector<std::vector<std::vector<bool> > > Map_;

struct coords{
	int r, c, f;
	coords(int r_, int c_, int f_){
		r = r_;
		c = c_;
		f = f_;
	} 
};

int bfs(){
	if(N == 1 and M == 1) return 1;
	std::vector<std::vector<std::vector<bool> > > visited;
	visited.resize(2);
	visited[0].resize(N);
	visited[1].resize(N);
	for(int i = 0; i < N; ++i){
		visited[0][i].resize(M, false);
		visited[1][i].resize(M, false);
	}
	std::queue<coords> q;
	visited[0][0][0] = true;
	visited[1][0][0] = true;
	coords c(0, 0, 0);
	q.push(c);
	int level = 2;
	while(!q.empty()){
		int qsize = q.size();
		for(int i = 0; i < qsize; ++i){
			coords c_tmp = q.front();
			q.pop();
			for(int d = 0; d < 4; ++d){
				int nr = c_tmp.r + dr[d];
				int nc = c_tmp.c + dc[d];
				int floor = c_tmp.f;
				if(nr < 0 or nr >= N or nc < 0 or nc >= M) continue;
				if(nr == N - 1 and nc == M - 1) return level;
				if(not visited[floor][nr][nc] and not Map_[floor][nr][nc]){
					coords c_next(nr, nc, floor);
					q.push(c_next);
					visited[floor][nr][nc] = true;
					if(floor == 0) visited[1][nr][nc] = true;
				} 
				else if(Map_[floor][nr][nc] and floor == 0 and not visited[1][nr][nc]){
					coords c_next(nr, nc, 1);
					q.push(c_next);
					visited[1][nr][nc] = true;
				}
			}
		}			
		level++;
	}
	return -1;
}

int main(){
	scanf("%d%d", &N, &M);
	Map_.resize(2);
	Map_[0].resize(N);
	Map_[1].resize(N);
	for(int i = 0; i < N; ++i){
		Map_[0][i].resize(M, false);
		Map_[1][i].resize(M, false);
	}
	int t;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j){
			scanf("%1d",&t);
			Map_[0][i][j] = t;
			Map_[1][i][j] = t;
		}
	}
	printf("%d\n", bfs());
	return 0;
}