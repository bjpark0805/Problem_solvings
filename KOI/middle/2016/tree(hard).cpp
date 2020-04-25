// KOI 2016 middle #3

#include <iostream>
#include <vector>
using namespace std;
vector<int> parent;
vector<int> lifetime;
vector< pair<int, int> > query;
vector<bool> edge_set;
int N, Q;

int find_root(int node){
	while(1){
		if(edge_set[node]) {
			if(parent[node] == node) return node;
			else{
				node = parent[node];
			}
		}
		else return node;
	}
}

void solve(int start, int end){
	vector<int> index;
	for(int i = 2; i <= N; ++i){
		if(lifetime[i] >= end && !edge_set[i]) {
			edge_set[i] = true;
			index.push_back(i);
		}
	}
	if(start == end) {
		cout << "query : " << query[start].first << " " << query[start].second << endl;
		cout << "edge_set ";
		for(int i = 2; i <= N; ++i){
			cout << edge_set[i] << " ";
		}
		cout << endl;
		cout << "find_root : " << find_root(query[start].first) << " " << find_root(query[start].second) << endl;
		if(find_root(query[start].first) == find_root(query[start].second)) cout << "YES" << endl;
		else cout << "NO" << endl;
		return;
	}
	int M = (start + end)/2;
	solve(start, M);
	solve(M + 1, end);
	for(int i = 0; i < index.size(); ++i){
		edge_set[index[i]] = false;
	} 
}

int main(){
	cin >> N >> Q;
	parent.resize(N + 1);
	lifetime.resize(N + 1);
	query.resize(Q + 1);
	edge_set.resize(N + 1, false);

	parent[1] = 1;
	for(int i = 2; i <= N; ++i){
		cin >> parent[i];
	}
	int query_num = 0;
	for(int i = 1; i <= N - 1 + Q; ++i){
		int x; 
		cin >> x;
		if(x == 0){
			int b;
			cin >> b;
			lifetime[b] = query_num;	// edge from b to parent[b] is valid until 1 to query_num
		}else{
			query_num++;
			int c, d;
			cin >> c >> d;
			query[query_num] = make_pair(c, d);
		}
	}
	
	solve(1, Q);

	return 0;
}