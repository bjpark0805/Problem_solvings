// KOI 2016 middle #3
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<int> parent;
vector<int> original_parent;
vector<int> level;
vector< pair<int, int> > query;

int find_root(int node){
	if(parent[node] == node) return node;
	else return parent[node] = find_root(parent[node]);
}

void merge(int a, int b){
	a = find_root(a);
	b = find_root(b);
	if(a == b) return; 
	if(level[a] < level[b]) swap(a, b);
	parent[b] = a;
	if(level[a] == level[b]) level[a]++;
}

int main(){
	int N, Q;
	scanf("%d%d", &N, &Q);
	parent.resize(N + 1);
	original_parent.resize(N + 1);
	query.resize(N + Q);
	level.resize(N + 1, 1);

	for(int i = 1; i <= N; ++i){
		parent[i] = i;
	} 	

	original_parent[1] = 1;
	for(int i = 2; i <= N; ++i){
		scanf("%d", &original_parent[i]);
	}
	for(int i = 1; i <= N - 1 + Q; ++i){
		int x; 
		scanf("%d", &x);
		if(x == 0){
			int b;
			scanf("%d", &b);
			query[i] = make_pair(b, 0);
		}else{
			int c, d;
			scanf("%d%d", &c, &d);
			query[i] = make_pair(c, d);
		}
	}
	stack<bool> answer;
	for(int i = N + Q - 1; i >= 1; --i){
		int f = query[i].first;
		int s = query[i].second;

		if(s){
			if(find_root(f) == find_root(s)) answer.push(true);
			else answer.push(false);
		}else{
			// if(find_root(f) == find_root(s)) continue;
			merge(f, original_parent[f]);
		}
	}
	for(int i = 1; i <= Q; ++i){
		if(answer.top()) printf("YES\n");
		else printf("NO\n");
		answer.pop();
	}

	return 0;
}