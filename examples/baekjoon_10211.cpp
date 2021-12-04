#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
int N;
std::vector<int> X, c_sum;

void max_partial_sum(){
    int max_v = -INT_MAX;
    for(int i = 1; i <= N; ++i){
        for(int j = 0; j < i; ++j){
            max_v = std::max(max_v, c_sum[i] - c_sum[j]);
        }
    }
    std::cout << max_v << "\n";
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int T;
    std::cin >> T;
    for(int t = 0; t < T; ++t){
        std::cin >> N;
        X.clear();
        c_sum.clear();
        X.resize(N);
        c_sum.resize(N + 1);
        for(int i = 0; i < N; ++i){
            std::cin >> X[i];
            c_sum[i + 1] = c_sum[i] + X[i];
        }
        max_partial_sum();
    }
    return 0;
}