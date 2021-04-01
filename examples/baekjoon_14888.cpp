#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

int N, plus_, minus_, mul_, divide_;
vector<int> numbers;

int max_operating(int n, int sum){
	if(n == N) return sum;

	int max_ans = -INT_MAX; 
	if(plus_ != 0){
		plus_ -= 1;
		int tmp = max_operating(n + 1, sum + numbers[n]);
		max_ans = max(max_ans, tmp);
		plus_ += 1;
	}
	if(minus_ != 0){
		minus_ -= 1;
		int tmp = max_operating(n + 1, sum - numbers[n]);
		max_ans = max(max_ans, tmp);
		minus_ += 1;
	}
	if(mul_ != 0){
		mul_ -= 1;
		int tmp = max_operating(n + 1, sum * numbers[n]);
		max_ans = max(max_ans, tmp);
		mul_ += 1;
	}
	if(divide_ != 0){
		divide_ -= 1;
		int tmp = max_operating(n + 1, sum / numbers[n]);
		max_ans = max(max_ans, tmp);
		divide_ += 1;
	}
	return max_ans;
}

int min_operating(int n, int sum){
	if(n == N) return sum;
	int min_ans = INT_MAX;
	if(plus_ != 0){
		plus_ -= 1;
		int tmp = min_operating(n + 1, sum + numbers[n]);
		min_ans = min(min_ans, tmp);
		plus_ += 1;
	}
	if(minus_ != 0){
		minus_ -= 1;
		int tmp = min_operating(n + 1, sum - numbers[n]);
		min_ans = min(min_ans, tmp);
		minus_ += 1;
	}
	if(mul_ != 0){
		mul_ -= 1;
		int tmp = min_operating(n + 1, sum * numbers[n]);
		min_ans = min(min_ans, tmp);
		mul_ += 1;
	}
	if(divide_ != 0){
		divide_ -= 1;
		int tmp = min_operating(n + 1, sum / numbers[n]);
		min_ans = min(min_ans, tmp);
		divide_ += 1;
	}
	return min_ans;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	numbers.resize(N);
	for(int i = 0; i < N; ++i){
		cin >> numbers[i];
	}
	
	cin >> plus_ >> minus_ >> mul_ >> divide_;
	cout << max_operating(1, numbers[0]) << "\n" << min_operating(1, numbers[0]) << "\n"; 
	return 0;
}