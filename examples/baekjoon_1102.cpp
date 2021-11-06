#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::vector<int> > cost;
std::vector<std::vector<int> > dp;
int N, P;

int get_minimum(int activated, int state){
	if(activated >= P) return 0;
	if(dp[activated][state] != -1) return dp[activated][state];
	int& ret = dp[activated][state];
	int ans = 36 * 16;
	for(int j = 0; j < N; ++j){
		int plant = (1 << j);
		if((plant & state) == 0){
			int min_cost = 37;
			for(int i = 0; i < N; ++i){
				if((state & (1 << i)) != 0){
					min_cost = std::min(min_cost, cost[i][j]);
				}
			}
			if(min_cost != 37) ans = std::min(ans, get_minimum(activated + 1, state | plant) + min_cost);
		}
	}
	return ret = ans;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::cin >> N;
	cost.resize(N, std::vector<int>(N, 0));
	dp.resize(N, std::vector<int>((1<<N)-1, -1));
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			std::cin >> cost[i][j];
		}
	}
	std::string S;
	std::cin >> S;
	int power_plant = 0, cnt = 0;
	for(int i = 0; i < N; ++i){
		if(S[i] == 'Y'){
			power_plant |= (1 << i);
			cnt++;
		}
	}
	std::cin >> P;
	int answer = get_minimum(cnt, power_plant);
	if(answer >= 16 * 36) answer = -1;
	std::cout << answer << "\n";
	return 0;
}