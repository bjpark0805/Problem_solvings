#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void bfs(){
	int n,m,start,end;
	cin >> n >> start >> end >> m;
	vector<vector<int> > graph(n + 1);
	vector<bool> visited(n + 1,false);
	queue<int> q;
	
	for(int i = 0; i < m; ++i){
		int s, e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	q.push(start);
	visited[start] = true;
	int level = 1;
	while(!q.empty()){
		int qsize = q.size();
		for(int i = 0; i < qsize; ++i){
			int node = q.front();
			q.pop();
			for(int j = 0; j < graph[node].size(); ++j){
				if(graph[node][j] == end){
					cout << level << "\n";
					return;
				}
				if(not visited[graph[node][j]]){
					visited[graph[node][j]] = true;
					q.push(graph[node][j]);
				}
			}
		}
		level++;
	}
	cout << "-1" << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	bfs();
	return 0;
}