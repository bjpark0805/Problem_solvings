// KOI 2016 middle #3
// This version is easy, but caught in time limit

#include <stdio.h>
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
	scanf("%d%d", &N, &Q);
	parent.resize(N + 1);

	parent[1] = 1;
	for(int i = 2; i <= N; ++i){
		scanf("%d",&parent[i]);
	}
	int query_num = 1;
	for(int i = 1; i <= N - 1 + Q; ++i){
		int x; 
		scanf("%d", &x);
		if(x == 0){
			int b;
			scanf("%d", &b);
			parent[b] = b;
		}else{
			int c, d;
			scanf("%d%d", &c, &d);
			if(find_root(c) == find_root(d)) printf("YES\n");
			else printf("NO\n");
		}
	}

	return 0;
}