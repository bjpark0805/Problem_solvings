#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, x, y, K;
	cin >> N >> M >> x >> y >> K;
	vector<vector<int> > Map(N, vector<int>(M, 0));
	vector<int> dice(7, 0);
	for(int r = 0; r < N; ++r){
		for(int c = 0; c < M; ++c){
			cin >> Map[r][c];
		}
	}
	/*
			up	
	6-right top right
			6 - up
			6 - top 
	*/
	int top = 1, right = 3, up = 2, d;	
	for(int i = 0; i < K; ++i){
		cin >> d;
		if(d == 1){
			if(y + 1 >= M) continue;
			y += 1;
			int tmp = top;
			top = 7 - right; right = tmp; 
		}
		else if(d == 2){
			if(y - 1 < 0) continue;
			y -= 1;
			int tmp = top;
			top = right; right = 7 - tmp; 
		}
		else if(d == 3){
			if(x - 1 < 0) continue;
			x -= 1;
			int tmp = top;
			top = 7 - up; up = tmp;
		}
		else{// d == 4
			if(x + 1 >= N) continue;
			x += 1;
			int tmp = top;
			top = up; up = 7 - tmp;
		}
		if(Map[x][y] == 0) Map[x][y] = dice[7 - top];
		else{
			dice[7 - top] = Map[x][y];
			Map[x][y] = 0;
		}
		cout << dice[top] << "\n";
	}

	return 0;
}