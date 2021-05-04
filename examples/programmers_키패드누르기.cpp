#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left_row = 3, right_row = 3, left_col = 0, right_col = 2;
    int rows[10] = {3, 0, 0, 0, 1, 1, 1, 2, 2, 2};
    for(vector<int>::iterator iter = numbers.begin(); iter != numbers.end(); ++iter){
    	if(*iter == 1 or *iter == 4 or *iter == 7){
    		answer += "L";
    		left_row = rows[*iter];
    		left_col = 0;
    	}
    	else if(*iter == 3 or *iter == 6 or *iter == 9){
    		answer += "R";
    		right_row = rows[*iter];
    		right_col = 2;
    	}
    	else{
    		int r = rows[*iter];
    		if(abs(r - left_row) + 1 - left_col > abs(r - right_row) + right_col - 1){
    			answer += "R";
    			right_row = r;
    			right_col = 1;
    		}
    		else if(abs(r - left_row) + 1 - left_col < abs(r - right_row) + right_col - 1){
    			answer += "L";
    			left_row = r;
    			left_col = 1;
    		}
    		else{
    			if(hand == "left"){
    				answer += "L";
	    			left_row = r;
	    			left_col = 1;
    			}
    			else{
    				answer += "R";
	    			right_row = r;
	    			right_col = 1;
    			}
    		}
    	}
    }
    return answer;
}

int main(){
	vector<int> numbers = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
	string hand = "right";
	cout << solution(numbers, hand) << endl;
	return 0;
}