#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100
#define MAX_W 1000
int n;
int dp[MAX_N+1][MAX_W+1],ar[1000];
int weight[MAX_N+1];
int cost[MAX_N+1];
int CAP;
int func(int i,int w) {
    if(i==n+1) return 0;
    if(dp[i][w]!=-1) return dp[i][w];
    int profit1=0,profit2=0;
    if(w+weight[i]<=CAP)
        profit1=cost[i]+func(i+1,w+weight[i]);

    profit2=func(i+1,w);
    if(profit1>profit2)ar[i]=weight[i];
    else ar[i+1]=weight[i+1];
    dp[i][w]=max(profit1,profit2);
    return dp[i][w];
}
int main() {

    //freopen("in","r",stdin);
    memset(dp,-1,sizeof(dp));
    scanf("%d%d",&n,&CAP);
    for(int i=1; i<=n; i++) {
        scanf("%d %d",&weight[i],&cost[i]);
    }
    printf("%d\n",func(1,0));
    return 0;
}


/*** Brute force solution for knapsack ***********/
/*#include<bits/stdc++.h>
using namespace std;
int ar[500][10000],profit[100005],weight[100005];
int main() {
    int n,cap,sum=0,mx=0;
    scanf("%d %d",&n,&cap);
    for(int i=1; i<=n; i++) {
        scanf("%d %d",&weight[i],&profit[i]);
    }
    for(int i=0; i<=n; i++) {
        for(int w=0; w<=cap; w++) {
            if(i==0)ar[i][w]=0;
            else if(weight[i]<=w) {
                ar[i][w]=max(ar[i-1][w],ar[i-1][w-weight[i]]+profit[i]);

                //cout<<ar[i][w]<<" ";
            } else {
                ar[i][w]=ar[i-1][w];
                //cout<<ar[i][w]<<" ";
            }
        }
        cout<<endl;
    }
    printf("%d\n",ar[n][cap]);
    int ii=n,jj=cap;
    //cout<<"weight"<<"  "<<"yes/no"<<endl;
    while(ii>0) {
        if(ar[ii][jj]==ar[ii-1][jj]) {
            //cout<<ii<<"  "<<0<<endl;
            ii--;
        } else {
            cout<<ii<<"  "<<1<<endl;
            jj-=weight[ii];
            ii--;
        }
    }
    return 0;
}*/
