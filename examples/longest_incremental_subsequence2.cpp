#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A;
vector<int> tree;
void init(int node, int start, int end){
	tree[node] = 0;
	if (start == end){
		return;
	}
	init(node*2, start, (start+end)/2);
	init(node*2 + 1, (start+end)/2 + 1, end);
}

int find(int node, int left, int right, int start, int end){
	if(left > end || right < start) return 0;
	else if(left <= start && right >= end) return tree[node];
	else{
		return max(
			find(2*node, left, right, start, (start + end)/2), 
			find(2*node + 1, left, right, (start+end)/2+1, end)
			);
	}
}

void update(int node, int index, int maxVal, int start, int end){
	if(index < start || index > end) return;
	if(start == end) {
		tree[node] = maxVal;
		return;
	}
	else{
		update(2*node, index, maxVal, start, (start + end)/2);
		update(2*node + 1, index, maxVal, (start+end)/2 + 1, end);
		tree[node] = max(tree[2*node], tree[2*node+1]);
	}
}

int main(){
	int N;
	cin >> N;

	A.resize(N + 1);
	for (int i = 1; i <= N; ++i){
		cin >> A[i];
	}
	int M = 1000000;  
	tree.resize(4*M + 3);
	init(1, 1, M);
	int ans = -1;
	for(int i = 1; i <= N; ++i){
		int index = A[i];
		int maxVal = find(1, 1, index - 1, 1, M) + 1;
		update(1, index, maxVal, 1, M);
		ans = max(ans, maxVal);
	}
	cout << ans;
	return 0;
}