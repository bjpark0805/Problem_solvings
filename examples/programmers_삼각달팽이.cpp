#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    if(n == 1) {answer.push_back(1); return answer;}
    vector<vector<int> > arr;
    arr.resize(n);
    for(int i = 0; i < n; ++i){
        arr[i].resize(i + 1, 0);
    }
    int cnt = 1, d = 0, r = 0, c = 0, curr = 1;
    arr[r][c] = cnt;
    cnt += 1;
    while(true){
        int next_r = r, next_c = c;
        if(d == 0){
            next_r += 1;
        }
        else if(d == 1){
            next_c += 1;
        }
        else{ // d == 2
            next_r -= 1;
            next_c -= 1;
        }
        if(next_r < 0 or next_r >= n or next_c < 0 or next_c > next_r) {curr = 0; d = (d + 1)%3;}
        else if(not curr and arr[next_r][next_c]) break;
        else if(arr[next_r][next_c]) {curr = 0; d = (d + 1)%3;}
        else{
            arr[next_r][next_c] = cnt;
            cnt += 1;
            r = next_r;
            c = next_c;
            curr += 1;
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= i; ++j){
            answer.push_back(arr[i][j]);
        }
    }
    
    return answer;
}