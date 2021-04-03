#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, cnt = 0;
	cin >> N;
	vector<char> stack(0);
	string s;
	for(int i = 0; i < N; ++i){
		stack.resize(0);
		cin >> s;
		for(int i = 0; i < s.size(); ++i){
			if(stack.empty()) stack.push_back(s[i]);
			else{
				if(stack.back() == s[i]) stack.pop_back();
				else stack.push_back(s[i]);
			}
		}
		if(stack.empty()) cnt += 1;
	}
	cout << cnt << "\n";
	return 0;
}