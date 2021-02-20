#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> cards;
int cache[1001][1001] = {0};
int N;

int best_score(int i, int j, int sum){
	int& ref = cache[i][j];
	if(ref != 0) return ref;
	else if(i == j) return ref = cards[i];
	else{
		int case1 = sum - best_score(i + 1, j, sum - cards[i]); 
		int case2 = sum - best_score(i, j - 1, sum - cards[j]);
		return ref = max(case1, case2);
	}
}

int main(){
	int T;
	cin >> T;
	for(int i = 1; i <= T; ++i){
		cin >> N;
		cards.resize(N + 1, 0);
		for(int i = 0; i <= 1000; ++i){
			for(int j = 0; j <= 1000; ++j){
				cache[i][j] = 0;
			}
		}
		int sum = 0;
		for(int j = 1; j <= N; ++j){
			cin >> cards[j];
			sum += cards[j];
		}
		cout << best_score(1, N, sum) << endl;
	}
	return 0;
}