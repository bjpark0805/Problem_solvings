#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    vector<int> get_number(4);
    get_number[1] = 1;
    get_number[2] = 2;
    get_number[0] = 4;
    string answer = "";
    while(n > 3){
        answer = to_string(get_number[n % 3]) + answer;
        n = (n - 1)/3;
    }
    answer = to_string(get_number[n % 3]) + answer;
    return answer;
}