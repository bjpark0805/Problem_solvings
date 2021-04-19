#include <iostream>
#include <vector>

using namespace std;

int N, S;
int cnt = 0;
vector<int> v;
void dfs(int idx, int curr_sum){
	if(idx == N) return;
	if(curr_sum + v[idx] == S) cnt++;
	dfs(idx + 1, curr_sum);
	dfs(idx + 1, curr_sum + v[idx]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S;
	v.resize(N);
	for(int i = 0; i < N; ++i){
		cin >> v[i];
	}

	dfs(0, 0);

	cout << cnt << "\n";
	return 0;
}