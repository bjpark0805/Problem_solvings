// 4시간 35분
// 푸는데 대략 2시간
// 디버깅 2시간 반
// 그냥 시뮬레이션 문제라 문제 조건 그대로 따라가는게 맞을 듯. 다른 생각하지 말고
// 틀린 부분은 회전할때 내가 정해놓은 방향에 따라서 해당 면 회전 방향이 달라진다는 것. 
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<string> > cube(6, vector<string>(3, ""));

void initalize_cube(){
	string color[6] = {"www", "yyy", "rrr", "ooo", "ggg", "bbb"};
	for(int i = 0; i < 6; ++i){
		for(int j = 0; j < 3; ++j){
			cube[i][j] = color[i];
		}
	}
}

void rotate_d(int d, int num){
	vector<string> temp = cube[num];
	if(d == 0){ // left
		for(int i = 0; i < 3; ++i){
			for(int j = 0; j < 3; ++j){
				cube[num][2-j][i]= temp[i][j]; 
			}
		}
	}
	else{ //right
		for(int i = 0; i < 3; ++i){
			for(int j = 0; j < 3; ++j){
				cube[num][j][2-i]= temp[i][j]; 
			}
		}
	}
}

void rotate_cube(string command){
	int d = 1, num;
	if(command[1] == '-') d = 0;
	// "UDFBLR"
	if(command[0] == 'U'){
		num = 0;
		rotate_d(d, num);
		string temp[6] = {"", "", cube[2][0], cube[3][0], cube[4][0], cube[5][0]};
		if(command[1] == '-'){
			cube[5][0] = temp[2];
			cube[4][0] = temp[3];
			for(int i = 0; i < 3; ++i){
				cube[3][0][2-i] = temp[5][i];
				cube[2][0][2-i] = temp[4][i];
			}
		}
		else{
			cube[2][0] = temp[5];
			cube[3][0] = temp[4];
			for(int i = 0; i < 3; ++i){
				cube[5][0][2-i] = temp[3][i];
				cube[4][0][2-i] = temp[2][i];
			}
		}
	}
	else if(command[0] == 'D'){
		num = 1;
		rotate_d(1-d, num);
		string temp[6] = {"", "", cube[2][2], cube[3][2], cube[4][2], cube[5][2]};
		if(command[1] == '-'){
			cube[2][2] = temp[5];
			cube[3][2] = temp[4];
			for(int i = 0; i < 3; ++i){
				cube[5][2][2-i] = temp[3][i];
				cube[4][2][2-i] = temp[2][i];
			}
		}
		else{
			cube[5][2] = temp[2];
			cube[4][2] = temp[3];
			for(int i = 0; i < 3; ++i){
				cube[3][2][2-i] = temp[5][i];
				cube[2][2][2-i] = temp[4][i];
			}
		}
	}
	else if(command[0] == 'F'){
		num = 2;
		rotate_d(d, num);
		char temp[6][3] = {
			{cube[0][2][0], cube[0][2][1], cube[0][2][2]}, 
			{cube[1][2][0],cube[1][2][1],cube[1][2][2]}, 
			{'a','a','a'}, {'a','a','a'}, 
			{cube[4][0][0],cube[4][1][0],cube[4][2][0]}, 
			{cube[5][0][0],cube[5][1][0],cube[5][2][0]}
		};
		if(command[1] == '-'){
			for(int i = 0; i < 3; ++i){
				cube[4][2-i][0] = temp[0][i];
				cube[0][2][i] = temp[5][i];
				cube[5][2-i][0] = temp[1][i];
				cube[1][2][i] = temp[4][i];
			}
		}
		else{
			for(int i = 0; i < 3; ++i){
				cube[5][i][0] = temp[0][i];
				cube[1][2][2-i] = temp[5][i];
				cube[4][i][0] = temp[1][i];
				cube[0][2][2-i] = temp[4][i];
			}
		}
	}
	else if(command[0] == 'B'){
		num = 3;
		rotate_d(1-d, num);
		char temp[6][3] = {
			{cube[0][0][0], cube[0][0][1], cube[0][0][2]}, 
			{cube[1][0][0],cube[1][0][1],cube[1][0][2]}, 
			{'a','a','a'}, {'a','a','a'}, 
			{cube[4][0][2],cube[4][1][2],cube[4][2][2]}, 
			{cube[5][0][2],cube[5][1][2],cube[5][2][2]}
		};
		if(command[1] == '-'){
			for(int i = 0; i < 3; ++i){
				cube[5][i][2] = temp[0][i];
				cube[1][0][2-i] = temp[5][i];
				cube[4][i][2] = temp[1][i];
				cube[0][0][2-i] = temp[4][i];
			}
		}
		else{
			for(int i = 0; i < 3; ++i){
				cube[4][2-i][2] = temp[0][i];
				cube[0][0][i] = temp[5][i];
				cube[5][2-i][2] = temp[1][i];
				cube[1][0][i] = temp[4][i];
			}
		}
	}
	else if(command[0] == 'L'){
		num = 4;
		rotate_d(1-d, num);
		char temp[4][3] = {
			{cube[0][0][0],cube[0][1][0],cube[0][2][0]}, 
			{cube[1][0][0],cube[1][1][0],cube[1][2][0]}, 
			{cube[2][0][0],cube[2][1][0],cube[2][2][0]}, 
			{cube[3][0][0], cube[3][1][0], cube[3][2][0]}
		};

		if(command[1] == '-'){
			for(int i = 0; i < 3; ++i){
				cube[3][2-i][0] = temp[0][i];
				cube[1][i][0] = temp[3][i];
				cube[2][2-i][0] = temp[1][i];
				cube[0][i][0] = temp[2][i];
			}
		}
		else{
			for(int i = 0; i < 3; ++i){
				cube[2][i][0] = temp[0][i];
				cube[1][2-i][0] = temp[2][i];
				cube[3][i][0] = temp[1][i];
				cube[0][2-i][0] = temp[3][i];
			}
		}
	}
	else{ // R
		num = 5;
		rotate_d(d, num);
		char temp[4][3] = {
			{cube[0][0][2],cube[0][1][2],cube[0][2][2]}, 
			{cube[1][0][2],cube[1][1][2],cube[1][2][2]}, 
			{cube[2][0][2],cube[2][1][2],cube[2][2][2]}, 
			{cube[3][0][2], cube[3][1][2], cube[3][2][2]}
		};
		if(command[1] == '-'){
			for(int i = 0; i < 3; ++i){
				cube[2][i][2] = temp[0][i];
				cube[1][2-i][2] = temp[2][i];
				cube[3][i][2] = temp[1][i];
				cube[0][2-i][2] = temp[3][i];
			}
		}
		else{
			for(int i = 0; i < 3; ++i){
				cube[3][2-i][2] = temp[0][i];
				cube[1][i][2] = temp[3][i];
				cube[2][2-i][2] = temp[1][i];
				cube[0][i][2] = temp[2][i];
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, N;
	string cmd;
	cin >> T;
	for(int i = 0; i < T; ++i){
		initalize_cube();
		// cout << cube[0][0] << "\n" << cube[0][1] << "\n" << cube[0][2] << "\n";
		cin >> N;
		for(int j = 0; j < N; ++j){
			cin >> cmd;
			rotate_cube(cmd);
		}
		// cout << "-0-" << "\n";
		cout << cube[0][0] << "\n" << cube[0][1] << "\n" << cube[0][2] << "\n";
		// cout << "-3-" << "\n";
		// cout << cube[3][0] << "\n" << cube[3][1] << "\n" << cube[3][2] << "\n";
		// cout << "-4-" << "\n";
		// cout << cube[4][0] << "\n" << cube[4][1] << "\n" << cube[4][2] << "\n";
		// cout << "-5-" << "\n";
		// cout << cube[5][0] << "\n" << cube[5][1] << "\n" << cube[5][2] << "\n";
		// cout << "-2-" << "\n";
		// cout << cube[2][0] << "\n" << cube[2][1] << "\n" << cube[2][2] << "\n";
		// cout << "-1-" << "\n";
		// cout << cube[1][0] << "\n" << cube[1][1] << "\n" << cube[1][2] << "\n";
	}
	return 0;
}