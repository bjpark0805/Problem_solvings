// 1시간 26분
// bfs, 최단 경로 문제
// 문제 조건에 완벽하게 부합하게 bfs를 짜지 않아서 디버깅이 좀 오래걸림

#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

void bfs(){
	int N, r, c, time = 0;
	int dr[4] = {-1, 0, 0, 1};
	int dc[4] = {0, -1, 1, 0};
	cin >> N;
	vector<vector<int> > space(N, vector<int>(N, 0));
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cin >> space[i][j];
			if(space[i][j] == 9){
				space[i][j] = 0;
				r = i;
				c = j;
			}  
		}
	}

	int size = 2, eat = 0;
	
	while(true){
		vector<vector<bool> > visited(N, vector<bool>(N, false));
		queue<pair<int, int> > q;
		q.push(make_pair(r, c));
		visited[r][c] = true;
		vector<pair<int, int> > stop;
		int level = 1;
		// cout << "start: " << r << " " << c << " " << "size: " << size << endl;
		// for(int i = 0; i < N; ++i){
		// 	for(int j = 0; j < N; ++j){
		// 		cout << space[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		while(!q.empty()){
			int qsize = q.size();
			for(int i = 0; i < qsize; ++i){
				int r1 = q.front().first, c1 = q.front().second;
				q.pop();
				for(int d = 0; d < 4; ++d){
					int nr = r1 + dr[d], nc = c1 + dc[d];
					if(nr >= 0 and nr < N and nc >= 0 and nc < N and not visited[nr][nc]){
						if(space[nr][nc] > size) continue;
						else if(space[nr][nc] == size or space[nr][nc] == 0) {
							// cout << nr << " " << nc << endl;
							q.push(make_pair(nr, nc));
							visited[nr][nc] = true;
						}
						else{
							stop.push_back(make_pair(nr, nc));
						}
					}
				}
			}
			if(stop.size() == 0){
				level++;
				continue;
			}
			r = stop[0].first;
			c = stop[0].second;
			for(int i = 0; i < stop.size(); ++i){
				if(stop[i].first < r or (stop[i].first == r and stop[i].second < c)){
					r = stop[i].first;
					c = stop[i].second;
				}
			}

			eat += 1;
			if(size == eat){
				size++;
				eat = 0;
			}
			space[r][c] = 0;
			break;
		}
		if(stop.size() == 0) break; // 못먹은 경우, 자연스럽게 위의 와일문이 깨진 경우
		// cout << "eat " << r << " " << c << endl;
		// cout << level << "\n" << "---------" << endl;
		time += level; // 물고기 먹은 경우
	}
	cout << time << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bfs();
	return 0;
}