#include <iostream>
#include <vector>
#include <string>
#include <map>

std::string S;
int Q;

std::map<char, std::vector<int> > alphabet_p_sum;

void partial_sum(){
    char alphabet;
    int l, r;
    for(int i = 0; i < Q; ++i){
        std::cin >> alphabet >> l >> r;
        std::cout << alphabet_p_sum[alphabet][r + 1] - alphabet_p_sum[alphabet][l] << "\n";
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin >> S;
    std::cin >> Q;
    int N = S.size();
    for(int i = 0; i < 26; ++i){
        char alphabet = 'a' + i;
        alphabet_p_sum[alphabet] = std::vector<int>(N + 1, 0);
    }
    for(int i = 0; i < N; ++i){
        alphabet_p_sum[S[i]][i + 1] += 1;
        for(int a = 0; a < 26; ++a){
            alphabet_p_sum['a' + a][i + 1] += alphabet_p_sum['a' + a][i];
        }
    }
    partial_sum();
    return 0;
}