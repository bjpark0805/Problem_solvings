#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > lab;

int N, M;
vector<int> x_2, y_2;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void calculate_zeros(vector<vector<int> > &lab, int r, int c){
	for(int i = 0; i < 4; ++i){
		if(r + dx[i] < 0 || r + dx[i] >= N || c + dy[i] < 0 || c + dy[i] >= M) continue;
		else if(lab[r + dx[i]][c + dy[i]] == 0){
			lab[r + dx[i]][c + dy[i]] = 2;
			calculate_zeros(lab, r + dx[i], c + dy[i]);
		}
	}
}

int safety_zone(int cnt){
	if(cnt == 3){
		vector<vector<int> > lab_tmp(lab);
		for(int i = 0; i < x_2.size(); ++i){
			calculate_zeros(lab_tmp, x_2[i], y_2[i]);
		}
		int n = 0;
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < M; ++j){
				if(lab_tmp[i][j] == 0) n += 1;
			}
		}
		return n;
	} 
	int ans = 0;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j){
			if(lab[i][j] == 0){
				lab[i][j] = 1;
				ans = max(ans, safety_zone(cnt + 1));
				lab[i][j] = 0;
			}
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	lab.resize(N);
	x_2.resize(0); y_2.resize(0);
	for(int i = 0; i < N; ++i){
		lab[i].resize(M);
		for(int j = 0; j < M; ++j){
			cin >> lab[i][j];
			if(lab[i][j] == 2){
				x_2.push_back(i);
				y_2.push_back(j);
			}
		}
	}

	cout << safety_zone(0) << "\n";
	return 0;
}