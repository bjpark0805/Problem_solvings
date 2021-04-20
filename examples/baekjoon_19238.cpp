// 2시간 이상 소요
// bfs, 시뮬레이션
// 처음 풀었을 때 난이도가 높다고 생각하진 않았는데 이상한데서 디버깅 걸려서 좆될뻔
// 확실히 컨디션 안좋으니까 실수가 나온다.

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int N, M, fuel, customers_left, start_r, start_c;
vector<vector<int> > city;
vector<vector<int> > customer;
vector<pair<int, int> > arrive;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

void Print(){
	cout << "--------------------------\n";
	cout << "fuel : " << fuel << endl;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cout << customer[i][j] << " ";
		}
		cout << endl;
	}
}
bool compare(pair<int, int> a, pair<int, int> b){
	if(a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}
void find_arrival(int r, int c, int customer_idx){
	int arrive_r = arrive[customer_idx].first, arrive_c = arrive[customer_idx].second;
	queue<pair<int, int> > q;
	vector<vector<bool> > visited(N, vector<bool>(N, false));
	q.push(make_pair(r, c));
	visited[r][c] = true;
	int level = 1;
	while(!q.empty()){
		int qsize = q.size();
		for(int i = 0; i < qsize; ++i){
			int r1 = q.front().first, c1 = q.front().second;
			q.pop();
			for(int d = 0; d < 4; ++d){
				int nr = r1 + dr[d], nc = c1 + dc[d];
				if(nr < 0 or nr >= N or nc < 0 or nc >= N) continue;
				if(nr == arrive_r and nc == arrive_c){
					fuel -= level;
					if(fuel < 0) return;
					fuel += level * 2;
					start_r = arrive_r;
					start_c = arrive_c;
					return;
				}
				if(city[nr][nc] == 0 and not visited[nr][nc]){
					q.push(make_pair(nr,nc));
					visited[nr][nc] = true;
				}
			}
		}
		level++;
	}
	fuel = -1;
}

void search_customer(){
	while(customers_left > 0){
		// Print();
		if(customer[start_r][start_c] > 0){
			int num = customer[start_r][start_c];
			customer[start_r][start_c] = 0;
			find_arrival(start_r, start_c, num);
			if(fuel < 0){
				return;
			}
			customers_left--;
			continue;
		}
		vector<vector<bool> > visited(N, vector<bool>(N, false));
		visited[start_r][start_c] = true;
		queue<pair<int, int> > q;
		q.push(make_pair(start_r, start_c));
		int level = 1;
		bool find = false;
		while(!q.empty()){
			int qsize = q.size();
			vector<pair<int, int> > temp;	
			for(int i = 0; i < qsize; ++i){
				int r = q.front().first, c = q.front().second;
				q.pop();
				for(int d = 0; d < 4; ++d){
					int nr = r + dr[d], nc = c + dc[d];
					if(nr < 0 or nr >= N or nc < 0 or nc >= N) continue;
					if(customer[nr][nc] > 0) {
						temp.push_back(make_pair(nr, nc));
						visited[nr][nc] = true;
						continue;
					}
					if(not visited[nr][nc] and city[nr][nc] == 0){
						q.push(make_pair(nr, nc));
						visited[nr][nc] = true;
					}
				}
			}
			if(!temp.empty()){
				find = true;
				fuel -= level;
				if(fuel <= 0){
					fuel = -1;
					return;
				}
				sort(temp.begin(), temp.end(), compare);
				int num = customer[temp[0].first][temp[0].second];
				customer[temp[0].first][temp[0].second] = 0;
				find_arrival(temp[0].first, temp[0].second, num);
				break;
			}
			level++;
		}
		if(fuel < 0 or not find){
			fuel = -1;
			return;
		}
		customers_left--;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> fuel;
	customers_left = M;
	city.resize(N);
	customer.resize(N);
	arrive.resize(M + 1);
	for(int i = 0; i < N; ++i){
		city[i].resize(N);
		customer[i].resize(N, 0);
		for(int j = 0; j < N; ++j){
			cin >> city[i][j];
		}
	}

	int customer_r, customer_c, arrive_r, arrive_c;
	cin >> start_r >> start_c;
	start_r--;
	start_c--;
	for(int i = 0; i < M; ++i){
		cin >> customer_r >> customer_c >> arrive_r >> arrive_c;
		customer[customer_r - 1][customer_c - 1] = i + 1;
		arrive[i + 1] = make_pair(arrive_r - 1, arrive_c - 1);
	}
	search_customer();
	if(fuel < 0) fuel = -1;
	cout << fuel << "\n";
	return 0;
}
