#include <iostream>
#include <deque>
#include <string>
#include <sstream>
using namespace std;

/*
Key point: Parsing

When parsing in c++, think about just printing and use for loop 
instead of parsing it with STL like Python. 
*/

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, N;
	string p;
	cin >> T;
	for(int i = 0; i < T; ++i){
		cin >> p;
		cin >> N;
		bool front = true, error = false; 
		deque<string> deq;
		string s, stringBuffer;
		cin >> s;
		s = s.substr(1, s.size() - 1);
		s = s.substr(0, s.size() - 1);
		istringstream ss(s);
		while(getline(ss, stringBuffer, ',')){
			deq.push_back(stringBuffer);
		}

		for(int j = 0; j < p.size(); ++j){
			if(p[j] == 'D'){
				if(deq.empty()) {error = true; break;}
				else{
					if(front) deq.pop_front();
					else deq.pop_back();
				}
			}
			else front = !front;
		}
		if(error){
			cout << "error" << "\n";
			continue;
		}
		cout << "[";
		if(front){
			while(!deq.empty()){
				cout << deq.front();
				deq.pop_front();
				if(!deq.empty()) cout << ',';
			}
		} 
		else{
			while(!deq.empty()){
				cout << deq.back();
				deq.pop_back();
				if(!deq.empty()) cout << ',';
			}
		}
		cout << "]\n";
	}
	return 0;
}