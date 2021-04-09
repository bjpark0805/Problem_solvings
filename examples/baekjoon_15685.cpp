#include <iostream>
#include <vector>

using namespace std;
// 39분
vector<vector<bool> > points(101, vector<bool>(101, false));
int dr[4] = {0, -1, 0, 1};
int dc[4] = {1, 0, -1, 0};

void generate_drogon_curve(int r, int c, int d, int gen){
	vector<int> directions;
	directions.push_back(d);
	points[r][c] = true;
	r += dr[d]; 
	c += dc[d];
	points[r][c] = true;

	for(int g = 0; g < gen; ++g){
		for(int i = directions.size() - 1; i >= 0; --i){
			int nd = (directions[i] + 1)%4;
			r += dr[nd];
			c += dc[nd];
			points[r][c] = true;
			directions.push_back(nd);
		}
	}
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N, x, y, d, g;
	cin >> N;

	for(int i = 0; i < N; ++i){
		cin >> x >> y >> d >> g;
		generate_drogon_curve(y, x, d, g);
	}
	int cnt = 0;
	for(int i = 0; i < 100; ++i){
		for(int j = 0; j < 100; ++j){
			if(points[i][j] and points[i+1][j] and points[i][j+1] and points[i+1][j+1]) cnt += 1;
		}
	}
	cout << cnt << "\n";
	return 0;
}