#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int>vec[10000];
bool visit[10000];
int capacity[1000][1000],par[10000],flow_res=0;
ll bfs(int node,int source,int sink)
{
    for(int i=1; i<=node; i++)
    {
        par[i]=0;
        visit[i]=false;
    }
    queue<int>q;
    q.push(source);
    visit[source]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(u==sink)
        {
            return true;
        }
        for(int i=0; i<vec[u].size(); i++)
        {
            int adj=vec[u][i];
            if(!visit[adj]&&capacity[u][adj]>0)
            {
                visit[adj]=true;
                q.push(adj);
                par[adj]=u;
            }
        }
    }
    return false;
}
ll maxflow(int node,int source,int sink)
{
    int v,u,flow;
    while(bfs(node,source,sink))
    {
        v=sink;
        flow=INT_MAX;
        while(par[v])
        {
            u=par[v];
            flow=min(flow,capacity[u][v]);
            v=u;
        }
        v=sink;
        flow_res+=flow;
        while(par[v])
        {
            u=par[v];
            capacity[u][v]-=flow;
            capacity[v][u]+=flow;
            v=u;
        }
    }
    return flow_res;
}
int main()
{
    int node,edge,u,v,w,source,sink;
    scanf("%d %d",&node,&edge);
    for(int i=1; i<=edge; i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        vec[u].push_back(v);
        vec[v].push_back(u);
        capacity[u][v]=w;
    }
    scanf("%d %d",&source,&sink);
    printf("Maximum Flow per Unit=%d",maxflow(node,source,sink));
    return 0;
}
