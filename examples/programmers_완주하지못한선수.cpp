#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> participant_map, completion_map;
    string answer = "";
    for(int i = 0; i < participant.size(); ++i){
        if(participant_map.find(participant[i]) != participant_map.end()) participant_map[participant[i]] += 1;
        else participant_map[participant[i]] = 1;
    }
    for(int i = 0; i < completion.size(); ++i){
        if(completion_map.find(completion[i]) != completion_map.end()) completion_map[completion[i]] += 1;
        else completion_map[completion[i]] = 1;
    }
    for(int i = 0; i < participant.size(); ++i){
        if(completion_map.find(participant[i]) == completion_map.end()) {answer = participant[i]; break;}
        else if(completion_map[participant[i]] != participant_map[participant[i]]) {answer = participant[i]; break;}
    }
    return answer;
}