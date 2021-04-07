#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int N, M, ans;
vector<vector<int> > office;
vector<pair<int, int> > cameras;

void blind_sight(){
	if(cameras.empty()){
		int cnt = 0;
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < M; ++j){
				if(office[i][j] == 0) cnt += 1;
			}
		}
		ans = min(ans, cnt);
		return;
	}
	pair<int, int> camera = cameras.back();
	cameras.pop_back();
	int r = camera.first, c = camera.second;
	int camera_num = office[r][c];
	if(camera_num == 1){
		for(int d = 0; d < 4; ++d){
			vector<pair<int, int> > changes;
			int r_diff = 0, c_diff = 0;
			if(d % 2) r_diff = d - 2;
			else c_diff = d - 1;
			for(int i = 1; i < max(N, M); ++i){
				int new_r = r + i * r_diff, new_c = c + i * c_diff;
				if(new_r < 0 || new_r >= N || new_c < 0 || new_c >= M || office[new_r][new_c] == 6) break;
				if(office[new_r][new_c] == 0){changes.push_back(make_pair(new_r, new_c)); office[new_r][new_c] = -1;}
			}
			blind_sight();
			for(int i = 0; i < changes.size(); ++i){
				office[changes[i].first][changes[i].second] = 0;
			}
		}
	}
	else if(camera_num == 2){
		for(int d = 0; d < 4; ++d){
			vector<pair<int, int> > changes;
			int r_diff = 0, c_diff = 0;
			if(d % 2) r_diff = d - 2;
			else c_diff = d - 1;
			for(int i = 1; i < max(N, M); ++i){
				int new_r = r + i * r_diff, new_c = c + i * c_diff;
				if(new_r < 0 || new_r >= N || new_c < 0 || new_c >= M || office[new_r][new_c] == 6) break;
				if(office[new_r][new_c] == 0){changes.push_back(make_pair(new_r, new_c)); office[new_r][new_c] = -1;}
			}
			for(int i = 1; i < max(N, M); ++i){
				int new_r = r - i * r_diff, new_c = c - i * c_diff;
				if(new_r < 0 || new_r >= N || new_c < 0 || new_c >= M || office[new_r][new_c] == 6) break;
				if(office[new_r][new_c] == 0){changes.push_back(make_pair(new_r, new_c)); office[new_r][new_c] = -1;}
			}
			blind_sight();
			for(int i = 0; i < changes.size(); ++i){
				office[changes[i].first][changes[i].second] = 0;
			}
		}
	}
	else if(camera_num == 3){
		for(int d = 0; d < 4; ++d){
			vector<pair<int, int> > changes;
			int r_diff = 0, c_diff = 0;
			if(d % 2) r_diff = d - 2;
			else c_diff = d - 1;
			for(int i = 1; i < max(N, M); ++i){
				int new_r = r + i * r_diff, new_c = c + i * c_diff;
				if(new_r < 0 || new_r >= N || new_c < 0 || new_c >= M || office[new_r][new_c] == 6) break;
				if(office[new_r][new_c] == 0){changes.push_back(make_pair(new_r, new_c)); office[new_r][new_c] = -1;}
			}
			int d_n = (d + 1)%4;
			r_diff = 0; c_diff = 0;
			if(d_n % 2) r_diff = d_n - 2;
			else c_diff = d_n - 1;
			for(int i = 1; i < max(N, M); ++i){
				int new_r = r + i * r_diff, new_c = c + i * c_diff;
				if(new_r < 0 || new_r >= N || new_c < 0 || new_c >= M || office[new_r][new_c] == 6) break;
				if(office[new_r][new_c] == 0){changes.push_back(make_pair(new_r, new_c)); office[new_r][new_c] = -1;}
			}
			blind_sight();
			for(int i = 0; i < changes.size(); ++i){
				office[changes[i].first][changes[i].second] = 0;
			}
		}
	}
	else if(camera_num == 4){
		for(int d = 0; d < 4; ++d){
			vector<pair<int, int> > changes;
			int r_diff = 0, c_diff = 0;
			if(d % 2) r_diff = d - 2;
			else c_diff = d - 1;
			for(int i = 1; i < max(N, M); ++i){ // original
				int new_r = r + i * r_diff, new_c = c + i * c_diff;
				if(new_r < 0 || new_r >= N || new_c < 0 || new_c >= M || office[new_r][new_c] == 6) break;
				if(office[new_r][new_c] == 0){changes.push_back(make_pair(new_r, new_c)); office[new_r][new_c] = -1;}
			}
			for(int i = 1; i < max(N, M); ++i){ // opposite
				int new_r = r - i * r_diff, new_c = c - i * c_diff;
				if(new_r < 0 || new_r >= N || new_c < 0 || new_c >= M || office[new_r][new_c] == 6) break;
				if(office[new_r][new_c] == 0){changes.push_back(make_pair(new_r, new_c)); office[new_r][new_c] = -1;}
			}
			int d_n = (d + 1)%4;
			r_diff = 0; c_diff = 0;
			if(d_n % 2) r_diff = d_n - 2;
			else c_diff = d_n - 1;
			for(int i = 1; i < max(N, M); ++i){ // right
				int new_r = r + i * r_diff, new_c = c + i * c_diff;
				if(new_r < 0 || new_r >= N || new_c < 0 || new_c >= M || office[new_r][new_c] == 6) break;
				if(office[new_r][new_c] == 0){changes.push_back(make_pair(new_r, new_c)); office[new_r][new_c] = -1;}
			}
			
			blind_sight();
			for(int i = 0; i < changes.size(); ++i){
				office[changes[i].first][changes[i].second] = 0;
			}
		}
	}
	else{ // camera_num == 5
		int d = 0;
		vector<pair<int, int> > changes;
		int r_diff = 0, c_diff = 0;
		if(d % 2) r_diff = d - 2;
		else c_diff = d - 1;
		for(int i = 1; i < max(N, M); ++i){ // original
			int new_r = r + i * r_diff, new_c = c + i * c_diff;
			if(new_r < 0 || new_r >= N || new_c < 0 || new_c >= M || office[new_r][new_c] == 6) break;
			if(office[new_r][new_c] == 0){changes.push_back(make_pair(new_r, new_c)); office[new_r][new_c] = -1;}
		}
		for(int i = 1; i < max(N, M); ++i){ // opposite
			int new_r = r - i * r_diff, new_c = c - i * c_diff;
			if(new_r < 0 || new_r >= N || new_c < 0 || new_c >= M || office[new_r][new_c] == 6) break;
			if(office[new_r][new_c] == 0){changes.push_back(make_pair(new_r, new_c)); office[new_r][new_c] = -1;}
		}
		int d_n = (d + 1)%4;
		r_diff = 0; c_diff = 0;
		if(d_n % 2) r_diff = d_n - 2;
		else c_diff = d_n - 1;
		for(int i = 1; i < max(N, M); ++i){ // right
			int new_r = r + i * r_diff, new_c = c + i * c_diff;
			if(new_r < 0 || new_r >= N || new_c < 0 || new_c >= M || office[new_r][new_c] == 6) break;
			if(office[new_r][new_c] == 0){changes.push_back(make_pair(new_r, new_c)); office[new_r][new_c] = -1;}
		}
		for(int i = 1; i < max(N, M); ++i){ // opposite
			int new_r = r - i * r_diff, new_c = c - i * c_diff;
			if(new_r < 0 || new_r >= N || new_c < 0 || new_c >= M || office[new_r][new_c] == 6) break;
			if(office[new_r][new_c] == 0){changes.push_back(make_pair(new_r, new_c)); office[new_r][new_c] = -1;}
		}
		blind_sight();
		for(int i = 0; i < changes.size(); ++i){
			office[changes[i].first][changes[i].second] = 0;
		}
	}

	cameras.push_back(camera);
	return;	
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	ans = N * M;
	office.resize(N);
	for(int i = 0; i < N; ++i){
		office[i].resize(M);
		for(int j = 0; j < M; ++j){
			cin >> office[i][j];
			if(office[i][j] >= 1 and office[i][j] <= 5) cameras.push_back(make_pair(i, j));
		}
	}

	blind_sight();
	cout << ans << "\n";
	return 0;
}