#include <string>
#include <vector>
#include <utility>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<pair<int, int> > stack;
    vector<int> answer;
    answer.resize(prices.size(), 0);
    int cnt = 0;
    for(int i = 0; i < prices.size() - 1; ++i){
        answer[i] = -cnt;
        if(stack.empty()) stack.push_back(make_pair(i, prices[i]));
        else{
            while(stack.back().second > prices[i]){
                answer[stack.back().first] += cnt;
                stack.pop_back();
            }
            stack.push_back(make_pair(i, prices[i]));
        }
        cnt += 1;
    }
    while(!stack.empty()){
        answer[stack.back().first] += cnt;
        stack.pop_back();
    }
    return answer;
}