#include<bits/stdc++.h>
using namespace std;

bool can[205];
int ar[205][105],n;
int chk[205],cnt=0;

bool check(int pre,int ck,int val) {
    for(int i=1; i<=n; i++) {
        if(ar[val][i]==pre&&chk[val]==pre) {
            return true;
        } else if(ar[val][i]==ck) {
            return false;
        }
    }
}
void stable_marriage() {
    int cnd;
    while(cnt<n) {
        for(cnd=1; cnd<=n; cnd++) {
            if(!can[cnd])break;
        }

        for(int j=1; j<=n&&!can[cnd]; j++) {
            int pre=chk[ar[cnd][j]];
            if(chk[ar[cnd][j]]==0) {
                chk[ar[cnd][j]]=cnd;
                can[cnd]=true;
                cnt++;

            } else if(!check(pre,cnd,ar[cnd][j])) {

                chk[ar[cnd][j]]=cnd;
                can[cnd]=true;
                can[pre]=false;
            }
        }
    }
}
int main() {
    int test,x;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++) {
        scanf("%d",&n);
        for(int i=1; i<=2*n; i++) {
            for(int j=1; j<=n; j++) {
                scanf("%d",&ar[i][j]);
            }
        }
        stable_marriage();
        printf("Case %d: ",cs);
        for(int i=n+1; i<=2*n; i++) {
            printf("(%d %d)",chk[i],i);
            if(i!=2*n)
                printf(" ");
        }
        for(int i=1; i<=2*n; i++) {
            chk[i]=0,can[i]=false;
        }
        cnt=0;
        printf("\n");
    }
    return 0;
}

/**
6 7 10 9 8
8 6 10 7 9
6 10 8 9 7
8 9 10 7 6
6 10 9 7 8
1 2 3 4 5
1 3 2 5 4
2 1 3 4 5
1 2 5 3 4
2 1 4 5 3
**/

