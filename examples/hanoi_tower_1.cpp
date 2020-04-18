#include <stdio.h>
#include <iostream>
using namespace std;

void hanoi_tower(int from, int to, int N){
	hanoi_tower(1, 2, N - 1);
	printf("%d : %d -> %d\n", N, 1, 3);
	hanoi_tower(2, 3, N - 1);
}

int main(){
	int N;
	cin >> N;

	hanoi_tower(1, 3, N);

	return 0;
}