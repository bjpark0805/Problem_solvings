// 15분정도 소요
// min heap 단순 개념

#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i = 0; i < scoville.size(); ++i){
    	pq.push(scoville[i]);
    }
    while(pq.top() < K){
    	if(pq.size() == 1){
    		answer = -1;
    		break;
    	}
    	int top1 = pq.top();
    	pq.pop();
    	int top2 = pq.top();
    	pq.pop();
    	pq.push(top1 + top2 * 2);
  		answer += 1;
    }
    return answer;
}

int main(){
	vector<int> sco = {1, 2, 3, 9, 10, 12};
	int K = 7;
	cout << solution(sco, K) << endl;
	return 0;
}