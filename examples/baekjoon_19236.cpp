// 2시간 30분 소요
// 백트레킹, 시뮬레이션
// 맨처음에 조건문에서 약간씩 잘못 쓴 것들이 있어 오래걸림. 어쩔 수 없는 케이스
// 물고기 총 갯수가 16개인데 그걸 15개로 해서 우선 에러
// 나머지 하나는 문제 워딩이 좀 문제.
// 이렇게 백트레킹 과정에서 돌려놓는 것이 어려울 경우, 카피해서 하나 만들어놓고 나중에 다시 돌려놓는 방법 등이 있다.
// 전역변수에 덮어씌우는 것이 훨신 효율적이다. 
// 이는 call by reference, call by value의 차이에서 세게 올 것 같은데 정확한 건 다시 찾아본다.

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, -1, -1, -1, 0, 1, 1, 1};

class fish{
public:
	int r;
	int c;
	int d;
};

vector<int> path;

void Print(vector<vector<int> > space){
	cout << "==========================\n";
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 4; ++j){
			cout << space[i][j] << " ";
		}
		cout << endl;
	}
}
int shark_move(vector<vector<int> > space, vector<fish> fishes, int shark_r, int shark_c, int shark_d){
	// existing fishes move
	for(int i = 1; i <= 16; ++i){
		fish start = fishes[i];
		if(start.d == -1) continue;
		int nr = 0, nc = 0;
		int cnt = 0;
		while(cnt < 8){
			nr = start.r + dr[start.d];
			nc = start.c + dc[start.d];
			if(nr < 0 or nr >= 4 or nc < 0 or nc >= 4 or (nr == shark_r and nc == shark_c)){
				start.d = (start.d + 1)%8;
				cnt++;
			}
			else break; 
		}
		if(cnt == 8) continue;
		int prev_r = start.r, prev_c = start.c, prev_d = start.d;
		if(space[nr][nc] == 0){
			space[prev_r][prev_c] = 0;
			space[nr][nc] = i;
			fishes[i].r = nr;
			fishes[i].c = nc;
			fishes[i].d = prev_d;
		}
		else{
			int end_num = space[nr][nc];
			fishes[end_num].r = prev_r;
			fishes[end_num].c = prev_c;
			space[prev_r][prev_c] = end_num;
			fishes[i].r = nr;
			fishes[i].c = nc;
			fishes[i].d = start.d;
			space[nr][nc] = i;
		}
		
	}
	// shark move
	int answer = 0;
	for(int i = 1; i < 4; ++i){
		int nr = shark_r + i * dr[shark_d], nc = shark_c + i * dc[shark_d];
		if(nr < 0 or nr >= 4 or nc < 0 or nc >= 4) break;
		if(space[nr][nc] == 0) continue;
		
		vector<vector<int> > new_space(space);
		vector<fish> new_fishes(fishes);

		int nd = fishes[space[nr][nc]].d;
 		new_space[nr][nc] = 0;
		new_fishes[space[nr][nc]].r = -1;
		new_fishes[space[nr][nc]].c = -1;
		new_fishes[space[nr][nc]].d = -1;
		path.push_back(space[nr][nc]);
		answer = max(answer, space[nr][nc] + shark_move(new_space, new_fishes, nr, nc, nd));
		path.pop_back();
	}
	
	// Print(space);
	return answer;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int> > space(4, vector<int>(4));
	vector<fish> fishes(17);

	int n, d;
	fish empty_fish = {-1, -1, -1};
	fishes[0] = empty_fish;
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 4; ++j){
			cin >> n >> d;
			d--;
			space[i][j] = n;
			fish temp = {i, j, d};
			fishes[n] = temp;
		}
	}

	n = space[0][0];
	d = fishes[n].d;
	fishes[n].r = -1;
	fishes[n].c = -1;
	fishes[n].d = -1;
	space[0][0] = 0;
	path.push_back(n);
	cout << n + shark_move(space, fishes, 0, 0, d) << "\n";
	return 0;
}