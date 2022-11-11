#include<bits/stdc++.h>
using namespace std;
#define ll             long long
#define vi             vector<int>
#define FOR(x, l, r)   for (int x = l; x <= r; ++x)
#define RFOR(x, l, r)   for (int x = l; x >= r; --x)

const int N = (int) 2e5 + 5;
const int INF = (int) 1e9 + 7;
int ini() {
    int x;
    scanf("%d",&x);
    return x;
}
long long inl() {
    long long x;
    scanf("%lld",&x);
    return x;
}


struct Edge {
    int u;
    int v;
    int w;
};

Edge E[100];
int par[109];
bool compare(Edge A,Edge B) {
    return A.w<B.w;
}
int findroot(int x) {
    if(par[x]==x)return x;
    return par[x]=findroot(par[x]);
}
int kruskal(int n) {
    sort(E,E+n,compare);
    int ans=0;

    for(int i=0; i<n; i++) {
        if(findroot(E[i].u)!=findroot(E[i].v)) {
            par[par[E[i].u]]=par[E[i].v];
            ans+=E[i].w;
        }
    }
    return ans;
}

int main() {
    int t;
    t=ini();
    while(t--) {
        int e,n;
        n=ini();
        e=ini();
        for(int i=1; i<=n; i++)par[i]=i;
        for(int i=0; i<e; i++) {
            int x,y,z;
            cin>>x>>y>>z;
            E[i].u=x;
            E[i].v=y;
            E[i].w=z;

        }
        cout<<kruskal(e)<<endl;;
    }


    return 0;
}
