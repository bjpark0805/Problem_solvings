// 1시간 10분 소요
// 시뮬레이션
// 인덱스를 참조할게 굉장히 많았는데 (물론 좀 더 생각하니까 더 편하게 할 수 있긴 했음)
// 실수가 나와서 디버깅이 좀 힘들었다.
// 한쪽 방향만 잘 만든다음에 다른 3개의 방향은 잘 바꿔가면서 쓸 수 있었는데 괜히 아무 생각없이 하다가 다 써버림(시간 낭비)

#include <vector>
#include <iostream>

using namespace std;

int N, answer = 0;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {-1, 0, 1, 0};

int dustr[4][10] = {
	{-1, 1, -2, -1, 1, 2, -1, 1, 0, 0},
	{0, 0, 1, 1, 1, 1, 2, 2, 3, 2},
	{-1, 1, -2, -1, 1, 2, -1, 1, 0, 0},
	{0, 0, -1, -1, -1, -1, -2,-2,-3,-2}
};
int dustc[4][10] = {
	{0, 0, -1, -1, -1, -1, -2, -2, -3, -2},
	{-1, 1, -2, -1, 1, 2, -1, 1, 0, 0},
	{0, 0, 1, 1, 1, 1, 2, 2, 3, 2},
	{-1, 1, -2, -1, 1, 2, -1, 1, 0, 0}
};
int dpercentage[9] = {1, 1, 2, 7, 7, 2, 10, 10, 5};

vector<vector<int> > A;
vector<vector<int> > B;
void Print(){
	cout << "--------------------\n";
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}
void tornado(int r, int c, int d){
	int yr = r + dr[d], yc = c + dc[d];
	int total_dust = A[yr][yc];
	for(int i = 0; i < 10; ++i){
		int nr = r + dustr[d][i];
		int nc = c + dustc[d][i];
		if(i == 9){
			if(nr < 0 or nr >= N or nc < 0 or nc >= N){
				answer += A[yr][yc];
			}
			else{
				A[nr][nc] += A[yr][yc];
			}
			A[yr][yc] = 0;
		}
		else{
			int add_dust = total_dust * dpercentage[i] / 100;
			if(nr < 0 or nr >= N or nc < 0 or nc >= N){
				answer += add_dust; 
			}
			else{
				A[nr][nc] += add_dust;
			}
			A[yr][yc] -= add_dust;
		}
	}
}

void magic(){
	int r = N/2, c = N/2, l = 1, d = 0, cnt = 0;
	while(true){
		cnt++;
		for(int i = 0; i < l; ++i){
			tornado(r, c, d);
			r += dr[d];
			c += dc[d];
			B[r][c] = cnt;
			if(r == 0 and c == 0){
				cout << answer <<"\n";
				return;
			}
		}
		d = (d + 1)%4;
		if(cnt % 2 == 0) l++;
	}
	tornado(r, c, d);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	A.resize(N);
	B.resize(N);
	for(int i = 0; i < N; ++i){
		B[i].resize(N, 0);
		A[i].resize(N, 0);
		for(int j = 0; j < N; ++j){
			cin >> A[i][j];
		}
	}
	magic();
	// Print();
	return 0;
}	
