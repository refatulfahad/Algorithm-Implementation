#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
vector<int>adj[N];
vector<pair<int,int> >articu_bridge;
bool vis[N],point[N];
int low_link[N],dis[N],parent[N],t;


void dfs(int u,int parent) {
    vis[u]=true;
    t++;
    //dis[u]=t;
    low_link[u]=dis[u]=t;

    for(int v:adj[u]) {

        //cout<<vertex[u].size()<<" "<<u<<" "<<v<<endl;
        if(v==parent) continue;
        if(!vis[v]) {
            dfs(v,u);
            low_link[u]=min(low_link[u],low_link[v]);
            if(dis[u]<low_link[v]) {
                articu_bridge.push_back({u,v});
            }
        } else {
            low_link[u]=min(low_link[u],dis[v]);
        }

    }

}
int main() {
    int n,edge,u,v;
    scanf("%d %d",&n,&edge);
    for(int i=1; i<=edge; i++) {
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            dfs(i,-1);
        }
    }
    for(int i=0; i<articu_bridge.size(); i++) {
        cout<<articu_bridge[i].first<<" "<<articu_bridge[i].second<<endl;

    }
    return 0;
}

