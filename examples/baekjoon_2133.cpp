#include <iostream>
#include <vector>

std::vector<std::vector<int> > dp;
int N;
int tile3(int shape, int idx){
	if(shape == 0 and idx == N) return 1;
	else if(idx >= N) return 0;

	if(dp[shape][idx] != -1) return dp[shape][idx];
	int& ret = dp[shape][idx];
	int answer = 0;
	if(shape == 0){
		answer = 2 * tile3(2, idx);
		if(idx <= N - 2) answer += tile3(0, idx + 2);
	}
	else if(shape == 1){
		answer = tile3(0, idx + 1) + tile3(2, idx + 1);
	}
	else{ // shape == 2
		answer = tile3(1, idx + 1);
	}
	return ret = answer;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin.tie(NULL);
	std::cin >> N;
	dp.resize(3, std::vector<int>(N, -1));
	std::cout << tile3(0, 0) << "\n";
	return 0;
}
