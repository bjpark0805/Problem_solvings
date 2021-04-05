#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L, cnt = 0;
	cin >> N >> L;
	vector<vector<int> > map(N, vector<int>(N, 0));

	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			cin >> map[i][j];
		}
	}
	for(int r = 0; r < N; ++r){
		vector<bool> slide(N, true);
		for(int i = 0; i < N;){
			if(i == N - 1 || map[r][i] == map[r][i+1]){
				if(i >= N - 2) {cnt += 1; break;}
				else i = i + 1;
			}
			else if(map[r][i] > map[r][i+1] + 1 || map[r][i] < map[r][i+1] - 1) break;
			else if(map[r][i] > map[r][i+1]){
				bool unable = false;
				for(int l = 1; l <= L; ++l){
					if(i + l >= N) {unable = true; break;}
					else if(map[r][i+1] == map[r][i+l] && slide[i+l]) slide[i+l] = false;
					else{unable = true; break;}
				}
				if(unable) break;
				i = i + L;
			}
			else{
				bool unable = false;
				for(int l = 0; l < L; ++l){
					if(i - l < 0) {unable = true; break;}
					else if(map[r][i] == map[r][i-l] && slide[i-l]) slide[i-l] = false;
					else{unable = true; break;}
				}
				if(unable) break;
				i = i + 1;
			}
		}
	}

	for(int c = 0; c < N; ++c){
		vector<bool> slide(N, true);
		for(int i = 0; i < N;){
			if(i == N - 1 || map[i][c] == map[i + 1][c]){
				if(i >= N - 2) {cnt += 1; break;}
				else i = i + 1;
			}
			else if(map[i][c] > map[i+1][c] + 1 || map[i][c] < map[i+1][c] - 1) break;
			else if(map[i][c] > map[i+1][c]){
				bool unable = false;
				for(int l = 1; l <= L; ++l){
					if(i + l >= N) {unable = true; break;}
					else if(map[i+1][c] == map[i+l][c] && slide[i+l]) slide[i+l] = false;
					else{unable = true; break;}
				}
				if(unable) break;
				i = i + L;
			}
			else{
				bool unable = false;
				for(int l = 0; l < L; ++l){
					if(i - l < 0) {unable = true; break;}
					else if(map[i][c] == map[i-l][c] && slide[i-l]) slide[i-l] = false;
					else{unable = true; break;}
				}
				if(unable) break;
				i = i + 1;
			}
		}
	}

	cout << cnt << "\n";
	return 0;
}