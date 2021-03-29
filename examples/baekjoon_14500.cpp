/*
DFS, brute-force

Point: To use DFS, you need to do exception handling.
+ For DFS, do not need to use check array with parameter. 
Remember, Do check, run DFS, undo check.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int N, M;
vector<vector<int> > paper;
vector<vector<bool> > check;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int tetromino(int x, int y, int s, int cnt){
	if(cnt == 4) return s;
	
	int ans = 0;
	s += paper[x][y];
	cnt += 1;
	check[x][y] = true;
	for(int i = 0; i < 4; ++i){
		int new_x = x + dx[i], new_y = y + dy[i];
		if(new_x < 0 || new_x >= N || new_y < 0 || new_y >= M || check[new_x][new_y]) continue;
		ans = max(ans, tetromino(new_x, new_y, s, cnt));
	}
	check[x][y] = false;
	return ans;
}

int convex_shape(int x, int y){
	int ans = 0;
	for(int i = 0; i < 4; ++i){
		int i1 = (i + 1)%4, i2 = (i + 2)%4, i3 = (i + 3)%4;
		int x1 = x + dx[i1], x2 = x + dx[i2], x3 = x + dx[i3], y1 = y + dy[i1], y2 = y + dy[i2], y3 = y + dy[i3];
		if(x1 < 0 || x2 < 0 || x3 < 0 || 
			x1 >= N || x2 >= N || x3 >= N ||
			y1 < 0 || y2 < 0 || y3 < 0 || 
			y1 >= M || y2 >= M || y3 >= M) continue;
		ans = max(ans, paper[x][y] + paper[x1][y1] + paper[x2][y2] + paper[x3][y3]);
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	paper.resize(N);
	check.resize(N);
	for(int i = 0; i < N; ++i){
		paper[i].resize(M, 0);
		check[i].resize(M, false);
	}
	
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j){
			cin >> paper[i][j];
		}
	}

	int ans = 0;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < M; ++j){
			ans = max(ans, tetromino(i, j, 0, 0));
			ans = max(ans, convex_shape(i, j));
		}
	}

	cout << ans << "\n";
	return 0;
}


/*
The code below is the wrong one with time limit exceed.
I didn't catch exception handling, thus the time take too long.
I tried to do DFS for every element at every step, thus the number of cases increase almost 10 times.  
*/


// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <utility>
// using namespace std;

// int N, M;
// vector<vector<pair<int, int> > > form;
// vector<vector<int> > paper;

// int tetromino(int r, int c){
// 	int ans = 0;
// 	// Straight
// 	int tmp = 0;
// 	for(int i = 0; i < 4; ++i){
// 		if(r + i >= N){tmp = 0; break;}
// 		tmp += paper[r + i][c];
// 	}
// 	ans = max(tmp. ans);
// 	tmp = 0;
// 	for(int i = 0; i < 4; ++i){
// 		if(c + i >= M){tmp = 0; break;}
// 		tmp += paper[r][c+i];
// 	}
// 	ans = max(tmp, ans);
// 	// Square
// 	tmp = 0;
// 	for(int i = 0; i < 4; ++i){
// 		int r1 = i/2, c1 = i%2;
// 		if(r + r1 >= N || c + c1 >= M){tmp = 0; break;}
// 		tmp += paper[r + r1][c + c1];
// 	}
// 	ans = max(tmp, ans);

// 	// 
// 	return ans;
// }

// int main(){
// 	ios::sync_with_stdio(false);
// 	cin.tie(NULL);
// 	cout.tie(NULL);

// 	form.resize(5);
// 	for(int i = 0; i < 5; ++i){
// 		form[i].resize(4);
// 	}
// 	form[0][0] = make_pair(0, 0); form[0][1] = make_pair(0, 1); form[0][2] = make_pair(0, 2); form[0][3] = make_pair(0, 0); 
// 	cin >> N >> M;
// 	paper.resize(N);
// 	for(int i = 0; i < N; ++i){
// 		paper[i].resize(M);
// 	}
// 	vector<vector<bool> > choose(N, vector<bool>(M, false));
// 	vector<pair<int, int> > polyminos(0);
// 	for(int i = 0; i < N; ++i){
// 		for(int j = 0; j < M; ++j){
// 			cin >> paper[i][j];
// 		}
// 	}
// 	int ans = 0;
// 	for(int i = 0; i < N; ++i){
// 		for(int j = 0; j < M; ++j){
// 			ans = max(ans, tetromino(i, j));
// 		}
// 	}

// 	cout << ans << "\n";
// 	return 0;
// }