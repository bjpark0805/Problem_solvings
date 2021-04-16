#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2,0);
    for(int r = 1; r <= yellow; ++r){
    	if(yellow % r != 0) continue;
    	int c = yellow / r;
    	if(2 * r + 2 * c + 4 == brown){
    		answer[0] = c + 2;
    		answer[1] = r + 2;
    		break;
    	}
    }
    return answer;
}

int main(){
	int brown = 24;
	int yellow = 24;
	cout << solution(brown, yellow)[0] << " " << solution(brown, yellow)[1] << endl;
}