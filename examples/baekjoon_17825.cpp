// 1시간 30분 소요
// 시뮬레이션 + dfs로 완전탐색인데 dfs할 때 팝이 스무스하게 안되어서 좀 짜증남.
// 일부 디버깅 문제.
// 문제 잘 못 읽음. 말은 4개밖에 없었다.. 말이 4개밖에 없는 경우에는 아주 쉽게 dfs활용 가능.
// 말이 무한대일때가 좀 복잡함.
// 약간 백트래킹 문제라는데 백트래킹 공부를 좀 하고 다시 오자.

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int answer = 0;
vector<vector<int> > board;
vector<vector<bool> > visited;

vector<int> dice(10);

pair<int, int> find_next(int board_n, int idx, int dice_num){
	if(board_n == 0){
		if(dice_num + idx == 5) return make_pair(1, 0);
		else if(dice_num + idx == 10) return make_pair(2, 0);
		else if(dice_num + idx == 15) return make_pair(3, 0);
		else if(dice_num + idx == 20) return make_pair(4, 3);
		else if(dice_num + idx > 20) return make_pair(4, 4);
		else return make_pair(board_n, idx + dice_num);
	}
	else if(board_n == 1 or board_n == 3){
		if(dice_num + idx > 3) return make_pair(4, dice_num + idx - 4);
		else return make_pair(board_n, idx + dice_num);
	}
	else if(board_n == 2){
		if(dice_num + idx > 2) return make_pair(4, dice_num + idx - 3);
		else return make_pair(board_n, idx + dice_num);
	}
	else{
		if(dice_num + idx > 3) return make_pair(4, 4);
		else return make_pair(board_n, idx + dice_num);
	}
}

void dfs(int num, int score, vector<pair<int, int> > horse, int left){
	if(num == 10){
		answer = max(answer, score);
		return;
	}

	int dice_num = dice[num];
	pair<int, int> tmp = find_next(0, 0, dice_num);
	if(not visited[tmp.first][tmp.second] and left > 0){
		visited[tmp.first][tmp.second] = true;
		vector<pair<int, int> > horse_temp(horse);
		horse_temp.push_back(tmp);
		dfs(num + 1, score + board[tmp.first][tmp.second], horse_temp, left - 1);
		visited[tmp.first][tmp.second] = false;
	}

	for(int i = 0; i < horse.size(); ++i){
		int old_bn = horse[i].first, old_idx = horse[i].second;
		if(old_bn == 4 and old_idx == 4) continue;
		int board_n = find_next(horse[i].first, horse[i].second, dice_num).first;
		int idx = find_next(horse[i].first, horse[i].second, dice_num).second;
		vector<pair<int, int> > horse_temp(horse);
		if(visited[board_n][idx]) continue;
		if(board_n == 4 and idx == 4){
			horse_temp[i].first = board_n;
			horse_temp[i].second = idx;
			visited[old_bn][old_idx] = false;
			dfs(num + 1, score, horse_temp, left);
			visited[old_bn][old_idx] = true;
		}
		else{
			// cout << board_n << " " << idx << endl;
			visited[board_n][idx] = true;
			visited[old_bn][old_idx] = false;
			horse_temp[i].first = board_n;
			horse_temp[i].second = idx;
			dfs(num + 1, score + board[board_n][idx], horse_temp, left);
			visited[board_n][idx] = false;
			visited[old_bn][old_idx] = true;
		}	
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for(int i = 0; i < 10; ++i){
		cin >> dice[i];
	}

	board.resize(5);
	board[0].resize(20);
	for(int i = 0; i < 20; ++i){
		board[0][i] = 2 * i;
	}
	board[1].resize(4);
	for(int i = 0; i < 4; ++i){
		board[1][i] = 10 + 3*i;
	}
	board[2].resize(3);
	for(int i = 0; i < 3; ++i){
		board[2][i] = 20 + 2*i;
	}
	board[3].resize(4);
	board[3][0] = 30;
	for(int i = 1; i < 4; ++i){
		board[3][i] = 29 - i;
	}
	board[4].resize(4);
	for(int i = 0; i < 4; ++i){
		board[4][i] = 25 + 5*i;
	}
	visited.resize(5);	
	for(int i = 0; i < 5; ++i){
		visited[i].resize(board[i].size(), false);
	}
	vector<pair<int, int> > horse;
	dfs(0, 0, horse, 4);
	cout << answer << "\n";
	return 0;
}