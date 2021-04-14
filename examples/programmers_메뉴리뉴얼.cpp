// 80분 (1시간 20분)
// 시뮬레이션 
// 구현이 좀 귀찮긴 했는데 게다가 처음 프로그래머스에서 로컬로 가져와서 해서 더 익숙하지 않았던듯
// 근데 로컬로 하는 것도 나쁘진 않은듯

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
vector<vector<string> > menu;
vector<vector<int> > counts;
vector<int> max_v;

void dfs(string order, string curr, int target_size, int idx){
    if(curr.size() + order.size() < target_size) return;
	if(curr.size() == target_size){
		bool exist = false;
		for(int i = 0; i < menu[idx].size(); ++i){
			if(menu[idx][i] == curr){
				counts[idx][i] += 1;
				max_v[idx] = max(max_v[idx], counts[idx][i]);
				exist = true;
				break;
			}
		}
		if(not exist){
			menu[idx].push_back(curr);
			counts[idx].push_back(1);
			max_v[idx] = max(max_v[idx], 1);
		}
        return;
	}
    if(order.size() == 0) return;
	string new_order = order.substr(1, order.size() - 1);
	dfs(new_order, curr, target_size, idx);
	dfs(new_order, curr + order[0], target_size, idx);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    menu.resize(course.size());
    counts.resize(course.size());
    max_v.resize(course.size());
    for(int i = 0; i < orders.size(); ++i){
    	for(int j = 0; j < course.size(); ++j){
    		string order = orders[i];
    		sort(order.begin(), order.end());
    		if(order.size() >= course[j]) dfs(order, "", course[j], j);
    	}
    }
    
    for(int i = 0; i < counts.size(); ++i){
    	for(int j = 0; j < counts[i].size(); ++j){
    		if(counts[i][j] == max_v[i] and max_v[i] >= 2) answer.push_back(menu[i][j]);
    	}
    }

    sort(answer.begin(), answer.end());
    return answer;
}