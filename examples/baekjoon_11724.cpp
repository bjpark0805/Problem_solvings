#include <iostream>
#include <vector>

using namespace std;

int N, M, cnt;
vector<vector<int> > edges;
vector<bool> visited;

void dfs(int node){
	for(int i = 0; i < edges[node].size(); ++i){
		if(not visited[edges[node][i]]){
			visited[edges[node][i]] = true;
			dfs(edges[node][i]);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	edges.resize(N + 1);
	visited.resize(N + 1, false);
	int u, v;
	for(int i = 0; i < M; ++i){
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	for(int i = 1; i <= N; ++i){
		if(not visited[i]){
			visited[i] = true;
			cnt += 1;
			dfs(i);
		}
	}
	
	cout << cnt << "\n";
	return 0;
}