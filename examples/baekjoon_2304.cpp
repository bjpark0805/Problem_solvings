#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<pair<int, int> > bar(N);
	vector<pair<int, int> > stack(0);
	int L, H;
	for(int i = 0; i < N; ++i){
		cin >> L >> H; 
		bar[i] = make_pair(L, H);
	}
	sort(bar.begin(), bar.end());
	stack.push_back(bar[0]);
	int prev_max = bar[0].second, ans = bar[0].second;
	for(int i = 1; i < N; ++i){
		while(stack.back().second <= bar[i].second){
			// If top is the tallest since here.
			if(stack.back().second == prev_max) {
				ans += prev_max * (bar[i].first - stack.back().first - 1) + bar[i].second;
				prev_max = bar[i].second;
				stack.push_back(bar[i]);
				break;
			}
			// Else, i.e. top is smaller than prev one.
			pair<int, int> top = stack.back();
			stack.pop_back();
			ans -= (top.first - stack.back().first) * top.second;
		}
		if(bar[i].second < stack.back().second) {
			ans += (bar[i].first - stack.back().first) * bar[i].second; 
			stack.push_back(bar[i]);
		}
	}
	cout << ans << endl;
	return 0;
}

/*
Second method: use two stack, sweep from left to right and right to left.
For each two stack, add bar only if the height is taller than the prev_max. 
Everytime the bar is added, sum prev_max * distance between the new bar and the top of the stack.
Finally, add two sums and the area between two heightest bar if the height of the bars are same. 
*/