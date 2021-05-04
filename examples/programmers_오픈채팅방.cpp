#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

vector<string> split(string target){
    vector<string> ans;
    size_t previous = 0, current;
    string delimiter = " ";
    current = target.find(delimiter);
    while(current != string::npos){
        ans.push_back(target.substr(previous, current - previous));
        previous = current + delimiter.size();
        current = target.find(delimiter, previous);
    }
    ans.push_back(target.substr(previous, current - previous));
    return ans;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<bool, string> > open_chat;
    map<string, string> id_to_nickname;
    for(vector<string>::iterator iter = record.begin(); iter != record.end(); ++iter){
        vector<string> split_record = split(*iter);
        if(split_record[0] == "Enter"){
            id_to_nickname[split_record[1]] = split_record[2];
            open_chat.push_back(make_pair(false, split_record[1]));
        }
        else if(split_record[0] == "Leave"){
            open_chat.push_back(make_pair(true, split_record[1]));
        }
        else{
            id_to_nickname[split_record[1]] = split_record[2];
        }
    }
    
    for(vector<pair<bool, string> >::iterator iter = open_chat.begin(); iter != open_chat.end(); ++iter){
        if(iter->first){ // leave
            string s = id_to_nickname[iter->second] + "님이 나갔습니다.";
            answer.push_back(s);
        }
        else{ // enter
            string s = id_to_nickname[iter->second] + "님이 들어왔습니다.";
            answer.push_back(s);
        }
    }
    return answer;
}