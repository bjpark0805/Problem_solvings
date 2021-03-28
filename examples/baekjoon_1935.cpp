#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

double operators(double a, double b, char o){
	if(o == '+') return a + b;
	else if(o == '-') return a - b;
	else if(o == '*') return a * b;
	else return a/b;
}
int main(){
	int N;
	map<char, double> m;
	cin >> N;
	string s;
	cin >> s;
	double n;
	vector<double> stack;
	for(int i = 0; i < N; ++i){
		cin >> n;
		m['A'+i] = n;
	}
	for(int i = 0; i < s.size(); ++i){
		if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
			double b = stack.back();
			stack.pop_back();
			double a = stack.back();
			stack.pop_back();
			stack.push_back(operators(a, b, s[i]));
		}
		else {
			stack.push_back(m[s[i]]);
		}
	}
	printf("%.2f\n", stack.back());
	return 0;
}