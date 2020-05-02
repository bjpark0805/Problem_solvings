// 2015 KOI middle #1
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int main(){
	int K, C;
	scanf("%d%d", &K, &C);
	for (int i = 1; i <= C; ++i){
		int M, N;
		scanf("%d%d", &M, &N);
		if(M > N){
			if(2*M - N - 2 > K) printf("0\n");
			else printf("1\n");
		}else if(M < N){
			if(2* N - M - 1 > K) printf("0\n");
			else printf("1\n");
		}else{
			printf("1\n");
		}
	}
	return 0;
}