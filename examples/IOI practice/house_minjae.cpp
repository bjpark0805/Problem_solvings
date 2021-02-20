#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <stdio.h>
using namespace std;
int n;
long long sum;
vector<pair<int,int>> stru;
vector<int> height;
void cal_left(int start, int maxi){
    int tempmax=stru[start].second, tempi=start;
    for(int i=start+1; i<=maxi;++i){
        if(tempmax<=stru[i].second){
            sum+=(stru[i].first-stru[tempi].first)*tempmax;
            tempmax=stru[i].second;
            tempi=i;
        }
    }
}
void cal_right(int maxi, int end){
    int tempmax=stru[end].second, tempi=end;
    for(int i=end-1; i>=maxi;--i){
        if(tempmax<=stru[i].second){
            sum+=(stru[tempi].first-stru[i].first)*tempmax;
            tempmax=stru[i].second;
            tempi=i;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        int a,b;scanf("%d %d",&a,&b);
        stru.push_back(make_pair(a,b));
    }
    sort(stru.begin(), stru.end());
    int temph=0;
    int maxi;
    for(int i=0;i<n;++i){
        if(stru[i].second>temph){
            maxi=i;
            temph=stru[i].second;
        }
    }
    cal_left(0,maxi);
    cal_right(maxi,n-1);
    sum+=stru[maxi].second;
    cout<<sum;
}