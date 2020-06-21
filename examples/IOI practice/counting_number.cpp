#include <stdio.h>
#include <iostream>
using namespace std;

int seed[42] = {0};
int divider[20] = {2, 3, 2, 5, 7, 2, 3, 11, 13, 2, 17, 19, 23, 5, 3, 29, 31, 2, 37, 41};
int seed_divider[20] = {2, 3, 4, 5, 7, 8, 9, 11, 13, 16, 17, 19, 23, 25, 27, 29, 31, 32, 37, 41};

// int strength(int )
long long strength_sum(long long n){
	long long sum = 0;
	for(int i = 0; i < 20; ++i){
		long long temp = n - n / divider[i];
		sum += (long long) (temp * (seed[seed_divider[i]] + 1));
		n = (long long)n / divider[i];
	}	
	return sum;
}

int main(){
	long long A, B;
	cin >> A >> B;
	
	// calculate seed strength
	seed[2] = 1;
	for(int i = 3; i <= 41; ++i){
		for(int j = 2; j <= 41; ++j){
			if(i % j != 0){
				seed[i] = seed[j] + 1;
				break;
			}
		}
	}
	
	printf("%lld\n", strength_sum(B) - strength_sum(A - 1));

	return 0;
}