#include <stdio.h>
#include <vector>

using namespace std;

int main(){
	vector<int> top(4, 0);
	int K;
	vector<vector<int> > gear(4, vector<int>(8, 0));
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 8; ++j){
			scanf("%1d", &gear[i][j]);
		}
	}
	scanf("%d", &K);
		
	for(int i = 0; i < K; ++i){
		int num, d;
		scanf("%d%d", &num, &d);
		num -= 1;
		vector<int> tmp(top);
		tmp[num] = (tmp[num] - d + 8)%8;
		int tmp_d = d;
		for(int j = num + 1; j < 4; ++j){
			tmp_d = -tmp_d;
			if(gear[j - 1][(top[j - 1]+2)%8] == gear[j][(top[j]+6)%8]) break;
			else tmp[j] = (tmp[j] - tmp_d + 8)%8;
		}
		tmp_d = d;
		for(int j = num - 1; j >= 0; --j){
			tmp_d = -tmp_d;
			if(gear[j + 1][(top[j + 1]+6)%8] == gear[j][(top[j]+2)%8]) break;
			else tmp[j] = (tmp[j] - tmp_d + 8)%8;
		}

		top = tmp;
	}

	int sum = gear[0][top[0]] + gear[1][top[1]] * 2 + gear[2][top[2]] * 4 + gear[3][top[3]] * 8; 
	printf("%d\n", sum);

	return 0;
}