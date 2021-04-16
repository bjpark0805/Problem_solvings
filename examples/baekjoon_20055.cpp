// 40분 정도 소요
// 시뮬레이션
// 디버깅 일부 에러로 시간초과, 시뮬레이션의 경우 문제를 항상 잘읽어라


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void conveyer_belt(){
	int N, K;
	cin >> N >> K;
	vector<int> belt(2 * N);
	vector<int> exist(2 * N, false);
	for(int i = 0; i < 2 * N; ++i){
		cin >> belt[i];
	}
	queue<int> q;
	int up = 0;
	int down = N - 1;
	int level = 0;
	while(true){
		level++;
		up = (up + 2 * N - 1) % (2 * N);
		down = (down + 2 * N - 1) % (2 * N);
		if(exist[down]){
			exist[down] = false;
			q.pop();
		}
		int qsize = q.size();
		for(int i = 0; i < qsize; ++i){
			int idx = q.front();
			int next_idx = (idx + 1) % (2 * N);
			q.pop();
			if(not exist[next_idx] and belt[next_idx] > 0){
				exist[idx] = false;
				exist[next_idx] = true;
				belt[next_idx]--;
				q.push(next_idx);
			}
			else q.push(idx);
			
		}
		if(exist[down]) {
			exist[down] = false;
			q.pop();
		}

		if(not exist[up] and belt[up] > 0){
			exist[up] = true;
			belt[up]--;
			q.push(up);
		}
		int cnt = 0;
		for(int i = 0; i < 2 * N; ++i){
			if(belt[i] == 0) cnt++;
		}
		if(cnt >= K) break;

	}
	cout << level << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	conveyer_belt();
	return 0;
}