#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
vector<pair<int,int>> locates;
int n;
int k;

int solveLinear(int begin, int end, int idx){
    int sum=0;
    while(begin<end-1){
        int maxc=-1;
        while(idx<k && locates[idx].first<=begin+1){
            maxc=max(maxc,locates[idx].second);
            ++idx;
        }
        if(maxc<=begin) return k;
        begin=maxc;
        //cout<<"maxc: "<<maxc<<endl;
        ++sum;
    }
    return sum;
}

int solve(){
    int ret=k+1;
    for(int i=0;i<k;++i){
        if(locates[i].first<0){
            int begin=locates[i].second;
            int end=n+1+locates[i].first;
            //cout<<"begin: "<<begin<<" end: "<<end<<endl;
            ret=min(ret,1+solveLinear(begin,end,i+1));
        }
        else if(locates[i].first==1){
            int begin=locates[i].second;
            int end=n+1;
            //cout<<"begin: "<<begin<<" end: "<<end<<endl;
            ret=min(ret,1+solveLinear(begin,end,i+1));
        }
        else
            break;
    }
    return ret;
}

int main(){
    scanf("%d %d",&n,&k);
    for(int i=0;i<k;++i){
        int a,b;
        scanf("%d %d",&a,&b);
        if(a>b) a-=n+1;
        locates.push_back(make_pair(a,b));
    }
    sort(locates.begin(), locates.end());
    int result=solve();
    if(result>k)
        printf("impossible\n");
    else
        printf("%d\n",result);
}