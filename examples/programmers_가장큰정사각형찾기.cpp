#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

// 15분
/*
DP, 정사각형 혹은 직사각형 문제

처음보는 유형의 문제라 못풀었음.
반드시 기억해두기(bottom up 2차원 dp)
비슷한 예로 직사각형 문제도 있으면 풀어보자

*/
int solution(vector<vector<int>> board)
{
    int answer = 0;
    for(int i = 0; i < board.size(); ++i){
        for(int j = 0; j < board[i].size(); ++j){
            if(not board[i][j] or i == 0 or j == 0) {answer = max(answer, board[i][j]); continue;}
            board[i][j] = min(board[i-1][j-1], min(board[i-1][j], board[i][j-1])) + 1;
            answer = max(board[i][j], answer);
        }
    }
    
    return answer * answer;
}