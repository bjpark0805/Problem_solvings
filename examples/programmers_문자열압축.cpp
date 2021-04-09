#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string s) {
    int length = s.size();
    int answer = length;
    for(int l = 1; l <= length/2; ++l){
        // l: split 단위
        int ans = length;
        string prev = "";
        for(int i = 0; i < length/l; ++i){
            if(prev.size() == 0) prev = s.substr(i * l, l);
            else{
                int tmp = 1;
                while(prev == s.substr(i * l, l)){
                    tmp += 1;
                    i += 1;
                }
                if(tmp != 1) {
                    ans -= (tmp - 1) * l;
                    ans += to_string(tmp).size();
                }
                if(i < length/l) prev = s.substr(i * l, l);
            }
        }
        answer = min(ans, answer);
    }
    return answer;
}