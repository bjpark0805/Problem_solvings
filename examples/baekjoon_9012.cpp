#include <iostream>
#include <string>

using namespace std;

int main(){
	int T;
	cin >> T;
	for(int i = 0; i < T; ++i){
		string s;
		cin >> s;
		int n = 0;
		bool ans = true;
		for(int j = 0; j < s.size(); ++j){
			if(s[j] == '('){
				n += 1;
			}
			else n -= 1;
			if (n < 0) {ans = false; break;}
		}
		if (n != 0) ans = false;
		if(ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}