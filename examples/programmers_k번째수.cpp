#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 약 10분
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i = 0; i < commands.size(); ++i){
        vector<int> command = commands[i];
        vector<int> sub_arr;
        for(int j = command[0] - 1; j < command[1]; ++j){
            sub_arr.push_back(array[j]);
        }
        sort(sub_arr.begin(), sub_arr.end());
        answer.push_back(sub_arr[command[2] - 1]);
    }
    return answer;
}