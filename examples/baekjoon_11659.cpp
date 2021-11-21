#include <iostream>
#include <vector>
std::vector<int> v;
std::vector<int> cumul_sum;

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int N, M;
    std::cin >> N >> M;
    v.resize(N, 0);
    cumul_sum.resize(N + 1, 0);
    for(int i = 0; i < N; ++i){
        std::cin >> v[i];
        cumul_sum[i + 1] = cumul_sum[i] + v[i];
    }
    int i, j;
    for(int m = 0; m < M; ++m){
        std::cin >> i >> j;
        std::cout << cumul_sum[j] - cumul_sum[i - 1] << "\n";
    }
    return 0;
}