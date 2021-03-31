#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N;
vector<bool> person;
vector<vector<int> > ability;

int startlink(int n, int cnt_t, int cnt_f, int sum_t, int sum_f){
	if(n == N) return abs(sum_t - sum_f);
	
	int ans = INT_MAX, tmp = 0;
	if(cnt_t < N/2){
		person[n] = true;
		for(int i = 0; i < n; ++i){
			if(person[i]) tmp += ability[i][n] + ability[n][i];
		}
		ans = min(ans, startlink(n + 1, cnt_t + 1, cnt_f, sum_t + tmp, sum_f));
		person[n] = false;
		tmp = 0;
	} 
	if(cnt_f < N/2){
		for(int i = 0; i < n; ++i){
			if(not person[i]) tmp += ability[i][n] + ability[n][i];
		}
		ans = min(ans, startlink(n + 1, cnt_t, cnt_f + 1, sum_t, sum_f + tmp));
	}
	
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	person.resize(N, false);
	ability.resize(N);
	
	for(int i = 0; i < N; ++i){
		ability[i].resize(N);
		for(int j = 0; j < N; ++j){
			cin >> ability[i][j];
		}
	}

	cout << startlink(0, 0, 0, 0, 0) << "\n";
	return 0;
}