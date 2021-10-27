#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <utility>

std::vector<std::string> arr;
std::map<char, int> m;
std::map<char, int> weights;
std::vector<std::pair<char, int> > alphabets;
std::set<int> used_numbers;
int num_alphabet, num_words, max_sum = -1, sums = 0;

int calculate_sum(){
	int temp_sum = 0;
	for(int n = 0; n < num_words; ++n){
		for(int c = 0; c < arr[n].size(); ++c){
			int mul = m[arr[n][c]];
			if(mul == -1) mul = 9;
			temp_sum += mul * pow(10, arr[n].size() - c - 1);
		}
	}
	return temp_sum;
}

void backtracking(int idx){
	if(idx == num_alphabet){
		max_sum = std::max(max_sum, calculate_sum());
		return;
	}
	char alphabet = alphabets[idx].first;
	for(int i = 9; i >= 0; --i){
		bool invalid = false;
		int temp_sum = 0;
		if(i == 0){
			for(int n = 0; n < num_words; ++n){
				if(arr[n][0] == alphabet and arr[n].size() != 1) invalid = true;
			}
		}
		if(used_numbers.find(i) != used_numbers.end()) invalid = true;
		if(invalid) continue;
		m[alphabet] = i;
		used_numbers.insert(i);
		backtracking(idx + 1);
		m[alphabet] = -1;
		used_numbers.erase(i);
	}
}

bool compare(std::pair<char, int> a, std::pair<char, int> b){
	return a.second > b.second;
}

void greedy_search(){
	for(int i = 0; i < num_alphabet; ++i){
		m[alphabets[i].first] = 9 - i;
	}
	max_sum = calculate_sum();
}

int main(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::cin >> num_words;
	arr.resize(num_words);
	for(int i = 0; i < num_words; ++i){
		std::cin >> arr[i];
		for(int j = 0; j < arr[i].size(); ++j){
			m[arr[i][j]] = -1;
			if(weights.find(arr[i][j]) == weights.end()) weights[arr[i][j]] = 0;
			weights[arr[i][j]] += pow(10, arr[i].size() - j - 1); 
		}
	}
	num_alphabet = m.size();
	for(auto const& iter: weights){
		alphabets.push_back(std::make_pair(iter.first, iter.second));
	}
	sort(alphabets.begin(), alphabets.end(), compare);
	// backtracking(0);
	greedy_search();
	std::cout << max_sum << "\n";
	return 0;
}

