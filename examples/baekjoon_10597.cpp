#include <iostream>
#include <vector>
#include <string>

std::string s;
std::vector<int> v;
std::vector<bool> visited;
int s_length, v_size;
bool finished = false;

void Print(){
	for(auto &iter : v){
		std::cout << iter << " ";
	}
}

void backtracking(int curr){
	if(finished) return;
	if(curr == s_length){
		Print();
		finished = true;
		return;
	}
	for(int i = 1; i <= 2; ++i){
		if(curr > s_length - i) continue;
		int n = stoi(s.substr(curr, i));
		if(n == 0 or n > v_size) continue;
		// std::cout << n << std::endl;
		if(not visited[n]){
			v.push_back(n);
			visited[n] = true;
			backtracking(curr + i);
			visited[n] = false;
			v.pop_back();
		}	
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> s;
	s_length = s.size();
	if (s_length < 10) visited.resize(s_length + 1, false);
	else visited.resize((s_length + 9)/2 + 1, false); 
	v_size = visited.size() - 1;
	backtracking(0);

	return 0;
}