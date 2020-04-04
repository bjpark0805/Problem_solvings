# 2016 KOI middle #1

#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int main(){
	int N, K;
	int fstsnd = 0, threefourm = 0, threefourw = 0, fivesixm = 0, fivesixw = 0;
	int room = 0;
	cin >> N >> K;
	for(int i = 0; i < N; ++i){
		int S, Y;
		cin >> S >> Y;
		if(Y <= 2) fstsnd++;
		else if(Y == 3 || Y == 4){
			if(S == 0) threefourw++;
			else threefourm++;
		}
		else{
			if(S == 0) fivesixw++;
			else fivesixm++;	
		}
	}
	room = (fstsnd + K - 1)/ K + (threefourm + K - 1)/ K + (threefourw + K -1) / K 
	+ (fivesixm + K - 1)/ K + (fivesixw + K - 1)/ K;

	cout << room;
	return 0;
}
