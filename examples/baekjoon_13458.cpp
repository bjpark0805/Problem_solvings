#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, B, C;
	cin >> N;
	vector<int> applicants(N);
	for(int i = 0; i < N; ++i){
		cin >> applicants[i];
	}
	cin >> B >> C;
	long long ans = N;
	for(auto &x: applicants){
		int left = max(0, x - B);
		ans += left/C + (left%C > 0);
	}
	cout << ans;
	return 0;
}