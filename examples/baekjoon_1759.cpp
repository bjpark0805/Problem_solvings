#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int L, C;
int consonent = 0, vowel = 0;
vector<char> v;
string password = "";
// vector<string> candidate;

void dfs(int idx){
	if(password.size() == L){
		if(consonent > 1 and vowel > 0) cout << password << "\n";
		return;
	}
	if(idx == C) return;

	password += v[idx];
	if(v[idx] == 'a' or v[idx] == 'e' or v[idx] == 'i' or v[idx] == 'o' or v[idx] == 'u'){
		vowel++;
	}
	else{
		consonent++;
	}
	dfs(idx + 1);
	password = password.substr(0, password.size() - 1);
	if(v[idx] == 'a' or v[idx] == 'e' or v[idx] == 'i' or v[idx] == 'o' or v[idx] == 'u'){
		vowel--;
	}
	else{
		consonent--;
	}
	dfs(idx + 1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> L >> C;
	v.resize(C);
	for(int i = 0; i < C; ++i){
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	dfs(0);

	// for(int i = 0; i < candidate.size(); ++i){
	// 	cout << candidate[i] << "\n";
	// }

	return 0;
}