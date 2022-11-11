#include<bits/stdc++.h>
using namespace std;

int main() {
    int test,n,m,x,sum,ans;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++) {
        scanf("%d %d",&n,&m);
        ans=0;
        for(int i=1; i<=n; i++) {
            sum=0;
            for(int j=1; j<=m; j++) {
                scanf("%d",&x);
                sum+=x;
            }
            ans^=sum;
        }
        printf("Case %d: ",cs);
        if(ans!=0) {
            printf("Alice\n");
        } else {
            printf("Bob\n");
        }
    }
}
