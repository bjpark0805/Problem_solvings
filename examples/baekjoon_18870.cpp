#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

bool compare (std::pair<int,int> a, std::pair<int,int> b){
	if (a.second == b.second){
		return a.first < b.first;
	}
	else{
		return a.second < b.second;
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
 
	int N;
	std::cin >> N;
	std::vector<std::pair<int, int> > arr(N, std::make_pair(0, 0));
	for(int i = 0; i < N; ++i) {
		std::cin >> arr[i].second;
		arr[i].first = i;
	}
	std::sort(arr.begin(), arr.end(), compare);

	std::vector<int> ans(N, 0);

	int prev_n = 1000000001;
	int prev_c = -1;
	for(int i = 0; i < N; ++i){
		if(arr[i].second != prev_n){
			prev_n = arr[i].second;
			prev_c++;
		}
		ans[arr[i].first] = prev_c;
	}

	for(auto &i: ans){
		std::cout << i << " ";
	}
	return 0;
}