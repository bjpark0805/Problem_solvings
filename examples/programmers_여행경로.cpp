// 50분정도 소요
// 모의고사로 푸니까 확실히 조바심이 듬
// dfs 완전탐색
// 딱히 복잡하진 않지만 문제 설계 자체가 익숙하지 않다보니 예상외로 까다롭게 느껴짐. 앞에 문제들에서 시간을 많이 벌어야겠다 생각

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int target = 1;
vector<bool> visited;
vector<string> fastest_answer;
bool compare(vector<string> a, vector<string> b){
	if(a[0] == b[0]){
		return a[1] < b[1];
	}
	else return a[0] < b[0];
}

void dfs(vector<vector<string> > &tickets, vector<string> &path){
	if(path.size() == target){
		if(fastest_answer.empty()) fastest_answer = path;
		return; 
	}
	for(int i = 0; i < tickets.size(); ++i){
		if(not visited[i] and tickets[i][0] == path.back()){
			visited[i] = true;
			path.push_back(tickets[i][1]);
			dfs(tickets, path);
			path.pop_back();
			visited[i] = false;
		}
	}
}
vector<string> solution(vector<vector<string>> tickets) {
	target += tickets.size();
	sort(tickets.begin(), tickets.end(), compare);
	visited.resize(tickets.size(), false);
	vector<string> path;
	for(int i = 0; i < tickets.size(); ++i){
		if(tickets[i][0] != "ICN") continue;
		visited[i] = true;
		path.push_back(tickets[i][0]);
		path.push_back(tickets[i][1]);
		dfs(tickets, path);
		path.pop_back();
		path.pop_back();
		visited[i] = false;
		if(!fastest_answer.empty()) break;
	}

    vector<string> answer = fastest_answer;
    return answer;
}

int main(){
	vector<vector<string> > tickets = {{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}};
	vector<string> answer = solution(tickets);
	for(int i = 0; i < answer.size(); ++i){
		cout << answer[i] << " ";
	}
	cout << endl;
	return 0;
} 