#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <bitset>

std::vector<std::vector<int> > bridges;
std::vector<int> islands;
int n, K; // # of islands, # of jewels

int cnt_num_of_jewels(int jewels){
	int cnt = 0;
	for(int i = 0; i < K; ++i){
		if((jewels & (1 << i)) != 0) cnt++;
	}
	return cnt;
}

int bfs(){
	int max_val = 0;
	std::vector<std::vector<bool> > visited(1 << K, std::vector<bool>(n, false));
	std::queue<std::pair<int, int> > q; // jewel, curr_island
	q.push(std::make_pair(0, 0));
	visited[0][0] = true;
	while(not q.empty()){
		std::pair<int, int> front = q.front();
		q.pop();
		int curr_jewels = front.first, curr_island = front.second;
		int num_of_jewels = cnt_num_of_jewels(curr_jewels);
		if(not visited[curr_jewels][0] and bridges[curr_island][0] >= num_of_jewels){
			visited[curr_jewels][0] = true;
			max_val = std::max(max_val, num_of_jewels);
		}
		for(int next_island = 1; next_island < n; ++next_island){
			if(bridges[curr_island][next_island] < num_of_jewels or visited[curr_jewels][next_island]) continue;
			if(islands[next_island] != -1 and ((1 << islands[next_island]) & curr_jewels) == 0){
				int next_jewels = (1 << islands[next_island]) | curr_jewels;
				if(not visited[next_jewels][next_island]){
					q.push(std::make_pair(next_jewels, next_island));
					visited[next_jewels][next_island] = true;
				}

			}
			q.push(std::make_pair(curr_jewels, next_island));
			visited[curr_jewels][next_island] = true;
		}
	}
	if(islands[0] != -1) max_val++;
	return max_val;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int m, a, b, c;
	std::cin >> n >> m >> K;

	islands.resize(n, -1);
	for(int i = 0; i < K; ++i){
		std::cin >> a;
		islands[a-1] = i;
	}

	bridges.resize(n, std::vector<int>(n, -1));
	for(int i = 0; i < m; ++i){
		std::cin >> a >> b >> c;
		bridges[a - 1][b - 1] = c;
		bridges[b - 1][a - 1] = c;
	}
	std::cout << bfs() << "\n";
	return 0;
}