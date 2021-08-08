#include <iostream>
#include <queue>
#include <vector>
#include <string>

int level = 0;

void bfs(){
	int N, T, G;
	std::cin >> N >> T >> G;
	std::vector<bool> visited(100000, false);
	visited[N] = true;
	std::queue<int> q;
	q.push(N);
	while(!q.empty()){
		if(level > T){
			level = -1;
			return;
		}
		int qsize = q.size();
		for(int i = 0; i < qsize; ++i){
			int x = q.front();
			q.pop();
			if(x == G) return;
			if(x + 1 <= 99999 and not visited[x + 1]){
				visited[x + 1] = true;
				q.push(x + 1);
			}
			if(x != 0 and x * 2 <= 99999){
				std::string tmp = std::to_string(2 * x);
				tmp[0] -= 1;
				int x_b = std::stoi(tmp);
				if(not visited[x_b]){
					visited[x_b] = true;
					q.push(x_b);	
				}
			}
		}
		level++;
	}
	level = -1;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	// std::string test_s = "0";
	// test_s[0] -= 1;
	// std::cout << "test: " << std::stoi(test_s) << std::endl;
	bfs();
	if(level >= 0) std::cout << level << std::endl;
	else std::cout << "ANG" << std::endl;

	return 0;
}