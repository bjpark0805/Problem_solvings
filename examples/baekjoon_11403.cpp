// 44분
// directed graph에서 사이클을 돌지 않는 것에 대해 생각해볼 수 있었다. visited를 사용하자
// 생각해보니 좀 다른 방법: visited를 만들어서 모든 노드에서 dfs로 방문 가능한 곳을 전부 방문. 그담 각 i별 visited를 쭉 출력해주면 됨. 

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > graph;
vector<bool> visited;
int N;
bool dfs1(int start, int end){
	if(graph[start][end]) return true;
	if(visited[start]) return false;
	visited[start] = true;
	bool ans = false;
	for(int i = 0; i < N; ++i){
		if(graph[start][i]){
			ans |= dfs1(i, end);
		}
	}
	return ans;
}

void dfs2(int node){
	if(visited[node]) return;
	visited[node] = true;
	for(int i = 0; i < graph[node].size(); ++i){
		if(graph[node][i])
			dfs2(i);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	graph.resize(N);
	for(int i = 0; i < N; ++i){
		graph[i].resize(N);
		for(int j = 0; j < N; ++j){
			cin >> graph[i][j];
		}
	}
	// // method 1
	// for(int i = 0; i < N; ++i){
	// 	for(int j = 0; j < N; ++j){
	// 		visited.clear();
	// 		visited.resize(N, false);
	// 		cout << dfs(i, j) << " ";
	// 	}
	// 	cout << "\n";
	// }

	//method 2
	for(int i = 0; i < N; ++i){
		visited.clear();
		visited.resize(N, false);
		for(int j = 0; j < N; ++j){
			if(graph[i][j]) dfs2(j);
		}
		for(int j = 0; j < N; ++j){
			cout << visited[j] << " ";
		}
		cout << "\n"; 
	}
	return 0;
}