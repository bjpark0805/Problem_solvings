#include <iostream>
#include <vector>
std::vector<std::vector<int> > board;
std::vector<std::vector<int> > cumul_board;

void partial_sum(int N, int M){
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            std::cin >> board[i][j];
            cumul_board[i + 1][j + 1] = cumul_board[i + 1][j] + 
                                        cumul_board[i][j + 1] -
                                        cumul_board[i][j] +
                                        board[i][j];
        }
    }
    int x1, y1, x2, y2;
    for(int i = 0; i < M; ++i){
        std::cin >> x1 >> y1 >> x2 >> y2;
        std::cout << cumul_board[x2][y2] - cumul_board[x2][y1-1] - cumul_board[x1-1][y2] + cumul_board[x1-1][y1-1] << "\n";
    }
}
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;
    std::cin >> N >> M;
    board.resize(N, std::vector<int>(N));
    cumul_board.resize(N + 1,std::vector<int>(N + 1, 0));
    partial_sum(N, M);
    return 0;
}