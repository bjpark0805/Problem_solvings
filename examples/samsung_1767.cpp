#include<iostream>
#include <vector>
#include <utility>
#include <algorithm>
 
using namespace std;
int N, cnt, length;
vector<vector<int> > maxinos;
vector<pair<int, int> > cores;
 
void max_line(int core_cnt, int length_sum){
    if(cores.empty()){
        if(core_cnt > cnt) {cnt = core_cnt; length = length_sum;}
        else if(core_cnt == cnt) length = min(length, length_sum);
        return;
    }
     
    pair<int, int> core = cores.back();
    cores.pop_back();
    int r = core.first, c = core.second;
    if(r == 0 || c == 0 || r == N- 1 || c == N - 1) {
        max_line(core_cnt + 1, length_sum); 
        cores.push_back(core); 
        return;
    }
     
    max_line(core_cnt, length_sum);
     
    int r_diff, c_diff;
    for(int d = 0; d < 4; ++d){
        r_diff = 0; c_diff = 0;
        if(d % 2){
            r_diff = d - 2;
        }
        else{
            c_diff = d - 1;
        }
        bool success = true;
        int i;
        for(i = 1; i < N; ++i){
            int new_r = r + i * r_diff, new_c = c + i * c_diff;
            if(new_r < 0 || new_r >= N || new_c < 0 || new_c >= N) break;
            else if(maxinos[new_r][new_c]) {success = false; break;}
            else maxinos[new_r][new_c] = 1;
        }
        if(success) max_line(core_cnt + 1, length_sum + i - 1);
        
        for(int j = 1; j < i; ++j){
            int new_r = r + j * r_diff, new_c = c + j * c_diff;
            maxinos[new_r][new_c] = 0;
        }
    }
    cores.push_back(core);
    return;
}
 
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        cin >> N; 
        cnt = 0;
        length = 0;
        maxinos.resize(0);
        maxinos.resize(N);
        for(int i = 0; i < N; ++i){
            maxinos[i].resize(N, 0);
        }
        cores.resize(0);
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                cin >> maxinos[i][j];
                if(maxinos[i][j] == 1) cores.push_back(make_pair(i, j));
            }
        }
        max_line(0, 0);
        cout << "#" << test_case << " " << length << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}