#include <iostream>
#include <vector>

int N, Q;
std::vector<int> a;
std::vector<int> p_a;
std::vector<int> dist;

void partial_sum(){
    int qi, qj;
    for(int i = 0; i < Q; ++i){
        std::cin >> qi >> qj;
        if(qj <= qi) std::cout << "0\n";
        else std::cout << p_a[qj - 1] - p_a[qi - 1] << "\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::cin >> N >> Q;
    a.resize(N);
    dist.resize(N + 1, 0);
    p_a.resize(N + 1, 0);
    for(int i = 0; i < N; ++i){
        std::cin >> a[i];
        if(i > 0) {
            dist[i] = std::abs(a[i] - a[i - 1]); 
            p_a[i] = p_a[i - 1] + dist[i];
        }
    }
    partial_sum();
    return 0;
}