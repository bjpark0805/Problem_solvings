#include<vector>
#include <queue>
#include <utility>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size(), m = maps[0].size();
    int dr[4] = {0, 0, -1, 1};
    int dc[4] = {-1, 1, 0, 0};
    queue<pair<int, int> > q;
    vector<vector<bool> > visited(n, vector<bool>(m));
    q.push(make_pair(0, 0));
    visited[0][0] = true;
    int level = 2;
    while(!q.empty()){
        int qsize = q.size();
        for(int i = 0; i < qsize; ++i){
            int r = q.front().first, c = q.front().second;
            q.pop();
            for(int d = 0; d < 4; ++d){
                int nr = r + dr[d], nc = c + dc[d];
                if(nr < 0 or nr >= n or nc < 0 or nc >= m or visited[nr][nc] or maps[nr][nc] == 0) continue;
                if(nr == n - 1 and nc == m - 1){
                    return level;
                }
                q.push(make_pair(nr, nc));
                visited[nr][nc] = true;
            }
        }
        level++;
    }
    return -1;
}