// 15분 정도 소요
// 로컬에서 프로그래머스 문제 푸는데 익숙해짐
// 그냥 배열 다루는 문제

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    vector<int> ans(citations[citations.size() - 1] + 1, 0);
    int prev_c = -1;
    for(int i = 0; i < citations.size(); ++i){
    	int num = citations.size() - i;
    	int c = citations[i];
    	for(int j = prev_c + 1; j <= c; ++j){
    		ans[j] = num;
    	}
    	prev_c = c;
    }
    for(int i = 0; i < ans.size(); ++i){
    	if(ans[i] >= i) answer = i;
    }
    return answer;
}

int main(){
	vector<int> cit = {3, 0, 6, 1, 5};
	cout << solution(cit) << endl;
	return 0;
}