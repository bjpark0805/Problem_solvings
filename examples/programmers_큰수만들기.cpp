// 37분 소요
// 그리디라고 나와있긴 했는데 스택을 쓰는게 젤 현명해보임

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string solution(string number, int k) {
	vector<char> stack;
	int cnt = 0, i = 0;
	for(i = 0; i < number.size(); ++i){
		if(cnt == k) break;
		while(!stack.empty()){
			if(stack.back() < number[i]) {
				stack.pop_back(); cnt++;
				if(cnt == k) break;
			}
			else break;
		}
		stack.push_back(number[i]);
	}
	while(cnt < k){
		stack.pop_back();
		cnt++;
	}
    string answer(stack.begin(), stack.end());
    if(number.size() > stack.size() + k)
    	answer += number.substr(answer.size() + k, number.size() - answer.size() - k);

    return answer;
}

int main(){
	string number = "1924";
	int k = 2;
	cout <<  solution(number, k) << endl;
	return 0;
}