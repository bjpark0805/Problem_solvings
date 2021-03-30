#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int max_profit(vector<int> &T, vector<int> &P, int now, int profit){
	if(now >= N) return profit;
	else if(now + T[now] > N) return max_profit(T, P, now + 1, profit);
	else return max(max_profit(T, P, now + 1, profit), max_profit(T, P, now + T[now], profit + P[now]));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	vector<int> T(N, 0), P(N, 0);
	for(int i = 0; i < N; ++i){
		cin >> T[i] >> P[i];
	}

	cout << max_profit(T, P, 0, 0) << "\n";
	return 0;
}