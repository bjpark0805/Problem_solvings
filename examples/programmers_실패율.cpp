#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;

bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
	long long f_r = a.first.second, s_r = b.first.second;
	f_r *= max(1, b.first.first);
	s_r *= max(1, a.first.first);
	if(f_r == s_r) return a.second < b.second;
	else return f_r > s_r;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<pair<int, int>, int> > fail_rate(N, make_pair(make_pair(0, 0), 0));

    for(int i = 0; i < N; ++i){
    	fail_rate[i].second = i + 1;
    }
    for(vector<int>::iterator iter = stages.begin(); iter != stages.end(); ++iter){
    	int s = *iter;
    	for(int i = 0; i < min(s, N); ++i){
    		fail_rate[i].first.first++;
    	}
    	if(s <= N) fail_rate[s-1].first.second++;
    }
    
    sort(fail_rate.begin(), fail_rate.end(), compare);
    for(int i = 0; i < N; ++i){
    	answer.push_back(fail_rate[i].second);
    }
    return answer;
}

int main(){
	int N = 4;
	vector<int> stages = {4,4,4,4,4};
	vector<int> answer = solution(N, stages);
	for(vector<int>::iterator iter = answer.begin(); iter != answer.end(); ++iter){
		cout << *iter << " ";
	}
	cout << endl;
	return 0;
}