// 1시간 반 소요. 
// 구현, 각 행렬의 인덱스 정의하는게 좀 힘들었음.
// 약간 실수로 인한 디버깅

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, total = 0;
vector<vector<int> > city;

int calculate_diff(int x, int y, int d1, int d2){
	vector<int> areas(5, 0);
	//area1
	for(int r = 0; r < x + d1; ++r){
		for(int c = 0; c < y - max(r-x, -1); ++c){
			areas[0] += city[r][c];
		}
	}
	//area2
	for(int r = 0; r <= x + d2; ++r){
		for(int c = max(y + 1, r - x + 1 + y); c < N; ++c){
			areas[1] += city[r][c];
		}
	}

	//area3
	for(int r = x + d1; r < N; ++r){
		for(int c = 0; c <= min(y - d1 + d2 - 1, y - d1 - 1 + r - x - d1); ++c){
			areas[2] += city[r][c];
		}
	}

	//area4
	for(int r = x + d2 + 1; r < N; ++r){
		for(int c = max(y + d2 + 1 - r + x + d2, y - d1 + d2); c < N; ++c){
			areas[3] += city[r][c];
		}
	}

	areas[4] = total - areas[0] - areas[1] - areas[2] - areas[3];
	sort(areas.begin(), areas.end());
	return areas[4] - areas[0];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	city.resize(N);
	for(int i = 0; i < N; ++i){
		city[i].resize(N);
		for(int j = 0; j < N; ++j){
			cin >> city[i][j];
			total += city[i][j];
		}
	}
	int answer = 40001;
	for(int x = 1; x <= N - 3; ++x){
		for(int y = 2; y <= N - 2; ++y){
			for(int d1 = 1; d1 <= (N+1)/2; ++d1){
				for(int d2 = 1; d2 <= (N+1)/2; ++d2){
					if(x + d1 + d2 >= N or y < d1 or y + d2 >= N) break;
					answer = min(answer, calculate_diff(x, y, d1, d2));
				}
			}
		}
	}
	cout << answer << "\n";
	return 0;
}