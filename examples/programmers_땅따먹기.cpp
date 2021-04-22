#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int solution(vector<vector<int> > land)
{
    int c1 = land[0][0], c2 = land[0][1], c3 = land[0][2], c4 = land[0][3];
    for(int i = 1; i < land.size(); ++i){
        int tmp1 = max(c2, max(c3, c4)) + land[i][0];
        int tmp2 = max(c1, max(c3, c4)) + land[i][1];
        int tmp3 = max(c2, max(c4, c1)) + land[i][2];
        int tmp4 = max(c2, max(c3, c1)) + land[i][3];
        c1 = tmp1;
        c2 = tmp2;
        c3 = tmp3;
        c4 = tmp4;
    }
    int answer = max(max(max(c1, c2), c3), c4);

    return answer;
}