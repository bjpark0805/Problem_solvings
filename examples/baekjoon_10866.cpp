#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	cin.ignore();
	string s, stringBuffer, str;
	deque<int> deq;
	for(int i = 0; i < N; ++i){
		getline(cin, s);
		istringstream ss(s);
		vector<string> v;
		v.clear();
		while(getline(ss, stringBuffer, ' ')){
			v.push_back(stringBuffer);
		}
		if(v[0] == "push_back"){
			deq.push_back(stoi(v[1]));
		}
		else if(v[0] == "push_front"){
			deq.push_front(stoi(v[1]));
		}
		else if(v[0] == "pop_back"){
			if(deq.empty()) cout << -1 << "\n";
			else {cout << deq.back() << "\n"; deq.pop_back();}
		}
		else if(v[0] == "pop_front"){
			if(deq.empty()) cout << -1 << "\n";
			else {cout << deq.front() << "\n"; deq.pop_front();}
		}
		else if(v[0] == "size"){
			cout << deq.size() << "\n";
		}
		else if(v[0] == "empty"){
			cout << deq.empty() << "\n";
		}
		else if(v[0] == "back"){
			if(deq.empty()) cout << -1 << "\n";
			else cout << deq.back() << "\n";
		}
		else if(v[0] == "front"){
			if(deq.empty()) cout << -1 << "\n";
			else cout << deq.front() << "\n"; 
		}
	}
	return 0;
}