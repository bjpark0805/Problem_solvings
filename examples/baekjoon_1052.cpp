#include <iostream>

int count_bottle(int N){
    int digit = 1, cnt = 0;
    while(digit <= N){
        if(digit & N) cnt += 1;
        digit <<= 1;
    }
    return cnt;   
}

void water_bottle(int N, int K){
    for(int i = 0; i <= N; ++i){
        if(count_bottle(N + i) <= K) {
            std::cout << i << "\n";
            return;
        }
    }
    std::cout << -1 << "\n";
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, K;
    std::cin >> N >> K;
    water_bottle(N, K);
    return 0;
}