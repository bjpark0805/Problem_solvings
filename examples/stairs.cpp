#include <iostream>
#include <algorithm>
using namespace std;

int stair[301] = {0};
int N;
int cache[301] = {0};

int score(int n){
	int& ref = cache[n];
	if(ref != 0) return ref;
	ref = 0;
	if(n == 0) return 0;
	else if(n == 1) return ref = stair[1];
	else if(n == 2) return ref = stair[1] + stair[2];
	else return ref = stair[n] + max(score(n - 2), stair[n-1] + score(n - 3));
}

int main(){
	cin >> N;
	for(int i = 1; i <= N; ++i){
		cin >> stair[i];
	}

	score(N);

	cout << cache[N];
	return 0;
}