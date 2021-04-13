#include <iostream>
#include <vector>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, P;
	cin >> N >> M >> P;
	vector<int> graph(M + 1, 0);
	vector<bool> visited(M + 1, false);

	for(int i = 0; i < N; ++i){
		int in, out;
		cin >> out >> in;
		if(graph[in] == 0) graph[in] = out;
	}
	int cnt = 0;
	while(true){
		if(visited[P]) {cnt = -1; break;}
		if(graph[P] == 0) break;
		visited[P] = true;
		P = graph[P];
		cnt += 1;
	}

	cout << cnt << "\n";
	return 0;
}