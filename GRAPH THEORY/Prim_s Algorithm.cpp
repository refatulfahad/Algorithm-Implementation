#include<bits/stdc++.h>
using namespace std;
vector< pair < int,int > > v[1000];
struct node {
    int cost,u;
};
bool operator<(node a,node b) {
    return a.cost>b.cost;
}
priority_queue<node>pq;
int cost[1000];
bool taken[1000];
int vertex,edge;
int prim(int source) {
    for(int i=0; i<vertex; i++) {
        cost[i]=INT_MAX;
        taken[i]=false;
    }
    cost[source]=0;
    node temp;
    temp.u=source;
    temp.cost=0;
    pq.push(temp);
    int ans=0;
    while(!pq.empty()) {
        node current=pq.top();
        pq.pop();
        if(taken[current.u]) {
            continue;
        }
        taken[current.u]=true;
        ans+=current.cost;


        for(int i=0; i<v[current.u].size(); i++) {
            if(taken[v[current.u][i].first]) {
                continue;
            }
            if(v[current.u][i].second<cost[v[current.u][i].first]) {
                node temp2;
                temp2.u=v[current.u][i].first;
                temp2.cost=v[current.u][i].second;
                pq.push(temp2);
                cost[v[current.u][i].first]=v[current.u][i].second;
            }
        }

    }
    return ans;
}
int main() {

    scanf("%d %d",&vertex,&edge);
    pair<int,int>p;
    int source;
    for(int i=0; i<edge; i++) {
        cin>>source>>p.first>>p.second;
        v[source].push_back(p);
        int source1=p.first;
        p.first=source;
        v[source1].push_back(p);
    }
    cout<<"cost  "<<prim(0);
    return 0;
}
