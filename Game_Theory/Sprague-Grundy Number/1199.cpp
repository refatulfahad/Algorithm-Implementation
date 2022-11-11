#include<bits/stdc++.h>
using namespace std;

int ar[10005],br[105];
int main() {
    int test,n;
    ar[0]=0,ar[1]=0,ar[2]=0;
    for(int i=3; i<=10000; ++i) {
        set<int>st;
        for(int j=1;; ++j) {
            if(j>=(i-j))break;
            st.insert(ar[j]^ar[i-j]);
        }
        int ck=0;
        while(st.count(ck)) {
            ck++;
        }
        ar[i]=ck;
    }
    scanf("%d",&test);
    for(int cs=1; cs<=test; ++cs) {
        scanf("%d",&n);
        int xo=0;
        for(int i=1; i<=n; ++i) {
            scanf("%d",&br[i]);
            xo^=ar[br[i]];
        }
        printf("Case %d: ",cs);
        if(xo>0) {
            printf("Alice");
        } else {
            printf("Bob");
        }
        //if(cs!=test)
            cout<<endl;
    }
    return 0;
}
