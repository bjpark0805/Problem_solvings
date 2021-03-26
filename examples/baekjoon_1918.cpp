#include <iostream>
#include <string>
#include <vector>
using namespace std;

int operator_to_num(char c){
	if(c == '(') return 0;
	else if(c == '+' || c == '-') return 1;
	else return 2;
}

int compare_char(const char x, const char y){
	return (operator_to_num(x) < operator_to_num(y)) ? 1 : 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	vector<char> stack1;
	vector<char> stack2;
	for(int i = 0; i < s.size(); ++i){
		if(s[i] == '(') stack2.push_back('(');
		else if(s[i] == '*' || s[i] == '+' || s[i] == '-' || s[i] == '/'){
			if(stack2.empty()){
				stack2.push_back(s[i]);
				continue;
			}
			// If new operator is strictly prior to the last operator at stack2, just push at stack2.
			// Else, pop and push the operator at stack1 until the operator at stack2 is strictly prior to the new one.
			while(not stack2.empty()){
				char top = stack2.back();

				if(compare_char(top, s[i])) break; 
				stack1.push_back(top);
				stack2.pop_back();
			}
			stack2.push_back(s[i]);
		} 
		else if(s[i] == ')'){
			char c = stack2.back();
			stack2.pop_back();
			while(c != '('){
				stack1.push_back(c);
				c = stack2.back();
				stack2.pop_back();
			}
		}
		else stack1.push_back(s[i]);
	}
	while(not stack2.empty()){
		stack1.push_back(stack2.back());
		stack2.pop_back();
	}

	string ans(stack1.begin(), stack1.end());
	cout << ans << endl;
	return 0;
}