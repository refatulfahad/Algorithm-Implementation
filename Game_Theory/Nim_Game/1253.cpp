#include<bits/stdc++.h>
using namespace std;


int main() {
    int test,n,x;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++) {
        scanf("%d",&n);
        bool ck=true;
        int xo=0;
        for(int i=1; i<=n; i++) {
            scanf("%d",&x);
            xo^=x;
            if(x!=1)ck=false;
        }
        printf("Case %d: ",cs);
        if(!ck) {
            if(xo>0) {
                printf("Alice\n");
            } else {
                printf("Bob\n");
            }
        } else {
            if(n%2) {
                printf("Bob\n");
            } else {
                printf("Alice\n");
            }
        }
    }
    return 0;
}
