#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, P, l, p, cnt = 0;
	cin >> N >> P;
	vector<vector<int> > line;
	line.resize(6);

	for(int i = 0; i < N; ++i){
		cin >> l >> p;
		while(not line[l-1].empty()){
			if(line[l-1].back() == p) break;
			else if(line[l-1].back() < p){
				line[l-1].push_back(p); cnt += 1; break;
			}
			else{
				line[l-1].pop_back(); cnt += 1;
			}
		}
		if(line[l-1].empty()){
			line[l-1].push_back(p); cnt += 1;
		}
	}

	cout << cnt << "\n";
	return 0;
}