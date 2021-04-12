#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

// 50분
// 문제의 조건 그대로 따라가자 제발(서로 겹치는게 있으면 안된다는 조건 그대로)

vector<int> duplicate_e(vector<int> a, vector<int> b){
    vector<int>::iterator iter;
    vector<int>::iterator iter_b;
    vector<int> c = a;
    for(iter_b = b.begin(); iter_b != b.end(); iter_b++){
        for(iter = c.begin(); iter != c.end();){
            if(*iter == *iter_b){
                iter = c.erase(iter);
                break;
            }
            else
                iter++;
        }
    }
    return c;
}
int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> lost_temp(lost);
    lost = duplicate_e(lost, reserve);
    reserve = duplicate_e(reserve, lost_temp);
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    int answer = n - lost.size();
    int idx = 0;
    for(int l = 0; l < lost.size(); ++l){
        if(idx == reserve.size()) break; 
        for(int r = idx; r < reserve.size(); ++r){
            if(abs(lost[l] - reserve[r]) <= 1){
                answer += 1;
                idx = r + 1;
                break;
            }
            else if(lost[l] <= reserve[r]){
                idx = r;
                break;
            }
        }
    }
    return answer;
}