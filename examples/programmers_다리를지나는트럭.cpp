#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<pair<int, int> > q;
    int time = 1;
    int current_weight = 0;
    q.push(make_pair(time, truck_weights[0])); 
    current_weight += truck_weights[0];
    for(int i = 1; i < truck_weights.size(); ++i){
        time += 1;
        if(q.front().first + bridge_length <= time) {
            current_weight -= q.front().second; 
            q.pop();
        }
        while(current_weight + truck_weights[i] > weight){
            time = q.front().first + bridge_length;
            current_weight -= q.front().second;
            q.pop();
        }
        q.push(make_pair(time, truck_weights[i]));
        current_weight += truck_weights[i];
    }
    while(q.size() > 1) q.pop();
    time = q.front().first + bridge_length;
    return answer = time;
}