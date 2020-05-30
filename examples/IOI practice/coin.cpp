// 동전 문제
#include <stdio.h>
#include <vector>

int coin[21] = {0};
int cache[10001] = {0};

int main(){
	int N, M;
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i){
		scanf("%d", &coin[i]);
	}
	scanf("%d", &M);
	
	cache[0] = 1;

	for(int i = 1; i <= N; ++i){	// loop all the price
		for(int j = 1; j <= M; ++j){	// loop all the coins
			if(j >= coin[i]){
				cache[j] += cache[j-coin[i]];
			}
		}
	}
	printf("%d\n", cache[M]);
	return 0;
}