// 1시간 17분
// 시뮬레이션
// 디버깅하는데 시간이 간당간당했음
// 시뮬레이션 문제 풀때 잘못 설계하면 디버깅 시간이 오래걸린다. 다 정리하고 가는게 좋긴할듯
// 사실 벡터 정확하게 몰라서 디버깅 오래걸린게 크다.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void tree_investment(){
	int N, M, K;
	cin >> N >> M >> K;
	vector<vector<vector<int> > > trees(N, vector<vector<int> >(N));
	vector<vector<int> > land(N,vector<int>(N, 5));
	vector<vector<int> > A(N, vector<int>(N, 0));
	int dr[8] = {-1,-1,-1,0,0,1,1,1};
	int dc[8] = {-1,0,1,-1,1,-1,0,1};
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cin >> A[i][j];
		}
	}

	for(int i = 0; i < M; ++i){
		int x, y, z;
		cin >> x >> y >> z;
		trees[x-1][y-1].push_back(z);
	}
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			sort(trees[i][j].begin(), trees[i][j].end());
		}
	}
	for(int k = 0; k < K; ++k){
		vector<vector<int> > tree_grow(N, vector<int>(N, 0));
	
		// spring and summer 
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < N; ++j){
				vector<int> temp_tree;
				int add_nu = 0;
				for(int t = 0; t < trees[i][j].size(); ++t){	
					if(trees[i][j][t] <= land[i][j]){
						land[i][j] -= trees[i][j][t];
						trees[i][j][t] += 1;
						temp_tree.push_back(trees[i][j][t]);
						if(trees[i][j][t] % 5 == 0){
							for(int d = 0; d < 8; ++d){
								int nr = i + dr[d], nc = j+dc[d];
								if(nr >= 0 and nr < N and nc >= 0 and nc < N){
									tree_grow[nr][nc]++;
								}
							}
						} 
					}
					else add_nu += trees[i][j][t]/2;
				}
				land[i][j] += add_nu;
				trees[i][j] = temp_tree;
			}
		}

		// fall and winter
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < N; ++j){
				// if(tree_grow[i][j] > 0)
				trees[i][j].insert(trees[i][j].begin(), tree_grow[i][j], 1);
				land[i][j] += A[i][j];
			}
		}
	}

	int answer = 0;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			answer += trees[i][j].size();
		}
	}
	cout << answer << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	tree_investment();
	return 0;
}