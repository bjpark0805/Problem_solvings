#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = ""; 
    string day[7] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
    int d = 4;
    int month[12] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    for(int i = 0; i < a; ++i){
        d += month[i];
    }
    d += b;
    return answer = day[d%7];
}