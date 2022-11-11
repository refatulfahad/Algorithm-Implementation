#include<bits/stdc++.h>
using namespace std;

vector<int>vertex[100005];
int par[100005],dp[100005][5];

int fun(int node,int chk) {

    if(vertex[node].size()==0) {
        return 0;
    }
    if(dp[node][chk]!=-1) {
        return dp[node][chk];
    }
    int sum=0;

    for(int v:vertex[node]) {
        if(par[node]!=v) {
            par[v]=node;
            if(!chk) {
                sum+=fun(v,1);
            } else {
                sum+=min(fun(v,1),fun(v,0));
            }
        }
    }

    return dp[node][chk]=sum+chk;
}
int main() {
    int n,y,x;
    scanf("%d",&n);
    memset(dp,-1,sizeof(dp));
    for(int i=1; i<n; i++) {
        scanf("%d %d",&x,&y);
        vertex[y].push_back(x);
        vertex[x].push_back(y);
    }
    int mn1=fun(1,1);
    //memset(dp,-1,sizeof(dp));

    int mn2=fun(1,0);
    //cout<<mn1;
    printf("%d\n",max(1,min(mn1,mn2)));
    return 0;
}



