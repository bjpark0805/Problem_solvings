// 이상한게 map size 구하는 방식을 하는게 훨씬 느려짐. 이유를 알고싶다.

#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v(n+1, 0);
    v[1] = 1;
    for(int i = 2; i * i <= n; ++i){
        if(v[i] == 1) continue;
        int j = 2;
        while(i * j <= n){
            v[i * j] = 1;
            j++;
        }
    }
    for(int i = 2; i <= n; ++i){
        if(v[i] == 0) answer++;
    }
    return answer;
}