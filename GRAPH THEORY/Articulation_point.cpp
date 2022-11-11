/*#include<bits/stdc++.h>
using namespace std;
vector<int>vertex[1000],art_point;
bool visit[10000],point[1000];
int low[1000],dis[1000],parent[1000],t;
void articulation_point(int u) {
    visit[u]=true;
    t++;
    dis[u]=t;

    low[u]=dis[u];
    int no_children=0;
    for(int i=0; i<vertex[u].size(); i++) {
        int v=vertex[u][i];
        cout<<vertex[u].size()<<" "<<u<<endl;
        if(v==parent[u])continue;
        if(!visit[v]) {
            parent[v]=u;
            no_children++;
            articulation_point(v);
            low[u]=min(low[u],low[v]);
            if(dis[u]<=low[v]&&parent[u]!=0&&!point[u]) {
                point[u]=true,art_point.push_back(u);
            }
        } else {
            low[u]=min(low[u],dis[v]);
            //cout<<u<<" "<<v<<" ";
        }
    }
    if(parent[u]==0&&no_children>1&&!point[u]) {
        point[u]=true,art_point.push_back(u);
    }
}
int main() {
    int n,edge,u,v;
    scanf("%d %d",&n,&edge);
    for(int i=1; i<=edge; i++) {
        scanf("%d %d",&u,&v);
        vertex[u].push_back(v);
        vertex[v].push_back(u);
    }
    for(int i=0; i<n; i++) {
        if(!visit[i]) {
            articulation_point(i);
        }
    }
    if(art_point.size()!=0) {
        for(int i=0; i<art_point.size(); i++) {
            //cout<<art_point[i];
            if(i<art_point.size()-1)
                printf(" ");
        }
    } else {
        printf("biconnected graph");
    }
    return 0;
}*/

#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
vector<int>adj[N];
bool vis[N],articu_point[N];
int low[N],dis[N],t,OutComingEdge=0;
void dfs(int root,int u,int parent) {
    if(root==u)++OutComingEdge;
    vis[u]=true;
    t++;
    dis[u]=t;
    low[u]=dis[u];

    for(int v:adj[u]) {

        //cout<<vertex[u].size()<<" "<<u<<endl;
        if(v==parent)continue;
        if(!vis[v]) {
            dfs(root,v,u);
            low[u]=min(low[u],low[v]);
            if(dis[u]<=low[v]) {
                articu_point[u]=true;
            }
        } else {
            low[u]=min(low[u],dis[v]);
            //cout<<u<<" "<<v<<" ";
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
            //(root,node,parent)
            dfs(i,i,-1);
            articu_point[i]=(OutComingEdge>1);
        }
    }
    for(int i=0; i<n; ++i) {
        if(articu_point[i]) {
            cout<<"articulation_point  :"<<i<<'\n';
        }
    }
    return 0;
}

