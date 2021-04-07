#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int N, M, ans = 0;
vector<vector<int> > office;
vector<pair<int, int> > cameras;

void blind_sight(int cnt){
	if(cameras.empty()){
		ans = max(ans, cnt);
		return;
	}
	pair<int, int> camera = cameras.back()
	cameras.pop_back();
	int r = camera.first, c = camera.second;
	int camera_num = office[r][c];
	if(camera_num == 1){
		for(int d = 0; d < 4; ++d){
			int r_diff = 0; c_diff = 0;
			if(d % 2) r_diff = d - 2;
			else c_diff = d - 1;
			for(int i = 1; i < max(N, M); ++i){
				
			}
		}
		vector<pair<int, int> > changes;

	}
	else if(camera_num == 2){

	}
	else if(camera_num == 3){

	}
	else if(camera_num == 4){

	}
	else{ // camera_num == 5

	}



	cameras.push_back(camera);
	return;	
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	cameras.resize(N);
	for(int i = 0; i < N; ++i){
		cameras[i].resize(M);
		for(int j = 0; j < M; ++j){
			cin >> cameras[i][j];
			if(cameras[i][j] >= 1 || cameras[i][j] <= 5) office.push_back(make_pair(i, j));
		}
	}

	blind_sight(0);
	cout << ans << "\n";
	return 0;
}