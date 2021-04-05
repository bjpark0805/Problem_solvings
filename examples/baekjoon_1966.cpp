#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N, order;
	
	cin >> T;
	for(int i = 0; i < T; ++i){
		cin >> N >> order;
		vector<int> documents(N, 0);
		queue<pair<int, int> > q;
		for(int j = 0; j < N; ++j){
			cin >> documents[j];
			q.push(make_pair(j, documents[j]));
		}
		sort(documents.begin(), documents.end());
		int cnt = 0;
		
		while(true){
			if(q.front().second == documents.back()){
				cnt += 1;
				if(q.front().first == order) break;
				q.pop();
				documents.pop_back();
			}
			else{
				q.push(q.front());
				q.pop();
			}
		}

		cout << cnt << "\n";
	}
	return 0;
}