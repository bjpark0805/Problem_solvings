#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 7분
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int score1 = 0, score2 = 0, score3 = 0;
    int p1[5] = {1,2,3,4,5}, p2[8] = {2,1,2,3,2,4,2,5}, p3[10] = {3,3,1,1,2,2,4,4,5,5};
    int size1 = 5, size2 = 8, size3 = 10;
    for(int i = 0; i < answers.size(); ++i){
        if(p1[i%size1] == answers[i]) score1 += 1;
        if(p2[i%size2] == answers[i]) score2 += 1;
        if(p3[i%size3] == answers[i]) score3 += 1;
    }
    int max_v = max(score1, max(score2, score3));
    if(max_v == score1) answer.push_back(1);
    if(max_v == score2) answer.push_back(2);
    if(max_v == score3) answer.push_back(3);
    
    return answer;
}