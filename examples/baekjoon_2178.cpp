#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

void bfs(){
	int N, M;
	cin >> N >> M;
	vector<string> maze(N);
	vector<vector<bool> > visited(N, vector<bool>(M, false));
	for(int i = 0; i < N; ++i){
		cin >> maze[i];
	}
	int dr[4] = {0,-1,0,1};
	int dc[4] = {-1,0,1,0};

	int level = 2;
	queue<pair<int, int> > q;
	q.push(make_pair(0, 0));
	visited[0][0] = true;
	while(!q.empty()){
		int qsize = q.size();
		for(int i = 0; i < qsize; ++i){
			pair<int, int> block = q.front();
			q.pop();
			for(int d = 0; d < 4; ++d){
				int nr = block.first + dr[d];
				int nc = block.second + dc[d];
				if(nr >= 0 and nr < N and nc >= 0 and nc < M and not visited[nr][nc] and maze[nr][nc] == '1'){
					if(nr == N - 1 and nc == M - 1){
						cout << level << "\n";
						return;
					}
					visited[nr][nc] = true;
					q.push(make_pair(nr, nc));
				}
			}
		}
		level++;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bfs();
	return 0;
}