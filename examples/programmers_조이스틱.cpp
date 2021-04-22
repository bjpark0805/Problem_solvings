#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int N, cnt = 0, total_cnt = 0;
int answer = 10000000;
vector<bool> prev_state;

int updown(char a, char b){
    return min(a - b, ('Z' - a) + 1);
}
void dfs(int idx, string name){
    if(cnt == N){
        answer = min(answer, total_cnt);
        return;
    }
    int idx1, idx2, i, j;
    for(i = 1; i < N; ++i){
        idx1 = (idx + i)%N;
        if(not prev_state[idx1]) break;
    }
    for(j = 1; j < N; ++j){
        idx2 = (idx - j + N)%N;
        if(not prev_state[idx2]) break;
    }
    
    prev_state[idx1] = true;
    cnt++;
    total_cnt += i + updown(name[idx1], 'A');
    dfs(idx1, name);
    cnt--;
    total_cnt -= i + updown(name[idx1], 'A');
    prev_state[idx1] = false;
    
    prev_state[idx2] = true;
    cnt++;
    total_cnt += j + updown(name[idx2], 'A');
    dfs(idx2, name);
    cnt--;
    total_cnt -= j + updown(name[idx2], 'A');
    prev_state[idx2] = false;
    
}
int solution(string name) {
    N = name.size();
    prev_state.resize(N, false);
    prev_state[0] = true;
    cnt++;
    total_cnt += updown(name[0], 'A');
    for(int i = 1; i < N; ++i){
        if(name[i] == 'A') {
            prev_state[i] = true;
            cnt++;
        }
    }
    dfs(0, name);
    return answer;
}