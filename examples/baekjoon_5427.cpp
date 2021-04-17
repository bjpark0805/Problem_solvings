#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>

using namespace std;
int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

void bfs(){
	int w, h;
	cin >> w >> h;
	vector<string> building(h);
	vector<vector<bool> > visited(h, vector<bool>(w, false));
	queue<pair<int, int> > q_sang, q_fire;
	for(int i = 0; i < h; ++i){
		cin >> building[i];
		for(int j = 0; j < w; ++j){
			if(building[i][j] == '@'){
				q_sang.push(make_pair(i, j));
				visited[i][j] = true;
			}
			if(building[i][j] == '*') q_fire.push(make_pair(i, j));
		}
	}
	int level = 1;
	while(!q_sang.empty()){
		int qsize_s = q_sang.size();
		int qsize_f = q_fire.size();
		for(int i = 0; i < qsize_s; ++i){
			int r = q_sang.front().first;
			int c = q_sang.front().second;
			q_sang.pop();
			if(building[r][c] == '*') continue;
			for(int d = 0; d < 4; ++d){
				int nr = r + dr[d], nc = c + dc[d];
				if(nr < 0 or nr >= h or nc < 0 or nc >= w){
					cout << level << "\n";
					return;
				}
				if(building[nr][nc] == '#' or building[nr][nc] == '*' or visited[nr][nc])
					continue;
				visited[nr][nc] = true;
				q_sang.push(make_pair(nr, nc));
			}
		}
		for(int i = 0; i < qsize_f; ++i){
			int r = q_fire.front().first;
			int c = q_fire.front().second;
			q_fire.pop();
			for(int d = 0; d < 4; ++d){
				int nr = r + dr[d], nc = c + dc[d];
				if(nr < 0 or nr >= h or nc < 0 or nc >= w 
					or building[nr][nc] == '*' 
					or building[nr][nc] == '#') continue;
				building[nr][nc] = '*';
				q_fire.push(make_pair(nr, nc));
			}
		}
		level++;
	}
	cout << "IMPOSSIBLE\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for(int i = 0; i < T; ++i){
		bfs();
	}
	return 0;
}