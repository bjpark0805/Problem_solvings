#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	long long ans = 0;
	vector<pair<int, long long> > stack(0);
	long long h;
	for(int i = 1; i <= N; ++i){
		cin >> h;
		if(stack.empty() || stack.back().second < h) stack.push_back(make_pair(i, h));
		else{
			pair<int, long long> top = stack.back();
			while(not stack.empty()){
				top = stack.back();
				if(top.second < h) break;
				stack.pop_back();
				int last_index = 0;
				if(not stack.empty()) last_index = stack.back().first;
				ans = max(ans, top.second * (i - last_index - 1));
			}
			stack.push_back(make_pair(i, h));
		}
	}
	while(not stack.empty()){
		pair<int, long long> top = stack.back();
		stack.pop_back();
		int last_index = 0;
		if(not stack.empty()) last_index = stack.back().first;
		ans = max(ans, top.second * (N - last_index));
	}
	cout << ans << endl;
	return 0;
}