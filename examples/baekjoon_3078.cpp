#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	long long cnt = 0;
	cin >> N >> K;

	vector<int> nums(21, 0);
	queue<int> q;

	for(int i = 0; i < N; ++i){
		string s;
		cin >> s;
		if(q.size() <= K){
			nums[s.size()] += 1;
			q.push(s.size());
		}
		else{
			int front = q.front();
			nums[front] -= 1;
			cnt += nums[front];
			q.pop();
			q.push(s.size());
			nums[s.size()] += 1;
		}
	}
	while(not q.empty()){
		int front = q.front();
		nums[front] -= 1;
		cnt += nums[front];
		q.pop();
	}

	cout << cnt << "\n";
	return 0;
}