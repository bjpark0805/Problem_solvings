#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

vector<int> graph;
vector<vector<int> > cache; // dp cache
vector<pair<int, int> > components; // component[i]: (ith cycle's person num, ith component person num)
vector<bool> visited;
vector<int> component;

int n, k, component_id = 0, max_component_n = -1;

void count_components_element(){
	for(int i = 1; i <= n; ++i){
		components[component[i]].second++;
	}
}
void dfs(int curr){
	visited[curr] = true;
	int next = graph[curr];
	if(visited[next]){
		if(component[next] == -1){
			component[next] = component_id;
			int cycle_cnt = 1;
			for(int temp = next; temp != curr; temp = graph[temp]) cycle_cnt++;
			components.push_back(make_pair(cycle_cnt, 0));
			component_id++;
		}
	}
	else dfs(next);
	component[curr] = component[next];
}

int dp(int component_n, int left){
	if(component_n == -1) return 0;
	if(left == 0) return 0;
	if(cache[component_n][left] != -1) return cache[component_n][left];
	if(components[component_n].first > left) return dp(component_n - 1, left);
	int maxv = dp(component_n - 1, left);
	for(int v = components[component_n].first; v <= components[component_n].second; ++v){
		if(v > left) break;
		maxv = max(maxv, dp(component_n - 1, left - v) + v);
	}
	return cache[component_n][left] = maxv;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	graph.resize(n + 1);
	visited.resize(n + 1, false);
	component.resize(n + 1, -1);

	for(int i = 1; i <= n; ++i){
		cin >> graph[i];
	}

	for(int i = 1; i <= n; ++i){
		if(not visited[i]) dfs(i);
	}

	count_components_element();

	cache.resize(components.size());
	for(auto &i: cache) i.resize(k + 1, -1);

	
	int c = components.size();
	cout << dp(c - 1, k) << "\n";

	return 0;
}