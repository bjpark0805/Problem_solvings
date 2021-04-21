#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, answer = 0;

int dr[4] = {-1, -1, 1, 1};
int dc[4] = {-1, 1, -1, 1};

vector<bool> col;
vector<bool> diagonal1;
vector<bool> diagonal2;

void dfs(int i){
	if(i == N){
		answer++;
		return;
	}
	for(int j = 0; j < N; ++j){
		if(col[j] or diagonal1[i + j] or diagonal2[N-i+j]) continue;
		col[j] = true;
		diagonal1[i + j] = true;
		diagonal2[N - i + j] = true;
		
		dfs(i + 1);

		col[j] = false;
		diagonal1[i + j] = false;
		diagonal2[N - i + j] = false;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	col.resize(N, false);
	diagonal1.resize(2 * N, false);
	diagonal2.resize(2 * N, false);
	dfs(0);
	cout << answer << "\n";
	return 0;
}