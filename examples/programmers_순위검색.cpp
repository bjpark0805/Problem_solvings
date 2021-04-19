// 3시간 넘게 소요
// 시뮬레이션, 카카오 기출인데 아주 극혐. 시간 복잡도 맞추기가 매우 어렵다
// map, 이분탐색, 문자열 다 써야됨.

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    map<string, vector<int> > info_map;
    for(int j = 0; j < info.size(); ++j){
		string applicant = info[j];
		string info_key = "";
		// each applicant
		size_t previous = 0, current;
		current = applicant.find(' ');
		while(current != string::npos){
			info_key += applicant.substr(previous, current - previous);
			previous = current + 1;
			current = applicant.find(' ', previous);
		}
		int score = stoi(applicant.substr(previous, current - previous));
		if(info_map.find(info_key) != info_map.end()){
			info_map[info_key].push_back(score);
		}
		else {
			vector<int> temp;
			temp.push_back(score);
			info_map[info_key] = temp;
		}
	}

	map<string, vector<int> >::iterator iter;
	for(iter = info_map.begin(); iter != info_map.end(); ++iter){
		sort(iter->second.begin(), iter->second.end());
	}
    for(int i = 0; i < query.size(); ++i){
    	string s = query[i];
    	size_t previous = 0, current;
    	current = s.find(" and ");
    	vector<string> query_str;
    	int idx = 0;
    	while(current != string::npos){
    		string temp = s.substr(previous, current - previous);
    		if(query_str.empty()){
    			if(temp == "-"){
    				query_str.push_back("cpp");
    				query_str.push_back("java");
    				query_str.push_back("python");
    			}
    			else query_str.push_back(temp);
    		}
    		else{
    			int qsize = query_str.size();
    			for(int j = 0; j < qsize; ++j){
    				if(temp == "-"){
    					if(idx == 1){
	    					query_str.push_back(query_str[j] + "frontend");
    						query_str[j] += "backend";
    					}
    					else if(idx == 2){
	    					query_str.push_back(query_str[j] + "senior");
    						query_str[j] += "junior";
    					}
	    			}
	    			else query_str[j] += temp;
	    		}
    		}
    		previous = current + 5;
    		current = s.find(" and ", previous);
    		idx++;
    	}
    	current = s.find(' ', previous);
    	string food = s.substr(previous, current - previous);
    	int qsize = query_str.size();
    	for(int j = 0; j < qsize; ++j){
    		if(food == "-"){
    			query_str.push_back(query_str[j] + "chicken");
    			query_str[j] += "pizza";
    		}
    		else query_str[j] += food;
    	}
    	int score_limit = stoi(s.substr(current + 1, string::npos - current - 1));
    	
    	int ans = 0;
    	for(int j = 0; j < query_str.size(); ++j){
    		if(info_map.find(query_str[j]) == info_map.end()) continue;
    		vector<int> peoples = info_map[query_str[j]];
    		if(peoples[peoples.size() - 1] < score_limit) continue;
    		if(peoples[0] >= score_limit){
    			ans += peoples.size();
    			continue;
    		}
    		int start = 0, end = peoples.size();
    		while(start + 1 < end){
    			int mid = (start + end)/2;
    			if(peoples[mid] >= score_limit) end = mid;
    			else start = mid;
    		}
    		if(end == peoples.size()) end = 0;
    		ans += peoples.size() - end;
    	}
    	answer.push_back(ans);
    }
    return answer;
}

int main(){
	vector<string> info = {
		"java backend junior pizza 150",
		"python frontend senior chicken 210",
		"python frontend senior chicken 150",
		"cpp backend senior pizza 260",
		"java backend junior chicken 80",
		"python backend senior chicken 50"
	};
	vector<string> query = {
		"java and backend and junior and pizza 100",
		"python and frontend and senior and chicken 200",
		"cpp and - and senior and pizza 250",
		"- and backend and senior and - 150",
		"- and - and - and chicken 100",
		"- and - and - and - 150"
	};
	vector<int> answer = solution(info, query);
	for(int i = 0; i < answer.size(); ++i){
		cout << answer[i] << " ";
	}
	cout << endl;
	return 0;
}