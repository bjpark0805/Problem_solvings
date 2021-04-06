#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int row_size = board.size();
    vector<int> stack(0);
    for(int i = 0; i < moves.size(); ++i){
        int c = moves[i] - 1;
        for(int j = 0; j < row_size; ++j){
            if(board[j][c] == 0) continue;
            if(stack.empty()) {stack.push_back(board[j][c]); board[j][c] = 0;}
            else if(stack.back() == board[j][c]){
                stack.pop_back();
                answer += 2;
                board[j][c] = 0;
            }
            else {stack.push_back(board[j][c]); board[j][c] = 0;}
            break;
        }
    }
    return answer;
}