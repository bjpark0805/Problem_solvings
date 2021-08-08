#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int level = 0;
void bfs(){
	int N, K;
	std::vector<bool> visited(100001, false);
	std::cin >> N >> K;
	std::queue<int> q;
	q.push(N);
	visited[N] = true;
	while(!q.empty()){
		int qsize = q.size();
		for(int i = 0; i < qsize; ++i){
			int x = q.front();
			q.pop();
			if(x == K) return;
			if(x - 1 >= 0 and not visited[x-1]) {
				q.push(x-1);
				visited[x-1] = true;
			}
			if(x + 1 <= 100000 and not visited[x+1]) {
				q.push(x+1);
				visited[x+1] = true;
			}
			if(x * 2 <= 100000 and not visited[2 * x]) {
				q.push(2 * x);
				visited[x * 2] = true;
			}
		}
		level++;
	}
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	bfs();
	std::cout << level << "\n";

	return 0;
}