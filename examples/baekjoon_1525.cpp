#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>

struct puzzle{
	int curr;
	std::string arr;
	puzzle(int c, std::string s){
		curr = c;
		arr = s;
	}
	puzzle(){
		curr = 0;
		arr = "012345678";
	}
};

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

puzzle p;

bool check_arr(std::string& arr){
	bool ans = true;
	for(int i = 0; i < 8; ++i){
		if(arr[i] != '1' + i) ans = false;
	}
	return ans;
}

int bfs(){
	if (check_arr(p.arr)) return 0;
	std::map<std::string, int> visited;
	int level = 1;
	std::queue<puzzle> q;
	q.push(p);
	visited[p.arr] = 1;
	while(!q.empty()){
		int qsize = q.size();
		for(int i = 0; i < qsize; ++i){
			puzzle t(q.front());
			q.pop();
			int r = t.curr / 3, c = t.curr % 3;
			for(int d = 0; d < 4; ++d){
				int nr = r + dr[d], nc = c + dc[d];
				if(nr < 0 or nr >= 3 or nc < 0 or nc >= 3) continue;
				std::string temp_arr = t.arr;
				temp_arr[t.curr] = temp_arr[nr*3 + nc];
				temp_arr[nr*3 + nc] = '0';
				// std::cout<<temp_arr << std::endl;
				if(check_arr(temp_arr)) return level;
				if(visited.find(temp_arr) != visited.end()) continue;
				puzzle nxt(nr*3+nc, temp_arr);
				q.push(nxt);
				visited[temp_arr] = 1;
				// std::cout << nr << " " << nc << std::endl;
			}
		}
		level++;
	}
	return -1;
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	for(int i = 0; i < 9; ++i){
		std::cin >> p.arr[i];
		if(p.arr[i] == '0') p.curr = i;
	}
	std::cout << bfs() << std::endl;
	return 0;
}