#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int ar[100][100],n,dp[100][100],r,c;

int minimum_path_sum(int i,int j) {
    // if(i==r+1&&j==c+1)return 0;
    //cout<<r<<" "<<c<<endl;
    if(i>r||j>c) {
        //cout<<1;
        return 1000;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int ans1,ans2;//=1000=1000
    if(i<=r&&j<=c) {
        ans1=ar[i][j];
        ans2=ar[i][j];
    }
    if(i<r||j<c) {
        ans1+=minimum_path_sum(i+1,j);
        //cout<<ans1<<" ";
    }
    if(i<r||j<c) {
        ans2+=minimum_path_sum(i,j+1);
        //cout<<ans2<<" ";
    }
    //cout<<min(ans1,ans2)<<endl;
    return dp[i][j]=min(ans1,ans2);
}
int main() {

    scanf("%d %d",&r,&c);
    memset(dp,-1,sizeof(dp));
    for(int i=1; i<=r; i++) {
        for(int j=1; j<=c; j++) {
            scanf("%d",&ar[i][j]);
        }
    }
    //cout<<ar[1][1]<<endl;
    cout<<minimum_path_sum(1,1)<<endl;
    return 0;
}
