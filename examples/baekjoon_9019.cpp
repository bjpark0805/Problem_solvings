#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>
#include <algorithm>

int D(int p){
	return (p * 2)%10000;
}
int S(int p){
	return (p + 9999)%10000;
}
int L(int p){
	std::string s = "0000";
	std::string ps = std::to_string(p);
	for(int i = 0; i < ps.size(); ++i){
		s[(s.size() - ps.size() + 3 + i)%4] = ps[i];
	}
	return stoi(s);
}
int R(int p){
	std::string s = "0000";
	std::string ps = std::to_string(p);
	for(int i = 0; i < ps.size(); ++i){
		s[(s.size() - ps.size() + 1 + i)%4] = ps[i];
	}
	return stoi(s);
}

std::string bfs(int start, int target){
	std::vector<bool> visited(10000, false);
	std::vector<std::pair<int, char> > prev(10000, std::make_pair(-1, '.'));
	std::queue<int> q;
	q.push(start);
	visited[start] = true;
	while(!q.empty()){
		int qfront = q.front();
		q.pop();
		int next_num[4] = {D(qfront), S(qfront), L(qfront), R(qfront)};
		char cmd[4] = {'D','S','L','R'};
		for(int i = 0; i < 4; ++i){
			int curr = next_num[i];
			if(visited[curr]) continue;
			visited[curr] = true;
			prev[curr] = std::make_pair(qfront, cmd[i]);
			if(curr == target) {
				std::vector<char> ans;
				while(curr != start){
					ans.push_back(prev[curr].second);
					curr = prev[curr].first;
				}
				std::string s(ans.begin(), ans.end());
				std::reverse(s.begin(), s.end());
				return s;
			}
			q.push(curr);
		}
	}
	return "";
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int T, start, target;
	std::cin >> T;
	for(int i = 0; i < T; ++i){
		std::cin >> start >> target;
		std::cout << bfs(start, target) << "\n";
	}
	return 0;
}