#include<bits/stdc++.h>
using namespace std;
int ar[15][15],cl[15],rw[15],N;
int check(int row,int col) {
    if(cl[col])return 1;
    if(rw[row])return 1;
    for(int i=row,j=col; i>=1&&j>=1; i--,j--) {
        if(ar[i][j]==1) {
            return 1;   //cout<<i<<j<<" ";
        }
    }
    for(int i=row,j=col; i>=1&&j<=N; i--,j++) {
        if(ar[i][j])return 1;
    }
    for(int i=row,j=col; i<=N&&j>=1; i++,j--) {
        if(ar[i][j])return 1;
    }
    for(int i=row,j=col; i<=N&&j<=N; i++,j++) {
        if(ar[i][j])return 1;
    }
    return 0;
}
int queen_solve(int n) {
    if(n==0)return 1;//cout<<1;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(check(i,j)==1) {
                //if(n==1)
                //cout<<i<<j<<" ";
                continue;
            }
            ar[i][j]=1;
            cl[j]=1;
            rw[i]=1;
            if(queen_solve(n-1)==1) {
                return 1;
            } //
            ar[i][j]=0;
            cl[j]=0;
            rw[i]=0;
            //cout<<1;
        }
    }
    return 0;
}
int main() {

    scanf("%d",&N);
    bool ck=queen_solve(N);
    if(ck) {
        printf("YES\n");
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++) {
                printf("%d ",ar[i][j]);
            }
            cout<<endl;
        }
    } else {
        printf("NO\n");
    }
    return 0;
}
