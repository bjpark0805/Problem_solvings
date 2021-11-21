#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

int N, K, l;

int bfs(){
	std::queue<int> q;
	q.push(N);
	int level = 1;
	while(!q.empty()){
		int qsize = q.size();
		int ans = -1;
		std::vector<bool> visited(1000001, false);
		for(int d = 0; d < qsize; ++d){
			int f = q.front();
			q.pop();
			for(int i = 0; i < l; ++i){
				for(int j = i + 1; j < l; ++j){
					std::string s = std::to_string(f);
					char tmp = s[i];
					s[i] = s[j];
					s[j] = tmp;
					if(s[0] == '0' or visited[std::stoi(s)]) continue;
					visited[std::stoi(s)] = true;
					q.push(stoi(s));
					ans = std::max(ans, stoi(s));
				}
			}
		}
		if(level == K) return ans;
		level++;
	}
	return -1;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> K;
	l = std::to_string(N).size();
	std::cout << bfs() << std::endl;

	return 0;
}