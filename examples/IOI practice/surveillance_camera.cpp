#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector< pair<int, int> > camera;
int maxcover_dp[1000000] = {0};
const int INF = 987654321;
int N, K;

int solveLinear(int begin, int end, int idx){
	int used = 0;
	while(begin <= end){
		int maxCover = -1;
		if(maxcover_dp[begin]){
			begin = maxcover_dp[begin] + 1;
		}else{
			while(idx < K && camera[idx].first <= begin){
			maxCover = max(maxCover, camera[idx].second);
			++idx;
			}
			if(maxCover < begin) return INF;
			maxcover_dp[begin] = maxCover;
			begin = maxCover + 1;
		}
		++used;
	}
	return used;
}

int main(){
	scanf("%d%d", &N, &K);
	for(int i = 1; i <= K; ++i){
		int ai, bi;
		scanf("%d%d", &ai, &bi);
		if(ai > bi){
			ai -= N;
		}
		camera.push_back(make_pair(ai, bi));
	}
	sort(camera.begin(), camera.end());

	int ret = K + 1;

	for(int i = 0; i < K; ++i){
		if(camera[i].first <= 1){
			ret = min(ret, 1 + solveLinear(camera[i].second + 1, camera[i].first + N - 1, i+1));
		}
	}

	if(ret >= K + 1) printf("impossible\n");
	else printf("%d\n", ret);

	return 0;
}

// #include <stdio.h>
// #include <vector>
// #include <iostream>
// #include <algorithm>

// using namespace std;
// vector< pair<int, int> > camera;
// const int INF = 987654321;
// int N, K;

// int solveLinear(int begin, int end){
// 	int used = 0, idx = 0;
// 	while(begin <= end){
// 		int maxCover = -1;
// 		while(idx < K && camera[idx].first <= begin){
// 			maxCover = max(maxCover, camera[idx].second);
// 			++idx;
// 		}
// 		if(maxCover < begin) return INF;
// 		begin = maxCover + 1;
// 		++used;
// 	}
// 	return used;
// }

// int main(){
// 	cin >> N >> K;
// 	for(int i = 1; i <= K; ++i){
// 		int ai, bi;
// 		scanf("%d%d", &ai, &bi);
// 		camera.push_back(make_pair(ai, bi));
// 	}
// 	sort(camera.begin(), camera.end());

// 	int ret = K + 1;

// 	for(int i = 0; i < K; ++i){
// 		if(camera[i].first > camera[i].second){
// 			ret = min(ret, 1 + solveLinear(camera[i].second + 1, camera[i].first - 1));
// 		}else if(camera[i].first == 1 && i == K-1){
// 			ret = min(ret, 1 + solveLinear(camera[i].second + 1, N));
// 		}else if(camera[i].first == 1 && camera[i+1].first > 1){
// 			ret = min(ret, 1 + solveLinear(camera[i].second + 1, N));
// 		}
// 	}

// 	if(ret >= K + 1) cout << "impossible";
// 	else cout << ret;

// 	return 0;
// }