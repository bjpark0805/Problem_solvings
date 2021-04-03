#include <iostream>
#include <queue>
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
	vector<string> x;
	string str, stringBuffer;
	queue<int> q;
	for(int i = 0; i < N; ++i){
		x.clear();
		getline(cin, str);
		istringstream ss(str);
		while (getline(ss, stringBuffer, ' ')){
			x.push_back(stringBuffer);
		}
		if(x[0] == "push") q.push(stoi(x[1]));
		else if(x[0] == "front"){
			if(q.empty()) cout << -1 << "\n";
			else cout << q.front() << "\n";
		}
		else if(x[0] == "back"){
			if(q.empty()) cout << -1 << "\n";
			else cout << q.back() << "\n";
		}
		else if(x[0] == "pop"){
			if(q.empty()) cout << -1 << "\n";
			else{
				int a = q.front();
				cout << a << "\n";
				q.pop();
			}
		}
		else if(x[0] == "size"){
			cout << q.size() << "\n";
		}
		else if(x[0] == "empty"){
			cout << q.empty() << "\n";
		}
	}

	return 0;
}