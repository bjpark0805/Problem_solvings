// 50분 컷
// 시뮬레이션, dfs
// 딱히 어렵진 않았고, 디버깅도 없었음.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N, Q;
int total_len;
int dr[4] = {0, 0, -1 ,1};
int dc[4] = {-1, 1, 0, 0};
vector<vector<int> > A;
vector<vector<bool> > visited;

void rotate(int L){
	int len = pow(2, L);
	for(int i = 0; i < total_len/len; ++i){
		for(int j = 0; j < total_len/len; ++j){
			vector<vector<int> > temp(len, vector<int>(len));
			for(int r = 0; r < len; ++r){
				for(int c = 0; c < len; ++c){
					temp[c][len-1-r] = A[i * len + r][j * len + c];
				}
			}
			for(int r = 0; r < len; ++r){
				for(int c = 0; c < len; ++c){
					A[i * len + r][j * len + c] = temp[r][c];
				}
			}
		}
	}
}

void melt_ice(){
	vector<vector<int> > temp(total_len, vector<int>(total_len, 0));
	for(int i = 0; i < total_len; ++i){
		for(int j = 0; j < total_len; ++j){
			if(A[i][j] == 0) continue;
			int cnt = 0;
			for(int d = 0; d < 4; ++d){
				int nr = i + dr[d], nc = j + dc[d];
				if(nr >= 0 and nr < total_len and nc >= 0 and nc < total_len and A[nr][nc] > 0) cnt++;
			}
			if(cnt <= 2) temp[i][j] = -1;
		}
	}

	for(int i = 0; i < total_len; ++i){
		for(int j = 0; j < total_len; ++j){
			A[i][j] += temp[i][j];
		}
	}
}

void firestorm(int L){
	rotate(L);
	melt_ice();
}

int dfs(int r, int c){
	visited[r][c] = true;
	int cnt = 1;
	for(int d = 0; d < 4; ++d){
		int nr = r + dr[d], nc = c + dc[d];
		if(nr < 0 or nr >= total_len or nc < 0 or nc >= total_len or A[nr][nc] == 0) continue;
		if(not visited[nr][nc]) cnt += dfs(nr, nc);
	}
	return cnt;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> Q;
	total_len = pow(2, N);
	A.resize(total_len);
	visited.resize(total_len);
	for(int i = 0; i < total_len; ++i){
		A[i].resize(total_len);
		visited[i].resize(total_len,false);
		for(int j = 0; j < total_len; ++j){
			cin >> A[i][j];
		}
	}

	int L;
	for(int i = 0; i < Q; ++i){
		cin >> L;
		firestorm(L);
	}
	int left_ice = 0, biggest_ice = 0;
	for(int i = 0; i < total_len; ++i){
		for(int j = 0; j < total_len; ++j){
			if(A[i][j] == 0) continue;
			left_ice += A[i][j];
			if(not visited[i][j]) biggest_ice = max(biggest_ice, dfs(i, j));
		}
	}
	if(biggest_ice == 1) biggest_ice = -1;

	cout << left_ice << "\n" << biggest_ice << "\n";
	return 0;
}