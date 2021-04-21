#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int R, C, answer = 0;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

vector<string> board;
vector<vector<int> > visited;
map<char, bool> m;


void dfs(int r, int c, int cnt){
	answer = max(answer, cnt);
	for(int d = 0; d < 4; ++d){
		int nr = r + dr[d], nc = c + dc[d];
		if(nr < 0 or nr >= R or nc < 0 or nc >= C or visited[nr][nc] or m[board[nr][nc]]) continue;
		m[board[nr][nc]] = true;
		visited[nr][nc] = true;
		dfs(nr, nc, cnt + 1);
		m[board[nr][nc]] = false;
		visited[nr][nc] = false;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;
	board.resize(R);
	visited.resize(R);
	for(int i = 0; i < R; ++i){
		visited[i].resize(C, false);
		cin >> board[i];
	}
	char c = 'A';
	for(int i = 0; i < 26; ++i){
		m[c + i] = false;
	}

	
	m[board[0][0]] = 1;
	dfs(0, 0, 1);

	cout << answer << "\n";
	return 0;
}
