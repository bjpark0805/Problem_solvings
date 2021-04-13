// 약 25분
// 한번에 성공
// 시뮬레이션 문제인데 역시 시뮬레이션은 그냥 아무 조건변화없이 따라가는게 맞다.

#include <string>
#include <vector>

using namespace std;

bool right_string(string s){
    int cnt = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '(') cnt += 1;
        else cnt -= 1;
        if(cnt < 0) break;
    }
    if(cnt == 0) return true;
    else return false;
}

bool balanced_string(string s){
    int cnt = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '(') cnt += 1;
        else cnt -= 1;
    }
    if(cnt == 0) return true;
    else return false;
}

string recSol(string s){
    if(s.size() == 0) return "";
    string temp = "(";
    for(int i = 2; i <= s.size(); i = i + 2){
        string u = s.substr(0, i), v = s.substr(i, s.size() - i);
        if(not balanced_string(u)) continue;
        if(right_string(u)) return u + recSol(v);
        temp += recSol(v);
        temp += ')';
        for(int i = 1; i < u.size() - 1; ++i){
            if(u[i] == '(') temp += ')';
            else temp += '(';
        }
        
        break;
    }
    return temp;

}
string solution(string p) {
    string answer = recSol(p);
    return answer;
}