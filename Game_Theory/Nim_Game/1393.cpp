#include<bits/stdc++.h>
using namespace std;


int main() {
    int test,r,c,xo;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++) {
        scanf("%d %d",&r,&c);
        xo=0;
        int ar[r+5][c+5];
        for(int i=1; i<=r; i++) {
            for(int j=1; j<=c; j++) {
                scanf("%d",&ar[i][j]);
            }
        }
        bool ck=false;
        int cnt=0;
        for(int i=r; i>=1; i--) {
            cnt++;
            if(cnt%2)ck=true;
            else ck=false;
            for(int j=c; j>=1; j--) {
                if(!ck) {
                    xo^=ar[i][j];
                    ck=true;
                } else {
                    ck=false;
                }
            }
        }
        printf("Case %d: ",cs);
        if(xo>0) {
            printf("win\n");
        } else {
            printf("lose\n");
        }
    }
    return 0;
}
