#include<bits/stdc++.h>
using namespace std;

///Author:Refat(BSMRSTU)///

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define pil pair<int,ll>
const int N = 1e5 + 5;
const int M = 1e9 + 7;
int Set(int N,int pos) {
    return N=N | (1<<pos);
}
int reset(int N,int pos) {
    return N= N & ~(1<<pos);
}
bool check(int N,int pos) {
    return (bool)(N & (1<<pos));
}
int ar[N],br[N],mark=0;
vector<int>vertex[N],components[N];
bool visit[N];
stack<int>st;
void dfs(int node) {
    visit[node]=true;
    for(int i=0; i<vertex[node].size(); i++) {
        int b=vertex[node][i];
        if(!visit[b]) {
            //cout<<node<<" "<<b<<endl;
            dfs(b);
        }
    }
    st.push(node);
}
void dfs1(int node,int mark) {
    visit[node]=true;
    components[mark].pb(node);
    for(int i=0; i<vertex[node].size(); i++) {
        int b=vertex[node][i];
        if(!visit[b]) {
            //cout<<node<<" "<<b<<endl;
            dfs1(b,mark);
        }
    }

}
int main() {
    /// freopen("input.txt","r",stdin);
    /// freopen("output.txt","w",stdout);
    int node,edge,u;
    scanf("%d %d",&node,&edge);
    for(int i=1; i<=edge; i++) {
        scanf("%d %d",&ar[i],&br[i]);
        vertex[ar[i]].pb(br[i]);
    }
    for(int i=1; i<=node; i++) {
        if(!visit[i]) {
            dfs(i);
        }
    }
    for(int i=1; i<=node; i++) {
        vertex[i].clear();
    }
    for(int i=1; i<=edge; i++) {
        vertex[br[i]].pb(ar[i]);
        visit[i]=false;
    }
    while(!st.empty()) {
        u=st.top();
        st.pop();
        if(!visit[u]) {
            mark+=1;
            dfs1(u,mark);
        }
    }
    cout<<mark<<endl;
    return 0;
}
