#include <stdio.h>
// #include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int A[2001];
int B[2001];
int cache[2001][2001] = {0};

int game(int left, int right){
	int& ret = cache[left][right];
	if(ret) return ret;
	
	// Either left or right is zero, the game is over.
	if(right == 0 || left == 0) return ret = 0;
	
	// Find the toppest card from the left, which is bigger than the right one.
	int index;
	for(index = left; index >= 1; --index){
		if(A[index] > B[right]) break;
	}
	
	if(index == 0) return ret = game(left - 1, right - 1);
	else return ret = max(game(left - 1, right - 1), game(index, right - 1) + B[right]);
	
}

int main(){
	int N;
	scanf("%d", &N);
	for(int i = N; i >= 1; --i){
		scanf("%d", &A[i]);
	}
	for(int i = N; i >= 1; --i){
		scanf("%d", &B[i]);
	}

	printf("%d\n", game(N, N));
	return 0;
}