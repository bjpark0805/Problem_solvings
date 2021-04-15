// 1시간 정도 소요
// 시뮬레이션
// 문제를 잘못읽어서 디버깅 실패
// pair 소팅하는 법 익히기

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
bool compare(pair<int, int> a, pair<int, int> b){
	if(a.second == b.second){
		return a.first < b.first;
	}
	else{
		return a.second < b.second;
	}
}
void arraycalculation(){
	int r, c, k;
	cin >> r >> c >> k;
	r--;
	c--;
	vector<vector<int> > A(100, vector<int>(100, 0));
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			cin >> A[i][j];
		}
	}
	if(A[r][c] == k){
		cout << 0 << "\n";
		return;
	}
	int R = 3, C = 3;
	int answer = 0;
	while(answer <= 100){
		answer++;		
		if(R >= C){
			int tmp_C = 0;
			for(int r = 0; r < R; ++r){
				vector<int> arr(101, 0);
				for(int c = 0; c < C; ++c){
					arr[A[r][c]]++;
				}
				vector<pair<int, int> > v;
				for(int i = 1; i < 101; i++){
					if(arr[i] != 0){
						v.push_back(make_pair(i, arr[i]));
					}
				}
				sort(v.begin(), v.end(), compare);
			
				int len = v.size();
				tmp_C = max(tmp_C, 2 * len);
				vector<int> temp(100, 0);
				for(int i = 0; i < min(50, len); ++i){
					temp[2*i] = v[i].first;
					temp[2*i + 1] = v[i].second;
				}
				for(int i = 0; i < 100; ++i){
					A[r][i] = temp[i];
				}
			}
			C = min(100, tmp_C);
		}
		else{
			int tmp_R = 0;
			for(int c = 0; c < C; ++c){
				vector<int> arr(101, 0);
				for(int r = 0; r < R; ++r){
					arr[A[r][c]]++;
				}
				vector<pair<int, int> > v;
				for(int i = 1; i < 101; ++i){
					if(arr[i] != 0){
						v.push_back(make_pair(i, arr[i]));
					}
				}
				sort(v.begin(), v.end(), compare);
				int len = v.size();
				tmp_R = max(tmp_R, len * 2);
				vector<int> temp(100, 0);
				for(int i = 0; i < min(50, len); ++i){
					temp[2*i] = v[i].first;
					temp[2*i + 1] = v[i].second;
				}
				for(int i = 0; i < 100; ++i){
					A[i][c] = temp[i];
				}
			}
			R = min(100, tmp_R);
		}
		
		if(A[r][c] == k){
			cout << answer << "\n";
			return;
		}
	}

	cout << -1 << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	arraycalculation();
	return 0;
}