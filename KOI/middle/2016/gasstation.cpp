#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
// 1km마다 1L 
vector<int> dist, price;
vector< pair<int, int> > priceandindex;
int m = 0;

bool compare(const pair<int, int>&a, const pair<int, int>&b)
{
	if(a.first == b.first)
		return a.second > b.second;
	return a.first > b.first;
}

long long calculate_price(int range){
	if(range == 0) return 0;
	int min_value, min_index;
	// for(int i = 0; i < range; ++i){
	// 	int p = price.at(i);
	// 	if(p < min_value){
	// 		min_value = p;
	// 		min_index = i;
	// 	}
	// }
	for(int i = m; i < priceandindex.size(); ++i){
		pair<int, int> temp = priceandindex.at(i);
		if(temp.second >= range) continue;
		else{
			min_value = temp.first;
			min_index = temp.second;
			m = temp.second;
		}
	}
	long long temp_sum = 0;
	
	for(int i = range - 1; i >= min_index; --i){
		temp_sum += dist.at(i);
	}
	return price.at(min_index) * temp_sum + calculate_price(min_index);
}
int main(){
	int N;
	cin >> N;
	long long partsum = 0;
	for(int i = 0; i < N -1; ++i){
		int temp;
		scanf("%d", &temp);
		dist.push_back(temp);
	}
	// int min_value = 1000000001, min_index = -1;
	for(int i = 0; i < N; ++i){
		int temp;
		scanf("%d", &temp);
		// if(temp < min_value){
		// 	min_value = temp;
		// 	min_index = i;
		// }
		price.push_back(temp);
		if(i < N - 1) priceandindex.push_back(make_pair(temp, i));
	}
	sort(priceandindex.begin(), priceandindex.end(), compare);
	// long long temp_sum = 0;
	// for(int i = dist.size() - 1; i >= min_index; --i){
	// 	temp_sum += dist.at(i);
	// }
	cout << calculate_price(N-1);

	return 0;
}
