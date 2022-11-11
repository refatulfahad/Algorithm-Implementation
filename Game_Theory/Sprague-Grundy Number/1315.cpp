#include<bits/stdc++.h>
using namespace std;

int ar[505][505];

int preinit(int x,int y) {
    if(x<1||y<1)return -1;
    if(ar[x][y]!=-1)return ar[x][y];
    set<int>st;
    st.insert(preinit(x+1,y-2));
    st.insert(preinit(x-1,y-2));
    st.insert(preinit(x-1,y-3));
    st.insert(preinit(x-2,y-1));
    st.insert(preinit(x-2,y+1));
    st.insert(preinit(x-3,y-1));
    int cnt=0;
    while(st.count(cnt))cnt++;
    return ar[x][y]=cnt;
}
int main() {
    int test,n,x,y;
    memset(ar,-1,sizeof(ar));
    for(int i=1; i<=500; i++) {
        for(int j=1; j<=500; j++) {
            preinit(i,j);
            //cout<<ar[i][j]<<" ";
        }//cout<<endl;
    }

    scanf("%d",&test);
    for(int cs=1; cs<=test; ++cs) {
        scanf("%d",&n);
        int xo=0;
        for(int i=1; i<=n; i++) {
            scanf("%d %d",&x,&y);
            x++,y++;
            xo^=ar[x][y];
        }
        printf("Case %d: ",cs);
        if(xo>0) {
            printf("Alice\n");
        } else {
            printf("Bob\n");
        }
    }
    return 0;
}
