#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

bool compare(string a, string b){
	return a.size() < b.size();
}
vector<int> solution(string s) {
    vector<int> answer;
	s = s.substr(0, s.size() - 1);
	istringstream ss(s);
	string stringBuffer;
	vector<string> splited_s;
	while(getline(ss, stringBuffer, '}')){
		splited_s.push_back(stringBuffer.substr(2, stringBuffer.size() - 2));
	}
	sort(splited_s.begin(), splited_s.end(), compare);
	for(int i = 0; i < splited_s.size(); ++i){
		vector<int> temp;
		istringstream sss(splited_s[i]);
		while(getline(sss, stringBuffer, ',')){
			temp.push_back(stoi(stringBuffer));
		}
		for(int j = 0; j < temp.size(); ++j){
			if(find(answer.begin(), answer.end(), temp[j]) == answer.end()){
				answer.push_back(temp[j]);
				break;
			}
		}		
	}
    return answer;
}

int main(){
	string s = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
	// string s = "{{1,2,3},{2,1},{1,2,4,3},{2}}";
	vector<int> answer = solution(s);
	for(int i = 0; i < answer.size(); ++i){
		cout << answer[i] << " ";
	}
	cout << endl;
	return 0;
}