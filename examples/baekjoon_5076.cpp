#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	vector<string> stack(0);
	while(true){
		getline(cin, s);
		if(s == "#") break;
		int start, end;
		for(int i = 0; i < s.size(); ++i){
			if(s[i] == '<') start = i + 1;
			else if(s[i] == '>') {
				end = i - 1;
				if(s[start] == '/'){ // closing tag
					if(not stack.empty() && stack.back() == s.substr(start + 1, end - start)) stack.pop_back();
					else{
						stack.push_back("a");
						break;
					}
				}
				else{
					if(s.substr(start, end - start + 1) == "br /") continue;
					for(int i = start; i <= end; ++i){
						if(s[i] == ' '){
							end = i - 1;
							break;
						}
					}
					stack.push_back(s.substr(start, end - start + 1));
				}
			}
		}
		if(stack.empty()) cout << "legal" << "\n";
		else cout << "illegal" << "\n";
		stack.resize(0);
	}
}