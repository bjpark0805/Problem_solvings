// KOI 2016 middle #3

#include <iostream>
#include <vector>
using namespace std;
vector<int> parent;

int find_root(int node){
	while(1){
		if(parent[node] == node) return node;
		else {
			node = parent[node]; 
			continue;
		}
	}
}


int main(){
	int N, Q;
	cin >> N >> Q;
	parent.resize(N + 1);

	parent[1] = 1;
	for(int i = 2; i <= N; ++i){
		cin >> parent[i];
	}
	int query_num = 1;
	for(int i = 1; i <= N - 1 + Q; ++i){
		int x; 
		cin >> x;
		if(x == 0){
			int b;
			cin >> b;
			parent[b] = b;
		}else{
			int c, d;
			cin >> c >> d;
			if(find_root(c) == find_root(d)) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}

	return 0;
}