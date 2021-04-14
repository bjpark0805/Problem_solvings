// 55분 정도 소요
// 시뮬레이션
// 단순 시뮬레이션이라 싦수만 안하면 됐음. 다행히 실수하나 한게 디버깅이 테케 안에서 끝나서 빠르게 마무리함

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int R, C;
vector<vector<int> > room;
pair<int, int> up, down;
int up_r[4] = {0, -1, 0, 1}, up_c[4] = {1, 0, -1, 0};
int down_r[4] = {0, 1, 0, -1}, down_c[4] = {1, 0, -1, 0};

void spread(){
	vector<vector<int> > dust(R, vector<int>(C, 0));
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			if(room[i][j] == -1) continue;
			int sp = room[i][j]/5;
			for(int d = 0; d < 4; ++d){
				int nr = i + up_r[d], nc = j + up_c[d];
				if(nr < 0 or nr >= R or nc < 0 or nc >= C or room[nr][nc] == -1) continue;
				dust[nr][nc] += sp;
				dust[i][j] -= sp;
			}
		}
	}

	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			room[i][j] += dust[i][j];
		}
	}
}

void conditioner(){
	// up conditioner
	int r = up.first + up_r[0], c = up.second + up_c[0];
	int prev = 0;
	for(int d = 0; d < 4; ++d){
		for(int i = 0; i < max(R, C); ++i){
			int nr = r + up_r[d], nc = c + up_c[d];
			if(nr < 0 or nr >= R or nc < 0 or nc >= C) break;
			if(room[nr][nc] == -1) {
				room[r][c] = prev;
				break;
			}
			int temp = room[r][c];
			room[r][c] = prev;
			prev = temp;
			r = nr;
			c = nc;
		}
	}
	// down conditioner
	r = down.first + down_r[0];
	c = down.second + down_c[0];
	prev = 0;
	for(int d = 0; d < 4; ++d){
		for(int i = 0; i < max(R, C); ++i){
			int nr = r + down_r[d], nc = c + down_c[d];
			if(nr < 0 or nr >= R or nc < 0 or nc >= C) break;
			if(room[nr][nc] == -1) {
				room[r][c] = prev;
				break;
			}
			int temp = room[r][c];
			room[r][c] = prev;
			prev = temp;
			r = nr;
			c = nc;
		}
	}
}

void Print(){
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			cout << room[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> R >> C >> T;
	room.resize(R);
	bool first = true;
	for(int i = 0; i < R; ++i){
		room[i].resize(C);
		for(int j = 0; j < C; ++j){
			cin >> room[i][j];
			if(room[i][j] == -1 and first) {
				up = make_pair(i, j);
				first = false;
			}
			else if(room[i][j] == -1) down = make_pair(i, j);
		}
	}

	for(int i = 0; i < T; ++i){
		spread();
		// Print();
		conditioner();
		// Print();
	}
	int answer = 2;
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			answer += room[i][j];
		}
	}
	cout << answer << "\n";
	return 0;
}
