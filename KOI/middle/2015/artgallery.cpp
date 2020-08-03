#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>
using namespace std;
const double PI = 2.0 * acos(0.0);
vector<long long> path;

struct vector2{
	long long x, y;

	explicit vector2(long long x_ = 0, long long y_ = 0): x(x_), y(y_) {}
	bool operator == (const vector2& rhs) const {
		return x == rhs.x && y == rhs.y;
	}
	bool operator < (const vector2& rhs) const {
		return x != rhs.x ? x < rhs.x : y < rhs.y;
	}
	vector2 operator + (const vector2& rhs) const {
		return vector2(x + rhs.x, y + rhs.y);
	}
	vector2 operator - (const vector2& rhs) const {
		return vector2(x - rhs.x, y - rhs.y);
	}
	// vector2 operator * (double rhs) const {
	// 	return vector2(x + rhs, y + rhs);
	// }

	long long norm() const {return x * x + y * y;} 

	// vector2 normalize() const {
	// 	return vector2((int)(x / norm()), (int)(y/norm()));
	// }

	// double polar() const {return fmod(atan2(y, x) + 2*PI, 2*PI);}

	long long dot(const vector2& rhs) const {
		return x * rhs.x + y * rhs.y;
	}
	
	// vector2 project(const vector2& rhs) const {
	// 	vector2 r = rhs.normalize();
	// 	return r * r.dot(*this);
	// }
	long long cross(const vector2& rhs) const {
		return x * rhs.y - rhs.x * y;
	}
};
vector<vector2> points;

long long ccw(vector2 a, vector2 b){
	return a.cross(b);
}
long long ccw(vector2 p, vector2 a, vector2 b){
	return ccw(a - p, b - p);
}

// void find_path(int start, int end){
// 	if(start > end){
// 		find_path(end, start);
// 		return;
// 	}
// 	path.push_back(start);
// 	if(start + 1 == end) {
// 		path.push_back(end);
// 		return;
// 	}
// 	vector2 pivot = points[start], next = points[start + 1], 
// 	nextnext = points[start + 2];
// 	int most_left = start + 1, second_left = start + 2;

// 	for(int i = start + 2; i <= end; ++i){
// 		long long cross = ccw(pivot, next, points[i]);
// 		long long dist = (next - pivot).norm() - (points[i] - pivot).norm();
// 		if((cross > 0 && ccw(pivot, points[i-1], points[i]) > 0)|| (cross == 0 && dist < 0 && most_left != end)) {
// 			next = points[i];
// 			most_left = i;
// 		}
// 	}
// 	if(most_left == end) {
// 		path.push_back(end);
// 		return;
// 	}
// 	find_path(most_left, end);
// }
void find_path(int start, int end){
	path.push_back(start);
	path.push_back(start + 1);
	if(start + 1 == end) return;
	int first, second, next = start + 2;
	while(next <= end){
		while(path.size() >= 2){
			second = path.back();
			path.pop_back();
			first = path.back();

			vector2 vf = points[first];
			vector2 vs = points[second];
			vector2 vn = points[next];

			if(ccw(vs, vn, vf) < 0) {
				path.push_back(second);
				break;
			}
		}
		path.push_back(next++);
	}
}

int main(){
	int n;
	cin >> n;
	long long x0, y0;
	scanf("%lld%lld", &x0, &y0);
	points.push_back(vector2(x0, y0));
	for (int i = 1; i < n; ++i){
		long long x, y;
		scanf("%lld%lld", &x, &y);
		points.push_back(vector2(x, y));
	}
	points.push_back(vector2(x0, y0));
	int i, j;
	cin >> i >> j;

	// start from i to j
	if(i == 0){
		i = n;
	}else if(j == 0){
		j = n;
	}
	bool swap_ = false;
	if(i > j){
		swap(i, j);
		swap_ = true;
	} 
	
	find_path(i, j);
	

	int m = path.size();
	cout <<  m << endl;
	if(swap_){
		for(int i = m - 1; i >= 0; --i){
			printf("%lld ", path[i]%n); 
		}
	}else{
		for(int i = 0; i < m; ++i){
			printf("%lld ", path[i]%n); 
		}
	}
	printf("\n");
	return 0;
}

