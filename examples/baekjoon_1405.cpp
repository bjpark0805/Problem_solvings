#include <cstdio>
#include <vector>

double prob = 0.0;
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
double dp[4] = {0,0,0,0};
int N;
std::vector<std::vector<bool> > visited;

void backtracking(int r, int c, int length, double curr_prob){
	if(length == N){
		prob += curr_prob;
		return;
	}
	for(int d = 0; d < 4; ++d){
		int nr = r + dr[d], nc = c + dc[d];
		if(visited[nr][nc]) continue;
		visited[nr][nc] = true;
		backtracking(nr, nc, length + 1, curr_prob * dp[d]);
		visited[nr][nc] = false;
	}
}

int main(){
	int EP,WP,SP,NP;
	scanf("%d%d%d%d%d", &N, &EP, &WP, &SP, &NP);
	dp[0] = (double)EP/100;
	dp[1] = (double)WP/100;
	dp[2] = (double)SP/100;
	dp[3] = (double)NP/100;
	visited.resize(2*N+1, std::vector<bool>(2*N+1, false));
	visited[N][N] = true;
	double p = 1.0;
	backtracking(N, N, 0, p);
	printf("%.9lf\n", prob);
	return 0;
}