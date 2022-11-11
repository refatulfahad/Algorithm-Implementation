#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
vector<int>vertex[N];
stack<int>st;
void dfs(int node) {

    for(int i=0; i<(int)vertex[node].size(); i++) {
        if(vertex[node][i]!=-1) {
            int v=vertex[node][i];
            vertex[node][i]=-1;
            dfs(v);
        }
    }
    st.push(node);
}
int main() {
    int n,ed,x,y;
    scanf("%d %d",&n,&ed);
    for(int i=1; i<=ed; i++) {
        scanf("%d %d",&x,&y);
        vertex[x].push_back(y);
        //vertex[y].push_back(x);
    }

    dfs(1);
    ///Euler Circuit
    while(!st.empty()) {
        cout<<st.top();
        st.pop();
        if(st.empty())continue;
        cout<<" ";
    }

    /*
      when we will calculate euler path ,then run a dfs and
      find last node and connect extra edge between fast node and last node.
    */
    return 0;
}
