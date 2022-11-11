#include<bits/stdc++.h>
using namespace std;


int ar[2*100+5];
int main() {
    int test,k,xo;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++) {
        scanf("%d",&k);
        xo=0;
        for(int i=1; i<=2*k; i++) {
            scanf("%d",&ar[i]);
        }
        printf("Case %d: ",cs);
        for(int i=1; i<=2*k; i+=2) {
            xo^=(ar[i+1]-ar[i]-1);
        }
        if(xo>0) {
            printf("Alice\n");
        } else {
            printf("Bob\n");
        }
    }
    return 0;
}
