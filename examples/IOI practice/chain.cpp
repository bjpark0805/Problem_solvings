#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int N, remain, cut = 0;
	cin >> N;
	remain = N;
	vector<int> Li;
	Li.resize(N+1);
	for(int i = 1; i <= N; ++i){
		scanf("%d", &Li[N]);
	}
	sort(Li.begin(), Li.end());

	for(int i = 1; i < N; ++i){
		// Longest Li is the first chain.
		if(Li[i] >= remain){
			cut += remain;
			break;
		}
		cut += Li[i];
		remain -= Li[i] + 1;
	}

	cout << remain;
	return 0;
}