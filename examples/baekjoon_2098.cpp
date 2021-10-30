#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define IMPOSSIBLE 1000000000

std::vector<std::vector<int> > dp;
std::vector<std::vector<int> > weights;
int N;

int tsp(int curr, int status){
	int& ret = dp[curr][status];
	if(ret != -1) return ret;
	if(status == (1 << N) - 1){
		if(weights[curr][0] != 0) return ret = weights[curr][0];
		return ret = IMPOSSIBLE;
	}
	int ans = IMPOSSIBLE;
	for(int i = 1; i < N; ++i){
		if(status & (1 << i) or weights[curr][i] == 0) continue;
		int next_status = status | (1 << i);
		ans = std::min(ans, tsp(i, next_status) + weights[curr][i]);
	}
	return ret = ans;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::cin >> N;
	dp.resize(N, std::vector<int>(1<<N, -1));
	weights.resize(N, std::vector<int>(N, 0));

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			std::cin >> weights[i][j];
		}
	}

	std::cout << tsp(0, 1) << "\n";
	return 0;
}