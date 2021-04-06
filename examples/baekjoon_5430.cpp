#include <iostream>
#include <deque>
#include <string>
#include <sstream>
using namespace std;

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
		deque<string> deq(N);
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
		string ans = "[";
		if(front){
			for(int i = 0; i < deq.size(); ++i){
				ans = ans + deq[i] + ',';
			}
		} 
		else{
			for(int i = deq.size() - 1; i >= 0; --i){
				ans = ans + deq[i] + ',';
			}
		}
		if(ans.size() != 1){
			ans = ans.substr(0, ans.size() - 1);
		}
		ans = ans + ']';
		cout << ans << "\n";
	}
	return 0;
}