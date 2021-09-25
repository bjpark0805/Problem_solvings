#include <cstdio>
#include <vector>
int modular = 1000000007;
std::vector<long long> fac;

long long power_mod(long long a, int n){
	if (n == 1) return a;
	long long h = power_mod(a, n/2);
	long long ans = (h * h)%modular;
	if (n%2 == 1){
		ans = (ans * a)%modular;
	}
	return ans;
}

void binomial_coefficient3(int N, int K){
	long long ans = (fac[N] * power_mod(fac[N-K], modular-2))%modular;
	ans = (ans * power_mod(fac[K], modular-2))%modular;
	printf("%lld\n", ans);
}

void calculate_factorials(int N){
	fac.resize(N+1, 1);
	for(int i = 1; i <= N; ++i){
		fac[i] = (fac[i-1] * i) % modular;
	}
}
int main(){
	int N, K;
	scanf("%d%d", &N, &K);
	calculate_factorials(N);
	binomial_coefficient3(N, K);
	return 0;
}