// 총 50분, 문제 푸는데 대략 20분, 디버깅 30분
// 첫번째 프로그래머스에서 자주 나타나는 문제: 전체적인 ide 폼이 익숙하지 않아서 그런지 return 값을 안써서 
// 시간초과걸리는 경우가 있음. 
// 둘째, 뭔가 느낌이 이상하긴 한데 조건문 걸 때 not a % b이게 안먹혀서 이거 찾는데 한참 걸림. 이해가 안되지만 
// 안전빵으로 가는게 나을수도있을듯



#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <iostream>
using namespace std;

vector<bool> check;
set<int> ans;

bool prime_check(int a){
    if(a == 1) return false;
    bool tmp = true;
    for(int i = 2; i <= sqrt(a); ++i){
        if(a%i == 0){
            tmp = false;
            break;
        } 
    }
    cout << endl;
    return tmp;
}

void dfs(string curr, string numbers, int cnt){
    if(prime_check(stoi(curr))) ans.insert(stoi(curr));
    if(cnt == check.size()) return;
    for(int i = 0; i < check.size(); ++i){
        if(not check[i]){
            check[i] = true;
            dfs(curr + numbers[i], numbers, cnt + 1);
            check[i] = false;
        }
    }
}
int solution(string numbers) {
    check.resize(numbers.size(), false);
    string curr = "";
    for(int i = 0; i < numbers.size(); ++i){
        if(numbers[i] != '0'){
            check[i] = true;
            dfs(curr + numbers[i], numbers, 1);
            check[i] = false;
        }
    }
    return ans.size();
}