// 괄호가 여러개일 때는 카운트로 안되고 스택을 쌓아야한다.

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool correct_parenthesis(string s){
    vector<char> stack;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '(' or s[i] == '{' or s[i] == '[') stack.push_back(s[i]);
        else{
            if(stack.empty()) return false;
            if(stack.back() == '(' and s[i] == ')') stack.pop_back();
            else if(stack.back() == '{' and s[i] == '}') stack.pop_back();
            else if(stack.back() == '[' and s[i] == ']') stack.pop_back();
            else return false;
        }
    }
    if(stack.empty()) return true;
    else return false;
}
int solution(string s) {
    int answer = 0;
    int N = s.size();
    if(correct_parenthesis(s)) answer++;
    for(int i = 0; i < N - 1; ++i){
        rotate(s.begin(), s.begin() + 1, s.end());
        if(correct_parenthesis(s)) answer++;
    }
    return answer;
}