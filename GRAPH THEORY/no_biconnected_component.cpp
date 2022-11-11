#include<bits/stdc++.h>
using namespace std;
vector<int>vertex[1000],art_point;
bool visit[10000],point[1000];
int low[1000],dis[1000],parent[1000],t;
stack<int>st,ts;
void articulation_point(int u) {
    visit[u]=true;
    t++;
    dis[u]=t;
    low[u]=dis[u];
    int no_children=0,u1,v1;
    for(int i=0; i<vertex[u].size(); i++) {
        int v=vertex[u][i];
        if(v==parent[u])continue;
        if(!visit[v]) {
            parent[v]=u;
            no_children++;
            st.push(u),ts.push(v);
            articulation_point(v);
            low[u]=min(low[u],low[v]);
            if(u==1&&no_children>1) {
                while(!st.empty()) {
                    u1=st.top(),v1=ts.top();
                    st.pop(),ts.pop();
                    cout<<u1<<" "<<v1<<endl;
                }
            } else if(dis[u]<=low[v]&&u!=1) {
                point[u]=true,art_point.push_back(u);
                while(1) {
                    u1=st.top(),v1=ts.top();
                    st.pop(),ts.pop();
                    if(u1==u&&v1==v) {
                        cout<<u1<<" "<<v1<<endl;
                        break;
                    }
                    cout<<u1<<" "<<v1<<" ";
                }
            }
        } else {
            if(low[u]>dis[v]) {
                low[u]=min(low[u],dis[v]);
                st.push(u),ts.push(v);
            }
        }
    }

}
int main() {
    int n,edge,u,v;
    scanf("%d %d",&n,&edge);
    for(int i=1; i<=edge; i++) {
        scanf("%d %d",&u,&v);
        vertex[u].push_back(v);
        //vertex[v].push_back(u);
    }
    for(int i=1; i<=n; i++) {
        if(!visit[i]) {
            articulation_point(i);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" "<<ts.top()<<" ";
        st.pop(),ts.pop();
    }
    /*if(art_point.size()!=0) {
        for(int i=0; i<art_point.size(); i++) {
            cout<<art_point[i];
            if(i<art_point.size()-1)
                printf(" ");
        }
    } else {
        printf("biconnected graph");
    }*/
    return 0;
}

