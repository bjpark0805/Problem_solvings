// 1시간 20분 소요
// 디버깅이 굉장히 오래걸렸는데 우선 크게 다음과 같은 문제가 있었다.
// 1. compare 함수를 처음에 너무 이상하게 짰던게 큰 문제
// 2. compare 함수에서 strict weak ordering을 해야한다는 것을 몰랐다.
// strict weak ordering 이란?
// compare(a, b) = true <-> a 다음 b
// compare(a, a) = false
// compare(a, b) = true -> compare(b, a) = false;
// compare(a, b) = true and compare(b, c) = true -> compare(a, c) = true;
// 이렇게 하는 이유는 compare(a, a) = true를 해버리면 a1 가 a2 앞에오는데 a2 가 a1 잎에오게되므로 자체 사이클이 생겨버림
// 잘 알아두자.

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(string a, string b){
    return stoi(a + b) > stoi(b + a);
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> numbers_s;
    for(int i = 0; i < numbers.size(); ++i){
    	numbers_s.push_back(to_string(numbers[i]));
    }
    sort(numbers_s.begin(), numbers_s.end(), compare);
    for(int i = 0; i < numbers_s.size(); ++i){
    	answer += numbers_s[i];
    }
    if(answer[0] == '0') answer = "0";
    return answer;
}

int main(){
	// vector<int> numbers = {6, 10, 2};
	vector<int> numbers = {3, 30, 34, 5, 9};

	string s = solution(numbers);
	cout << s<< endl;
	return 0;
}