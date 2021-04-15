//22분 
// 말그대로 hash(map)을 극한으로 사용해야하는 문제, 엄청 특이하다

#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

bool solution(vector<string> phone_book) {
	map<string, int> m;
    bool answer = true;
    for(int i = 0; i < phone_book.size(); ++i){
    	string phone_num = phone_book[i];
    	if(m.find(phone_num) != m.end()){
    		answer = false;
    		break;
    	}
    	m[phone_num] = 1;
    	for(int s = 1; s < phone_num.size(); ++s){
    		string sub_num = phone_num.substr(0, s);
    		if(m.find(sub_num) != m.end() and m[sub_num] == 1){
    			answer = false;
    			break;
    		}
    		else if(m.find(sub_num) == m.end()) m[sub_num] = 0;
    	}
    	if(not answer) break;
    }
    return answer;
}

int main(){
	vector<string> phone_book = {"123","456","789"};
	cout << solution(phone_book) << endl;
	return 0;
}