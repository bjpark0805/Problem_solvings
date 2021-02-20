#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<long long> >matrix;
const long long mod = 1000000007LL;
matrix operator * (const matrix &A, const matrix &B){
	int n = A.size();
	matrix C = matrix(n, vector<long long>(n));
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			for(int k = 0; k < n; ++k){
				C[i][j] += A[i][k] * B[k][j];
			}
			C[i][j] %= mod;
		}
	}
	return C;
} 

int main(){
	long long N;
	cin >> N;
	matrix answer = {{1, 0}, {0, 1}};
	matrix A = {{1, 1}, {1, 0}};

	if(N <= 1){
		cout << N << endl;
		return 0;
	} 

	while(N >= 1){
		if(N % 2 == 1){
			answer = answer * A;
		}
		A = A * A;
		N = N/2;
	}

	cout << answer[0][1] << endl;
	return 0;
}