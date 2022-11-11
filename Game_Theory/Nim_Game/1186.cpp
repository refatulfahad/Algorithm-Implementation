#include<bits/stdc++.h>
using namespace std;

int ar[105],br[105];
int main() {
    int test,n,xo;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++) {
        scanf("%d",&n);
        xo=0;
        for(int i=1; i<=n; i++) {
            scanf("%d",&ar[i]);
        }
        for(int j=1; j<=n; j++) {
            scanf("%d",&br[j]);
        }
        for(int i=1; i<=n; i++) {
            xo^=(br[i]-ar[i]-1);
        }
        printf("Case %d: ",cs);
        if(xo>0) {
            printf("white wins\n");
        } else {
            printf("black wins\n");
        }
    }
    return 0;
}
