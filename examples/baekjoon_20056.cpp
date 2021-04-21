// 1시간 소요
// 시뮬래이션
// 삼성 시뮬레이션 상어문제들 특징: struct을 잘 쓰는건데 이번에 연습 잘한것같다.
// 디버깅하는데 나머지 이런 계산할때 조심하자.

#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

struct fireball{
	int m;
	int s;
	int d;
};

vector<vector<vector<fireball> > > space;

void Print(){
	cout << "---------------------\n";
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cout << space[i][j].size() << " ";
		}
		cout << endl;
	}
}
void move(){
	vector<vector<vector<fireball> > > temp(N, vector<vector<fireball> >(N));
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			for(int l = 0; l < space[i][j].size(); ++l){
				int d = space[i][j][l].d;
				int s = space[i][j][l].s;
				int nr = (i + (dr[d] + N) * s)%N, nc = (j + (dc[d] + N) * s)%N;
				temp[nr][nc].push_back(space[i][j][l]);
			}
		}
	}
	space = temp;
}

void merge_split(){
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if(space[i][j].size() < 2) continue;
			int total_weight = 0, total_speed = 0, odd = 0, even = 0;
			int total_size = space[i][j].size();
			for(int l = 0; l < total_size; ++l){
				total_weight += space[i][j][l].m;
				total_speed += space[i][j][l].s;
				if(space[i][j][l].d % 2 == 0) even++;
				else odd++;
			}

			space[i][j].clear();
			if(total_weight / 5 == 0) continue;
			if(odd == total_size or even == total_size){
				for(int d = 0; d < 8; d = d + 2){
					fireball FB = {total_weight / 5, total_speed / total_size, d};
					space[i][j].push_back(FB);
				}
			}
			else{
				for(int d = 1; d < 8; d = d + 2){
					fireball FB = {total_weight / 5, total_speed / total_size, d};
					space[i][j].push_back(FB);
				}	
			}
		}
	}
}

void magic(){
	int k = 0;
	while(k < K){
		move();
		merge_split();
		k++;
	}

	int answer = 0;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			for(int l = 0; l < space[i][j].size(); ++l){
				answer += space[i][j][l].m;
			}
		}
	}

	cout << answer << "\n";
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;
	space.resize(N);
	for(int i = 0; i < N; ++i){
		space[i].resize(N);
	}
	int r, c, m, s, d;
	for(int i = 0; i < M; ++i){
		cin >> r >> c >> m >> s >> d;
		r--;
		c--;
		fireball FB = {m, s, d};
		space[r][c].push_back(FB);
	}
	magic();
	return 0;
}