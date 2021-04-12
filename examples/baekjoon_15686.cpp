// 29분
// 안정적

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdlib>
using namespace std;

int N, M;
vector<vector<int> > city;
vector<pair<int, int> > chickens;
vector<bool> choose;

int choose_chicken(int curr, int cnt){
	if(curr == chickens.size()){
		if(cnt > M or cnt == 0) return N * N * 4 + 1;
		int ans = 0;
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < N; ++j){
				if(city[i][j] == 1){
					int tmp = 2 * N + 1;
					for(int c = 0; c < chickens.size(); ++c){
						if(choose[c]){
							tmp = min(tmp, abs(chickens[c].first - i) + abs(chickens[c].second - j));
						}
					}
					ans += tmp;
				}
			}
		}
		return ans;
	}
	int ans = choose_chicken(curr + 1, cnt);
	choose[curr] = true;
	ans = min(ans, choose_chicken(curr + 1, cnt + 1));
	choose[curr] = false;

	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;

	city.resize(N);
	for(int i = 0; i < N; ++i){
		city[i].resize(N);
		for(int j = 0; j < N; ++j){
			cin >> city[i][j];
			if(city[i][j] == 2) chickens.push_back(make_pair(i, j));
		}
	}

	choose.resize(chickens.size(), false);
	cout << choose_chicken(0, 0) << "\n";
	return 0;
}