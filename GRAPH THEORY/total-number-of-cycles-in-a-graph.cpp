#include<bits/stdc++.h>

using namespace std;

vector<int>adj[109];
int color[109],par[109];
int cycle;
void dfs(int u,int p){
    if(color[u]==2)return;

    if(color[u]==1){
        cycle++;
        return;
    }
    par[u]=p;
    color[u]=1;

    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i];

        if(v==par[u])
            continue;
        dfs(v,u);
    }
    color[u]=2;
}
int main()
{
    int n,m;

    cin>>n>>m;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cycle=0;

    dfs(1,0);

    cout<<cycle<<endl;

    return 0;
}
