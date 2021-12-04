#include <iostream>
#include <vector>
int N, Q;
std::vector<int> breeding;
std::vector<int> b1, b2, b3;

void partial_sum(){
    int a, b;
    for(int i = 0; i < Q; ++i){
        std::cin >> a >> b;
        std::cout << b1[b] - b1[a - 1] << " " 
                  << b2[b] - b2[a - 1] << " "
                  << b3[b] - b3[a - 1] << "\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin.tie(NULL);

    std::cin >> N >> Q;
    breeding.resize(N, 0);
    b1.resize(N + 1, 0);
    b2.resize(N + 1, 0);
    b3.resize(N + 1, 0);
    for(int i = 0; i < N; ++i){
        std::cin >> breeding[i];
        if(breeding[i] == 1) b1[i + 1] += 1;
        if(breeding[i] == 2) b2[i + 1] += 1;
        if(breeding[i] == 3) b3[i + 1] += 1;
        b1[i + 1] += b1[i];
        b2[i + 1] += b2[i];
        b3[i + 1] += b3[i];
    }

    partial_sum();
    return 0;
}