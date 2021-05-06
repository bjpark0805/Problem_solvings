#include <string>
#include <map>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;

map<string, int> make_map(string s){
    map<string, int> m;
    for(int i = 0; i < s.size() - 1; ++i){
        string sub_s = s.substr(i, 2);
        if(!((sub_s[0] >= 65 and sub_s[0] <= 90) or (sub_s[0] >= 97 and sub_s[0] <= 122))) continue;
        if(!((sub_s[1] >= 65 and sub_s[1] <= 90) or (sub_s[1] >= 97 and sub_s[1] <= 122))) continue;
        transform(sub_s.begin(), sub_s.end(), sub_s.begin(), ::tolower);
        if(m.find(sub_s) == m.end()) m[sub_s] = 1;
        else m[sub_s]++;
    }
    return m;
}

pair<int, int> jacard_sim(map<string, int> m1, map<string, int> m2){
    int inner = 0, outer = 0;
    for(map<string, int>::iterator iter = m1.begin(); iter != m1.end(); ++iter){
        if(m2.find(iter->first) == m2.end()) outer += iter->second;
        else{
            outer += max(iter->second, m2[iter->first]);
            inner += min(iter->second, m2[iter->first]);
        }
    }
    for(map<string, int>::iterator iter = m2.begin(); iter != m2.end(); ++iter){
        if(m1.find(iter->first) == m1.end()) outer += iter->second;
    }
    if(outer == 0){
        inner = 1;
        outer = 1;
    }
    return make_pair(inner, outer);
}

int solution(string str1, string str2) {
    int answer = 0;
    map<string, int> m1 = make_map(str1);
    map<string, int> m2 = make_map(str2);
    
    pair<int, int> p1 = jacard_sim(m1, m2);
    answer = p1.first * 65536 / p1.second;
    return answer;
}