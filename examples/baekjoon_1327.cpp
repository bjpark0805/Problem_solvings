#include <iostream>
#include <queue>

int N, K, ans = 0, curr = 0;

int convert_num(int original, int idx){
    int answer = original;
    int sum_of_side = 2*idx - K + 1;
    for(int i = idx - K + 1; i <= idx; ++i){
        int sub = (original & (7 << (3 * i)));
        answer -= sub;
        int add;
        if(sum_of_side - 2 * i >= 0){
            add = (sub << (3 * (sum_of_side - 2 * i)));
        }
        else{
            add = (sub >> (3 * (-sum_of_side + 2 * i)));
        }
        answer += add;
    }
    return answer;
}

int bfs(){
    if(ans == curr) return 0;
    std::vector<bool> visited(1<<(3*N), false);
    std::queue<int> q;
    q.push(curr);
    visited[curr] = true;
    int level = 1;
    while(!q.empty()){
        int qsize = q.size();
        for(int i = 0; i < qsize; ++i){
            int qfront = q.front();
            q.pop();
            for(int k = K - 1; k < N; ++k){
                int converted_qfront = convert_num(qfront, k);
                if(converted_qfront == ans) return level;
                if(not visited[converted_qfront]){
                    q.push(converted_qfront);
                    visited[converted_qfront] = true;
                }
            }
        }
        level++;
    }
    return -1;
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::cin >> N >> K;

    for(int i = 0; i < N; ++i){
        int tmp;
        std::cin >> tmp;
        ans += i;
        curr += tmp - 1;
        if(i < N - 1){
            ans <<= 3;
            curr <<= 3;
        }
    }
    std::cout << bfs() << "\n";
    return 0;
}
