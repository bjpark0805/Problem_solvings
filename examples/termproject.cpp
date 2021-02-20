#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector <int> students;
vector <int> status;
int team;

void termproject(int j){
	vector<int> teamlist;
	teamlist.resize(0);
	int present = j;
	teamlist.push_back(present);
	status[present]++;
	while(true){
		int next = students[present];
		if(status[next] == -1){ // 한번도 방문 안한경우
			status[next]++;
			teamlist.push_back(next);
			present = next;
		} 
		else if(status[next] == 0) // 한번 방문한 애를 또 방문했으니까 사이클이 만들어진 경우, 여기서부터 사이클 따라서 한번 더 돌면서 status 2로 바꾸기, 나미전 0
		{
			int change = 2;
			while(!teamlist.empty()){
				status[teamlist.back()] = change;
				if(teamlist.back() == next) change = 1;
				teamlist.pop_back();
			}
			break;
		}
		else if(status[next] >= 1) // 여기 들어가게 되면 망한 케이스
		{
			while(!teamlist.empty()){
				status[teamlist.back()] = 1;
				teamlist.pop_back();
			}
			break;
		}
	}
}

int main(){
	int T;
	cin >> T;
	for(int i = 1; i <= T; ++i){
		int n, count = 0;
		cin >> n;
		students.resize(n + 1);
		status.resize(n + 1);
		fill(status.begin(), status.end(), -1);
		team = 1;
		for(int j = 1; j <= n; ++j){
			cin >> students[j];
		} 
		for(int j = 1; j <= n; ++j){
			if(status[j] == -1) termproject(j);
		}
		for(int j = 1; j <= n; ++j){
			if(status[j] < 2) count++;
		}
		// cout << endl;
		cout << count << endl;
	}
	return 0;
}