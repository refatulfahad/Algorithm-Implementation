#include<bits/stdc++.h>
using namespace std;
vector<int>a[100];
int n,m,j=0,x,y,s,p;
queue<int>q;
int c[100],v[100];
void bfs(int s,int n) {
    q.push(s);
    c[s]=0;
    v[s]=1;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        for(int i=0; i<a[u].size(); i++) {
            if(v[a[u][i]]==0) {
                v[a[u][i]]=1;
                p=a[u][i];
                c[p]=c[u]+1;
                q.push(p);
                cout<<p<<":"<<c[p]<<endl;
            }
        }
    }
    cout<<endl;
}
int main() {

    cin>>n>>m;
    for(int i=0; i<m; i++) {
        cin>>x>>y;
        if(i==0) {
            s=x;
        }
        a[x].push_back(y);
        a[y].push_back(x);
    }
    bfs(s,n);
    /***while(j<=n){
         cout<<j<<" :";
     for( int i=0;i<a[j].size();i++){
         cout<<a[j][i]<<" ";
     }
     cout<<endl;
     j++;
    }*********/

}
/********************bfs*************************
#include<bits/stdc++.h>

using namespace std;
vector<int>adj[1000];
queue<int>q;
int vis[1000];
void bfs(int s,int v){
    for(int i=0;i<v;i++)vis[i]=0;
   q.push(s);
   vis[s]=1;

   while(!q.empty()){
      int u=q.front();
      q.pop();
      for(int i=0;i<adj[u].size();i++){
        if(!vis[adj[u][i]]){
            int v=adj[u][i];
            cout<<v<<" ";
            vis[v]=1;
            q.push(v);
        }
      }
      cout<<endl;
   }
}
int main()
{
    int v,e,x,y,s;
    cin>>v>>e;
    for(int i=0;i<e;i++){
        cin>>x>>y;
        if(i==0)
            s=x;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bfs(s,v);
    return 0;
}************************/
