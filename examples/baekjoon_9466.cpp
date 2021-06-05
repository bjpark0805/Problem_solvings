#include <iostream>
#include <vector>

using namespace std;

vector<int> students;
vector<bool> visited;
vector<bool> finished;
int cnt;

void dfs(int curr){
	// cout << curr << endl;
	visited[curr] = true;
	int next = students[curr];
	if(visited[next]){
		if(!finished[next]){
			for(int i = next; i != curr; i = students[i]) cnt++;
			cnt++;
		}
	}
	else dfs(next);
	finished[curr] = true;
}

void termproject(){
	int n;
	cnt = 0;
	cin >> n;
	students.clear();
	visited.clear();
	finished.clear();

	students.resize(n);
	visited.resize(n, false);
	finished.resize(n, false);

	for(int i = 0; i < n; ++i){
		cin >> students[i];
		students[i]--;
	}

	for(int i = 0; i < n; ++i){
		if(not visited[i]) dfs(i);
	}

	cout << n - cnt << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for(int i = 0; i < T; ++i){
		termproject();
	}

	return 0;
}