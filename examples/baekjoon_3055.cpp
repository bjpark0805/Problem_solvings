#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>

using namespace std;

void bfs(){
	int dr[4] = {0, 0, -1, 1};
	int dc[4] = {1, -1, 0, 0};
	int R, C;
	cin >> R >> C;
	vector<string> forest(R);
	vector<vector<bool> > visited(R, vector<bool>(C, false));
	queue<pair<int, int> > q_animal, q_water;
	for(int i = 0; i < R; ++i){
		cin >> forest[i];
		for(int j = 0; j < C; ++j){
			if(forest[i][j] == '*') q_water.push(make_pair(i, j));
			if(forest[i][j] == 'S'){
				visited[i][j] = true;
				q_animal.push(make_pair(i, j));
			}
		}
	}
	int level = 1;
	while(!q_animal.empty()){
		int qsize_a = q_animal.size();
		int qsize_w = q_water.size();
		for(int i = 0; i < qsize_a; ++i){
			int r = q_animal.front().first;
			int c = q_animal.front().second;
			q_animal.pop();
			if(forest[r][c] == '*') continue;
			for(int d = 0; d < 4; ++d){
				int nr = r + dr[d], nc = c + dc[d];
				if(nr < 0 or nr >= R or nc < 0 or nc >= C 
					or forest[nr][nc] == '*' 
					or forest[nr][nc] == 'X'
					or visited[nr][nc]) continue;
				if(forest[nr][nc] == 'D') {
					cout << level << "\n";
					return;
				}
				visited[nr][nc] = true;
				q_animal.push(make_pair(nr, nc));
			}
		}
		for(int i = 0; i < qsize_w; ++i){
			int r = q_water.front().first;
			int c = q_water.front().second;
			q_water.pop();
			for(int d = 0; d < 4; ++d){
				int nr = r + dr[d], nc = c + dc[d];
				if(nr < 0 or nr >= R or nc < 0 or nc >= C 
					or forest[nr][nc] == '*' 
					or forest[nr][nc] == 'X'
					or forest[nr][nc] == 'D') continue;
				q_water.push(make_pair(nr, nc));
				forest[nr][nc] = '*';
			}
		}
		level++;
	}
	cout << "KAKTUS\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bfs();
	return 0;
}