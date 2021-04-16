// 55분 소요
// heap 사용하는 그리디인데 문제를 잘 읽자. 너무 말도 안되게 어려운거같으면 그냥 문제를 읽어라 제발
// priority queue랑 sort에서 compare함수 제대로 이해하기

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    sort(people.begin(), people.end(), greater<int>());
    pq.push(people[0]);
    for(int i = 1; i < people.size(); ++i){
    	if(people[i] + pq.top() > limit){
    		pq.push(people[i]);
    		continue;
    	}
    	else{
            pq.pop();
            answer++;
        }
    }
    answer += pq.size();
    return answer;
}

int main(){
	vector<int> people = {70, 80, 10, 20, 20};
	int limit = 100;
	cout << solution(people, limit) << endl;
	return 0;
}