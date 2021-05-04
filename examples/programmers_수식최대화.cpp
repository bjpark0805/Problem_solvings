#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

vector<string> express;
vector<char> operators;
vector<bool> visited;
string priority = "";
int N;
long long maxv;

vector<string> split(string expression){
	size_t previous = 0, current;
    string delimiter = "+-*/";
    current = expression.find_first_of(delimiter);
    vector<string> express;
    while(current != string::npos){
    	express.push_back(expression.substr(previous, current - previous));
    	express.push_back(expression.substr(current, 1));
    	if(find(operators.begin(), operators.end(), expression[current]) == operators.end()) operators.push_back(expression[current]);
    	previous = current + 1;
    	current = expression.find_first_of(delimiter, previous);
    }
    express.push_back(expression.substr(previous, current - previous));
    return express;
}

long long calculate(long long first, long long second, string op){
	if(op == "*") return first * second;
	else if(op == "+") return first + second;
	else return first - second;
}
void calculate_expression(){
	vector<long long> stack;
	vector<string> ops;
	for(int i = 0; i < express.size(); ++i){
		if(express[i] != "+" and express[i] != "-" and express[i] != "*"){
			stack.push_back(stol(express[i]));
		}
		else{
			if(ops.empty()) ops.push_back(express[i]);
			else{
				int new_o = priority.find(express[i]);
				while(!ops.empty()){
					int old_o = priority.find(ops.back());
					if(new_o < old_o) break;
					long long second = stack.back();
					stack.pop_back();
					long long first = stack.back();
					stack.pop_back();
					stack.push_back(calculate(first, second, ops.back()));
					ops.pop_back();
				}
				ops.push_back(express[i]);
			}
		}
	}

	while(!ops.empty()){
		long long second = stack.back();
		stack.pop_back();
		long long first = stack.back();
		stack.pop_back();
		stack.push_back(calculate(first, second, ops.back()));
		ops.pop_back();
	}

	maxv = max(maxv, abs(stack[0]));
}


void dfs(int cnt){
	if(cnt == N){
		calculate_expression();
		return;
	}
	for(int i = 0; i < N; ++i){
		if(visited[i]) continue;
		visited[i] = true;
		priority += operators[i];
		dfs(cnt + 1);
		visited[i] = false;
		priority = priority.substr(0, cnt);
	}
}

long long solution(string expression) {
    express = split(expression);
    visited.resize(operators.size(), false);
    N = operators.size();
    dfs(0);
    return maxv;
}

int main(){
	string expression = "100-200*300-500+20";
	cout << solution(expression) << endl;
	return 0;
}