// 14분 소요
// dfs, bfs 차이애 대한 개념문제

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int> > graph;
vector<bool> visited;
int N, V;
void bfs(){
	visited.clear();
	visited.resize(N+1, false);
	queue<int> q;
	q.push(V);
	visited[V] = true;
	while(!q.empty()){
		int curr = q.front();
		cout << curr << " ";
		q.pop();
		for(int i = 0; i < graph[curr].size(); ++i){
			if(not visited[graph[curr][i]]){
				q.push(graph[curr][i]);
				visited[graph[curr][i]] = true;
			}
		}
	}
}

void dfs(int curr){
	visited[curr] = true;
	cout << curr << " ";	
	for(int i = 0; i < graph[curr].size(); ++i){
		if(not visited[graph[curr][i]]){
			dfs(graph[curr][i]);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int M;
	cin >> N >> M >> V;
	graph.resize(N+1);
	for(int i = 0; i < M; ++i){
		int s,e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	for(int i = 1; i < N + 1; ++i){
		sort(graph[i].begin(), graph[i].end());
	}
	visited.resize(N+1, false);
	dfs(V);
	cout << "\n";
	bfs();
	cout << "\n";
	return 0;
}