#include<bits/stdc++.h>
using namespace std;
int BIT[1000],n;
void Update(int pos,int value) {
    while(pos<=n) {
        BIT[pos]+=value;
        pos+=(pos&-pos);
    }
}
int query(int r) {
    int res=0;
    while(r>0) {
        res+=BIT[r];
        r-=(r&-r);
    }
    return res;
}
int main() {
    int x,r,l,value;
    scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        scanf("%d",&x);
        ///single update
        Update(i,x);
    }
    scanf("%d",&r);
    ///single query
    printf("%d\n",query(r));
    ///range query
    scanf("%d %d",&l,&r);
    printf("%d\n",query(r)-query(l-1));
    ///range update
    scanf("%d %d %d",&l,&r,&value);
    Update(l,value);
    Update(r+1,-value);
    return 0;
}
