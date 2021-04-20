// 시간 못잼 중간에 끊겨서
// 시뮬레이션
// 구현자체가 엄청 어렵진않았는데 꽤 빡세긴했다.
// 문제 자체의 워딩이 애매해서 디버깅하는데 시간을 좀 썼고, 일부 생각을 잘못해서 또 디버깅했다.

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int N, M, k;
vector<vector<pair<vector<pair<int, int> >, vector<int> > > > space;
vector<vector<vector<int> > > priority;
vector<pair<pair<int, int>, int> > shark;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int shark_left;

void Print(){
	cout << "--------------------------------------------\n";
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cout << space[i][j].second.size() << " ";
			//  << space[i][j].second[0] << "\n";
		}
		cout << endl;
	}
}

void Print_scent(){
	cout << "--------------------------------------------\n";
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if(space[i][j].first.empty()) cout << '#' << " ";
			else cout << space[i][j].first[0].first << " ";
			//  << space[i][j].second[0] << "\n";
		}
		cout << endl;
	}
}
void grown_up_shark(){
	int time = 0;
	while(time < 1000){
		time++;
		vector<vector<vector<int> > > shark_temp(N, vector<vector<int> >(N));
		vector<vector<vector<pair<int, int> > > > scent_temp(N, vector<vector<pair<int, int> > >(N));
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < N; ++j){
				scent_temp[i][j] = space[i][j].first;
			}
		}
		// shark move
		for(int s = 0; s < M; ++s){
			if(shark[s].second == -1) continue;
			bool move = false;
			int r = shark[s].first.first;
			int c = shark[s].first.second;
			// 우선순위 체크
			vector<int> priority_s = priority[s][shark[s].second];
			for(int p = 0; p < priority_s.size(); ++p){
				int d = priority_s[p];
				int nr = r + dr[d], nc = c + dc[d];
				if(nr < 0 or nr >= N or nc < 0 or nc >= N or !space[nr][nc].first.empty()) continue;
				move = true;
				shark[s].first.first = nr;
				shark[s].first.second = nc;
				shark[s].second = d;
				shark_temp[nr][nc].push_back(s);
				scent_temp[nr][nc].push_back(make_pair(s, k+1));
				break;
			}
			// 냄새 없는 칸이 있었을 때.
			if(move) continue;
			
			move = false;
			for(int p = 0; p < priority_s.size(); ++p){
				int d = priority_s[p];
				int nr = r + dr[d], nc = c + dc[d];
				if(nr < 0 or nr >= N or nc < 0 or nc >= N) continue;
				for(int i = 0; i < scent_temp[nr][nc].size(); ++i){
					if(scent_temp[nr][nc][i].first == s){
						move = true;
						shark_temp[nr][nc].push_back(s);
						shark[s].first.first = nr;
						shark[s].first.second = nc;
						shark[s].second = d;
						scent_temp[nr][nc][i].second = k + 1;
						break;
					}
				}
				if(move) break;
			}
		}

		for(int i = 0; i < N; ++i){
			for(int j = 0; j < N; ++j){
				space[i][j].second = shark_temp[i][j];
				space[i][j].first = scent_temp[i][j];
				// Reduce scent left;
				vector<pair<int, int> > temp;
				for(int k = 0; k < space[i][j].first.size(); ++k){
					space[i][j].first[k].second--;
					if(space[i][j].first[k].second > 0) temp.push_back(space[i][j].first[k]);
				}
				space[i][j].first = temp;

				// Eliminate shark in the same block
				while(space[i][j].second.size() > 1){
					int shark_elim = space[i][j].second.back();
					shark[shark_elim].second = -1;
					space[i][j].second.pop_back();
					space[i][j].first.pop_back();
					shark_left--;
				}
			}
		}
		// Print();
		// Print_scent();
		// if(time >= 4) break;
		// if only shark 1 left, break
		if(shark_left == 1){
			cout << time << "\n";
			return;
		}
	}
	cout << -1 << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> k;
	space.resize(N);
	shark.resize(M);
	shark_left = M;
	for(int i = 0; i < N; ++i){
		space[i].resize(N);
		for(int j = 0; j < N; ++j){
			int num;
			cin >> num;
			if(num != 0){
				num--;
				space[i][j].first.push_back(make_pair(num, k));
				space[i][j].second.push_back(num);
				shark[num] = make_pair(make_pair(i, j), -1);
			}
		}
	}
	for(int i = 0; i < M; ++i){
		int d;
		cin >> d;
		d--;
		shark[i].second = d;
	}
	int d1;
	priority.resize(M);
	for(int i = 0; i < M; ++i){
		priority[i].resize(4);
		for(int j = 0; j < 4; ++j){
			priority[i][j].resize(4);
			for(int k = 0; k < 4; ++k){
				cin >> d1; 
				priority[i][j][k] = d1 - 1;
			}
		}
	}

	grown_up_shark();

	return 0;
}