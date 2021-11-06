#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<std::vector<int> > > dp;

long long stair_number(int top_num, int length, int state){
	if(length == 0 and state == (1<<10) - 1) return 1;
	else if(length == 0) return 0;
	if(dp[top_num][length][state] != -1) return dp[top_num][length][state];
	int &ret = dp[top_num][length][state];
	int answer = 0;
	for(int i = 0; i < 10; ++i){
		if(std::abs(i - top_num) == 1){
			answer += stair_number(i, length - 1, state | (1 << i));
			answer %= 1000000000;
		}
	}
	return ret = answer;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int N;
	std::cin >> N;
	dp.resize(10, std::vector<std::vector<int> >(N, std::vector<int>(1<<10, -1)));
	long long answer = 0;
	for(int i = 1; i <= 9; ++i){
		answer += stair_number(i, N - 1, 1 << i);
		answer %= 1000000000;
	}
	std::cout << answer << "\n";
	return 0;
}