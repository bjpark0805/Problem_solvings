//8분 소요
// hash(map) 사용하는 연습문제
// iterator사용하는 법을 잘 익혀두자.

#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int solution(vector<vector<string> > clothes) {
    int answer = 1;
    map<string, int> m;
    for(int i = 0; i < clothes.size(); ++i){
    	if(m.find(clothes[i][1]) != m.end()) m[clothes[i][1]] += 1;
    	else m[clothes[i][1]] = 1;
    }

    map<string, int>::iterator iter;
    for(iter = m.begin(); iter != m.end(); ++iter){
    	answer *= iter->second + 1;
    }
    answer -= 1;
    return answer;
}

int main(){
	vector<vector<string> > clothes = {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};
	cout << solution(clothes) << endl;
	return 0;
}