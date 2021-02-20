#include <iostream>
#include <vector>
using namespace std;

// 스위핑 : 왼쪽에서 부터 오른쪽으로 가면서 계산 O(N) * 다른 알고리즘
// 세그먼트 트리 : a[n] ... a[m] 까지의 합을 구하는 법, 배열의 숫자를 바꾸는 법 O(logN)
// N : 3000 이면 O(N^2) or O(N^2logN)
// 

struct mine{
	int x, y, w;
	mine(int x1, int y1, int w1){
		x = x1;
		y = y1;
		w = w1;
	}
};

bool cmp(const mine &m1, const mine &m2){
	if(m1.x < m2.x) return true;
	else if(m1.x == m2.x) return m1.y < m2.y;
	else return false;
}
vector<mine> mines;

int main(){
	int N;
	long long max_profit = -1;
	cin >> N;
	for (int i = 1; i <= N; ++i){
		int x, y, w;
		cin >> x >> y >> w;
		mines.push_back(mine(x, y, w)); 
	}

	sort(mines.begin(), mines.end(), cmp);




	cout << max_profit << endl;

	return 0;
}