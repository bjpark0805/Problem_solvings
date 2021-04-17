#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dfs(vector<int> &numbers, int idx, int curr, int target){
	if(idx == numbers.size()){
		if(curr == target) return 1;
		else return 0;
	}
	return dfs(numbers, idx + 1, curr + numbers[idx], target) + dfs(numbers, idx + 1, curr - numbers[idx], target);
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    answer = dfs(numbers, 0, 0, target);
    return answer;
}

int main(){
	vector<int> numbers = {1, 1, 1, 1, 1};
	int target = 3;
	cout << solution(numbers, target) << endl;
	return 0;
}