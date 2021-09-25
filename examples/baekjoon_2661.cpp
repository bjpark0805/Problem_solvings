#include <iostream>
#include <vector>
#include <string>
#include <climits>

int N;
std::string s = "1";
bool finished = false;

bool is_good_sequence(){
	int s_len = s.size();
	bool ans = true;
	for(int i = 1; i <= s_len/2; ++i){
		if(s.substr(s_len - 2*i, i) == s.substr(s_len - i, i)){
			ans = false;
			break;
		}
	}
	return ans;
}

void backtracking(int curr, int prev){
	if(finished) return;
	if(curr == N){
		finished = true;
		std::cout << s << std::endl;
		return;
	}
	for(int i = 1; i <= 3; ++i){
		if(i == prev) continue;
		s.push_back('0' + i);
		if(is_good_sequence()) backtracking(curr + 1, i);
		s.pop_back();
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	backtracking(1, 1);
	return 0;
}