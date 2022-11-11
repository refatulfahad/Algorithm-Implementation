#include<bits/stdc++.h>
using namespace std;
int r[10000],v[10000];
int n,p[100000],m,x,y,l,s=0,z;
void parent(int n) {
    for(int i=0; i<n; i++) {
        p[i]=i;
    }
}
struct abc {
    int u,v,w;
} ;
abc e[1000];
int rcheck(int a) {
    if(p[a]!=a) {
        return p[a]=rcheck(p[a]);
    } else {
        return a;
    }
}
bool compare(abc a,abc b) {
    return a.w<b.w;
}
int fun(int n) {
    sort(e,e+n,compare);
    for(int i=0; i<n; i++) {
        int px=rcheck(e[i].u);
        int py=rcheck(e[i].v);
        if(px!=py) {
            p[py]=px;
            cout<<"n ="<<e[i].w<<endl;
            s+=e[i].w;
        }
    }
    return s;
}
int main() {
    scanf("%d",&n);
    scanf("%d",&m);
    parent(n);

    for(int i=0; i<m; i++) {
        cin>>x>>y>>z;
        e[i].u=x;
        e[i].v=y;
        e[i].w=z;
    }
    fun(m);
    cout<<s;
    return 0;
}
