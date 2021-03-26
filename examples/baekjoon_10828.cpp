#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	cin.ignore();
	vector<int> stk(0);
	for(int i = 0; i < N; ++i){
		string s;
		getline(cin, s);
		istringstream ss(s);
		string buffer;
		bool push = false;
		while(getline(ss, buffer, ' ')){
			if(push){
				stk.push_back(stoi(buffer));
				break;
			}
			if(buffer == "push"){
				push = true;
			}
			else if(buffer == "top"){
				if(stk.empty()){
					cout << -1 << endl;
				}else{
					cout << stk.back() << endl;
				}
			}
			else if(buffer == "pop"){
				if(stk.empty()){
					cout << -1 << endl;
				}else{
					int tmp = stk.back();
					cout << stk.back() << endl;
					stk.pop_back();
				}
			}
			else if(buffer == "size"){
				cout << stk.size() << endl;
			}
			else if(buffer == "empty"){
				cout << stk.empty() << endl;
			}
		}
	}
	return 0;
}