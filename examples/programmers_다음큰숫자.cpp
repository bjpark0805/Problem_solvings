#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    int cnt = 0;
    int n_temp = n;
    while(n_temp > 1){
    	cnt += n_temp % 2;
    	n_temp /= 2;
    }
    for(int i = 1; i <= n; ++i){
    	int new_n = n + i;
    	int cnt_new = 0;
    	while(new_n > 1){
    		cnt_new += new_n % 2;
    		new_n /= 2;
    	}
    	if(cnt_new == cnt){
    		answer = n + i;
    		break;
    	}
    }
    return answer;
}

int main(){
	int n = 15;
	cout << solution(n) << "\n";
	return 0;
}