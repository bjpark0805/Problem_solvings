#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector< pair<int, int> > warehouse;
long long area = 0;

void calculate_left_area(int begin, int end){	// begin = 1, end = max_index
	int temp_height = 0, temp_index = -1;
	for(int i = begin; i <= end; ++i){
		if(warehouse[i].second >= temp_height) {
			area += (long long) temp_height * (warehouse[i].first - warehouse[temp_index].first);
			temp_index = i;
			temp_height = warehouse[i].second;
		}
	}
}
void calculate_right_area(int begin, int end){	// begin = max_index, end = N
	int temp_height = 0, temp_index = -1;
	for(int i = end; i >= begin; --i){
		if(warehouse[i].second >= temp_height) {
			area += (long long) temp_height * (warehouse[temp_index].first - warehouse[i].first);
			temp_index = i;
			temp_height = warehouse[i].second;
		}
	}
}

int main(){
	int N;
	scanf("%d", &N);
	warehouse.resize(N + 1);
    for(int i = 1; i <= N; ++i){
        int x, h;
        scanf("%d%d",&x, &h);
        warehouse[N] = make_pair(x, h);
    }

    sort(warehouse.begin(), warehouse.end());
    
    // Find maximum height and its index of the warehouses.
    int max_height = -1, max_index = -1;
    for(int i = 1; i <= N; ++i){
    	if(warehouse[i].second > max_height){
    		max_height = warehouse[i].second;
    		max_index = i;
    	}
    }

    // Add left area from the maximum warehous.
    calculate_left_area(1, max_index);
    // Add right area from the maximum warehouse.
    calculate_right_area(max_index, N);
    // Add the maximum warehouse.
    area += max_height;

    printf("%lld\n", area);

    return 0;
}