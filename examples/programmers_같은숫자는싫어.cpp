#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    int previous = 0;
    for(int i = 0; i < arr.size();){
    	while(i < arr.size() and arr[i] == arr[previous]){
    		i++;
    	}
    	answer.push_back(arr[previous]);
    	previous = i;
    }

    return answer;
}

int main(){
	vector<int> arr = {4,3,2};
	vector<int> answer = solution(arr);
	for(int i = 0; i < answer.size(); ++i){
		cout << answer[i] << " ";
	}
	cout << endl;
	return 0;
}