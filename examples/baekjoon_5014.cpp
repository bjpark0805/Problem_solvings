#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(){
	int F,S,G,U,D;
	cin >> F >> S >> G >> U >> D;
	if(S == G){
		cout << 0 << "\n";
		return;
	}
	S--;
	G--;
	vector<bool> visited(F, false);
	queue<int> q;
	q.push(S);
	int level = 1;
	while(!q.empty()){
		int qsize = q.size();
		for(int i = 0; i < qsize; ++i){
			int curr = q.front();
			q.pop();
			if(curr + U == G or curr - D == G){
				cout << level << "\n";
				return;
			}
			if(curr + U < F and not visited[curr + U]){
				q.push(curr + U);
				visited[curr + U] = true;
			}
			if(curr - D >= 0 and not visited[curr - D]){
				q.push(curr - D);
				visited[curr - D] = true;
			}
		}
		level++;
	}
	cout << "use the stairs\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bfs();
	return 0;
}