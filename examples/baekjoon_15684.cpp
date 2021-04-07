/*
Combination problem:
만약 경우의 수를 모두 찾는 문제에서 시간이 오래 걸릴 경우, 
combination을 고려해서 아예 필요없는 것들은 고려하지 않는 방향으로 코드를 짜보자. 
함수를 call 할때 그전에 멈춘 index를 넣어서 그 다음부터 탐색하는 것으로 한다던지. 
조기 종료를 call한다던지. 

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, H, ans = 4;
vector<vector<int> > ladder;

void ladder_modification(int cnt, int i1, int h1){
	//check
	bool check = true;
	for(int i = 1; i < N; ++i){
		int line = i;
		for(int h = 1; h <= H; ++h){
			if(ladder[line][h] > 0) line = ladder[line][h];
		}
		if(line != i) {check = false; break;}
	}
	if(check) {ans = min(ans, cnt); return;}
	else if(cnt >= 3) return;

	// add ladder
	for(int i = i1; i < N; ++i){
		if (i != i1) h1 = 0;
		for(int h = h1 + 1; h <= H; ++h){
			if(ladder[i][h] == 0 && ladder[i + 1][h] == 0){
				ladder[i][h] = i + 1;
				ladder[i + 1][h] = i;
				ladder_modification(cnt + 1, i, h);
				ladder[i][h] = 0;
				ladder[i + 1][h] = 0;
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> H;
	ladder.resize(N + 1);
	for(int i = 0; i < N + 1; ++i){
		ladder[i].resize(H + 1, 0);
	}
	int a, b;
	for(int i = 0; i < M; ++i){
		cin >> a >> b;
		ladder[b][a] = b + 1;
		ladder[b + 1][a] = b;
	}
	ladder_modification(0, 1, 0);
	if(ans == 4) ans = -1;
	cout << ans << "\n";
	return 0;
}