// 24분 소요
// bfs 문제
// 반드시 visited를 걸어줄것. 예외의 경우는 거의 없다.

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
int dr[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dc[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
void bfs(int l, int r1, int c1, int r2, int c2){
	if(r1 == r2 and c1 == c2){
		cout << 0 << "\n";
		return;
	}
	vector<vector<bool> > visited(l, vector<bool>(l, false));
	queue<pair<int, int> > q;
	q.push(make_pair(r1, c1));
	visited[r1][c1] = true;
	int level = 1;
	while(!q.empty()){
		int qsize = q.size();
		for(int i = 0; i < qsize; ++i){
			int r = q.front().first, c = q.front().second;
			q.pop();
			for(int d = 0; d < 8; ++d){
				int nr = r + dr[d], nc = c + dc[d];
				if(nr == r2 and nc == c2){
					cout << level << "\n";
					return;
				}
				if(nr >= 0 and nr < l and nc >= 0 and nc < l and not visited[nr][nc]){
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
	int T, l, r1, c1, r2, c2;
	cin >> T;
	for(int i = 0; i < T; ++i){
		cin >> l >> r1 >> c1 >> r2 >> c2;
		bfs(l, r1, c1, r2, c2);
	}
	return 0;
}