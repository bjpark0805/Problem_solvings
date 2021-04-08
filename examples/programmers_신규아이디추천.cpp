#include <string>
#include <vector>
#io
using namespace std;

string solution(string new_id) {
    string answer = "";
    answer= new_id;
    //step 1
    /* Use transform
    transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
    */
    for(int i = 0; i < answer.size(); ++i){
        if(answer[i] >= 'A' and answer[i] <= 'Z') answer[i] += 32;
    }
    
    //step 2
    string temp = "";
    for(int i = 0; i < answer.size(); ++i){
        if((answer[i] >= 'a' and answer[i] <= 'z') 
                or (answer[i] >= '0' and answer[i] <= '9') 
                or (answer[i] == '-') 
                or (answer[i] == '_') 
                or (answer[i] == '.')){
            temp += answer[i];
        }
    }
    answer = temp;

    // step 3
    temp = "";
    for(int i = 0; i < answer.size(); ++i){
        temp += answer[i];
        if(answer[i] == '.'){
            int j;
            for(j = i + 1; j < answer.size(); ++j){
                if(answer[j] != '.') break;
            }
            i = j - 1;
        }
    }
    answer = temp;
    
    // step 4
    if(answer[0] == '.') answer = answer.substr(1, answer.size() - 1);
    if(answer[answer.size() - 1] == '.') answer = answer.substr(0, answer.size() - 1);
    
    // step 5
    if(answer.size() == 0) answer = "a";
    
    // step 6
    if(answer.size() >= 16) answer = answer.substr(0, 15);
    if(answer[0] == '.') answer = answer.substr(1, answer.size() - 1);
    if(answer[answer.size() - 1] == '.') answer = answer.substr(0, answer.size() - 1);
    
    // step 7
    while(answer.size() < 3){
        int s = answer.size();
        answer += answer[s - 1];
    }
    
    return answer;
}