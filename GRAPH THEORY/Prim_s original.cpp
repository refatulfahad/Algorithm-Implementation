#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >g[1000];
bool vis[1000];

int prims(int u) {
    priority_queue<pair<int, int> > pq;
    int cost=0;
    pq.push({0, u});
    while(!pq.empty()) {
        u=pq.top().second;
        int w=abs(pq.top().first);
        pq.pop();
        if(!vis[u]) cost+=w;
        vis[u]=true;
        for(int i=0; i<g[u].size(); i++) {
            int v=g[u][i].second;
            int nw=g[u][i].first;
            if(!vis[v]) pq.push({-nw, v});
        }
    }
    return cost;
}

int main() {
    int vertex,edge;
    scanf("%d %d",&vertex,&edge);
    for(int i=1; i<=edge; i++) {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back(make_pair(w,v));
        g[v].push_back(make_pair(w,u));
    }
    printf("%d\n", prims(1));
    return 0;
}
