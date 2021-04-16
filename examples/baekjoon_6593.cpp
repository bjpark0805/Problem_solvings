#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int dl[6] = {0,0,0,0,1,-1};
int dr[6] = {0,0,1,-1,0,0};
int dc[6] = {1,-1,0,0,0,0};

vector<vector<string> > building;
int L, R, C;
int l1, l2, r1, r2, c1, c2;

void bfs(){
	building[l1][r1][c1] = '#';
	queue<pair<int, pair<int, int> > > q;
	q.push(make_pair(l1, make_pair(r1, c1)));
	int level = 1;
	while(!q.empty()){
		int qsize = q.size();
		for(int i = 0; i < qsize; ++i){
			int l = q.front().first, r = q.front().second.first, c = q.front().second.second;
			q.pop();
			for(int d = 0; d < 6; ++d){
				int nl = l + dl[d], nr = r + dr[d], nc = c + dc[d];
				if(nl == l2 and nr == r2 and nc == c2){
					cout << "Escaped in " << level << " minute(s).\n";
					return;
				}
				if(nl >= 0 and nl < L and nr >= 0 and nr < R and nc >= 0 and nc < C and not (building[nl][nr][nc] == '#')){
					q.push(make_pair(nl, make_pair(nr, nc)));
					building[nl][nr][nc] = '#';
				}
			}
		}
		level++;
	}
	cout << "Trapped!\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(true){
		cin >> L >> R >> C;
		if(L == 0 and R == 0 and C == 0) break;
		building.clear();
		building.resize(L);
		for(int i = 0; i < L; ++i){
			building[i].resize(R);
			for(int j = 0; j < R; ++j){
				cin >> building[i][j];
				for(int c = 0; c < C; ++c){
					if(building[i][j][c] == 'S'){
						l1 = i; r1 = j; c1 = c;
					}
					else if(building[i][j][c] == 'E'){
						l2 = i; r2 = j; c2 = c;
					}
				}
			}
			cin.ignore();
			string s;
			getline(cin, s);
		}
		bfs();
	}
	return 0;
}