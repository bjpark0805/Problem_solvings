#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int nutrients[16][6];
int N;
int mp,mf,ms,mv;
int min_cost = INT_MAX;
vector<int> answer;

void find_material(vector<int> current, int cp, int cf, int cs, int cv, int cost, int n){
	if(cp >= mp && cf >= mf && cs >= ms && cv >= mv && cost < min_cost){
		min_cost = cost;
		answer = current;	
		return;
	}
	
	if(n > N) return;
	else{
		for(int i = n; i <= N; ++i){
			vector<int> temp;
			temp = current;
			temp.push_back(i);
			find_material(temp, cp + nutrients[i][1], cf + nutrients[i][2], cs + nutrients[i][3], cv + nutrients[i][4], cost + nutrients[i][5], i + 1);
		}
	}
}

int main(){
	cin >> N;
	cin >> mp >> mf >> ms >> mv;

	for(int i = 1; i <= N; ++i){
		cin >> nutrients[i][1] >> nutrients[i][2] >> nutrients[i][3] >> nutrients[i][4] >> nutrients[i][5];
	}
	vector<int> v;
	v.resize(0);

	find_material(v, 0, 0, 0, 0, 0, 1);

	if(answer.size() == 0) cout << -1 << endl;
	else{
		cout << min_cost << endl;
		for(int i = 0; i < answer.size(); ++i){
			cout << answer[i] << " ";
		}
		cout << endl;
	}
	return 0;
}