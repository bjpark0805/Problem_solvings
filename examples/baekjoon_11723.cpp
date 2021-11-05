#include <iostream>
#include <string>

void set_func(int M){
    int S = 0, all = (1 << 20) - 1;
    int n;
    std::string operand;
    for(int i = 0; i < M; ++i){
        std::string x;
        std::cin >> x;
        if(x == "all") {
            S = all;
        }
        else if(x == "empty"){
            S = 0;
        }
        else if(x == "add"){
            std::cin >> n;
            S |= (1 << n - 1);
        }
        else if(x == "remove"){
            std::cin >> n;
            S &= ~(1 << n - 1);
        }
        else if(x == "check"){
            std::cin >> n;
            int ans = 0;
            if(S & (1 << (n - 1))) ans = 1;
            std::cout << ans << "\n";
        }
        else if(x == "toggle"){
            std::cin >> n;
            S ^= (1 << n - 1);
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int M;
    std::cin >> M;

    set_func(M);
    return 0;
}