#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    int l = s.size();
    if(l % 2 == 1) answer += s[l/2];
    else{
    	answer += s.substr(l/2 - 1, 2);
    }
    return answer;
}

int main(){
	string s = "qwe";
	cout << solution(s) << endl;
	return 0;
}