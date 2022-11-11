#include<bits/stdc++.h>
using namespace std;
vector<int>vertex[10000];
bool visit[100];
int c=0;
void dfs(int node) {
    visit[node]=true;
    for(int x:vertex[node]) {
        if(!visit[x]) {
            dfs(x);
        }
    }
}
int main() {
    int n,e,x,y,s;
    scanf("%d %d",&n,&e);
    for(int i=0; i<e; i++) {
        cin>>x>>y;
        if(i==0) {
            s=x;
        }
        vertex[x].push_back(y);
        vertex[y].push_back(x);
    }
    for(int i=s; i<n; i++) {
        if(!visit[i]) {
            c++;
            dfs(i);
        }
    }
    //cout<<c;
    ///cout<<v[1];
    return 0;
}
/*****************dfs*****************
#include<bits/stdc++.h>

using namespace std;
#define M 100000
vector<int>ve[M];
vector<bool>vis;

void dfs(int n){
    vis[n]=true;
    for(int i=0;i<ve[i].size();i++){
        int e=ve[n][i];
        if(!vis[e])
            dfs(e);
    }
}
int main()
{
    int n,e,i,j,x,y;
    cin>>n>>e;

    for(i=0;i<e;i++){
        cin>>x>>y;
        ve[x].push_back(y);
        ve[y].push_back(x);
    }
    int c=0;
    for(int i=1;i<=e;i++){
        if(!vis[i]){
            c++;
            dfs(i);
        }
    }
    cout<<c<<endl;
    return 0;
}************************************/
