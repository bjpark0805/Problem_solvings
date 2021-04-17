// 1시간 소요
// 시뮬레이션
// 배열 로테이션 익히기
// 시간초과 날까봐 걱정했는데 다행히 안났음.
// 실제시험에서 로테이션 써도 될듯.

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int N, M, T;
int dd[2] = {-1, 1};
int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};
vector<vector<int> > circle;

pair<int, int> total_sum(){
	int answer = 0, cnt = 0;
	for(int i = 0; i < circle.size(); ++i){
		for(int j = 0; j < circle[i].size(); ++j){
			if(circle[i][j] != -1){
				answer += circle[i][j];
				cnt++;
			}
		}
	}
	return make_pair(answer, cnt);
}

void Print(){
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j){
			cout << circle[i][j] << " ";
		}
		cout << endl;
	}
	cout << "---------------------------\n";
}

bool bfs(int r, int c){
	int target = circle[r][c];
	circle[r][c] = -1;
	bool find_same = false;
	queue<pair<int, int> > q;
	q.push(make_pair(r, c));

	while(!q.empty()){
		int r1 = q.front().first, c1 = q.front().second;
		q.pop();
		for(int d = 0; d < 4; ++d){
			int nr = r1 + dr[d], nc = (c1 + dc[d] + M)%M;
			if(nr < 0 or nr >= N) continue;
			if(circle[nr][nc] == target){
				find_same = true;
				circle[nr][nc] = -1;
				q.push(make_pair(nr, nc));
			}
		}
	}
	if(not find_same) circle[r][c] = target;
	return find_same;
}

void rotate_circle(int x, int d, int k){
	for(int i = x - 1; i < N; i = i + x){
		rotate(circle[i].begin(), circle[i].begin() + (dd[d] * k + M)%M, circle[i].end());
	}
	// Print();
	bool erase = false;
	for(int r = 0; r < N; ++r){
		for(int c = 0; c < M; ++c){
			if(circle[r][c] != -1){
				erase |= bfs(r, c);
			}
		}
	}
	if(erase) return;
	pair<int, int> ts = total_sum();
	double tmp = (double)ts.first / ts.second;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j){
			if(circle[i][j] == -1) continue;
			if(circle[i][j] > tmp) circle[i][j]--;
			else if(circle[i][j] < tmp) circle[i][j]++;
		}
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> T;
	circle.resize(N);
	
	for(int i = 0; i < N; ++i){
		circle[i].resize(M);
		for(int j = 0; j < M; ++j){
			cin >> circle[i][j];
		}
	}
	int x, d, k;
	for(int i = 0; i < T; ++i){
		cin >> x >> d >> k;
		rotate_circle(x, d, k);
	}

	cout << total_sum().first << "\n";
	return 0;
}