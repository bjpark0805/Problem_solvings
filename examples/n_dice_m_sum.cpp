#include <iostream>
using namespace std;
int N, M;
int num[11];

void dice(int level, int sum){
	if(level <= N){
		for(int i = 1; i <= 6; ++i){
			num[level] = i;
			dice(level + 1, sum + i);
		}
	}
	else{
		if(sum == M){
			for(int i = 1; i <= N; ++i){
				cout << num[i] << " ";
			}
			cout << endl;
		}
	} 
}


int main(){
	cin >> N >> M;
	for(int i = 0; i < 11; ++i){
		num[i] = 0;
	}
	dice(1, 0);
	return 0;
}

