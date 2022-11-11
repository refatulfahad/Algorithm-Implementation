#include<bits/stdc++.h>
using namespace std;


int main() {
    int test,n,x;
    scanf("%d",&test);
    for(int cs=1; cs<=test; ++cs) {
        scanf("%d",&n);
        int ans=0;
        for(int i=1; i<=n; ++i) {
            scanf("%d",&x);
            if(!(x%2)) {
                x/=2;
            } else {
                while(x%2) {
                    if(x==1) {
                        x=0;
                        break;
                    }
                    x/=2;
                    if(!(x%2)) {
                        x/=2;
                        break;
                    }
                }
            }
            ans^=x;
        }
        printf("Case %d: ",cs);
        if(ans>0) {
            printf("Alice");
        } else {
            printf("Bob");
        }
        //if(cs!=test)
            cout<<endl;
    }
    return 0;
}
