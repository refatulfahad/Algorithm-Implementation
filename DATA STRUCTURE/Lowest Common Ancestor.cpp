#include<bits/stdc++.h>
using namespace std;
vector<int>ar[10000];
int visit[1000],p[1000],length[1000],parent[1000][20];
void dfs(int node){
     visit[node]=1;
     for(int i=0;i<ar[node].size();i++){
        int b=ar[node][i];
        if(!visit[b]){
            //cout<<n<<" "<<b<<endl;
            length[b]=length[node]+1;
            p[b]=node;
            dfs(b);
        }
     }
}
void sparse_table(int node){
      for(int i=1;i<=node;i++){
        parent[i][0]=p[i];
      }
      for(int j=1;(1<<j)<=node;j++){
        for(int i=1;i<=node;i++){
            if(parent[i][j-1]!=0){
                parent[i][j]=parent[parent[i][j-1]][j-1];
            }
        }
      }
}
int result_LCA(int node,int node1,int node2){
    int log=1,temp;
    if(length[node1]<length[node2]){
        temp=node1;
        node1=node2;
        node2=temp;
    }
    while(1){
        int next=log+1;
        if((1<<next)>length[node1])break;
        log++;
    }
    for(int i=log;i>=0;i--){
        if(length[node1]-(1<<i)>=length[node2]){
            node1=parent[node1][i];
        }
    }
    if(node1==node2)return node1;
    for(int i=log;i>=0;i--){
        if(parent[node1][i]!=0&&parent[node1][i]!=parent[node2][i]){
            node1=parent[node1][i];node2=parent[node2][i];
        }
    }
    return p[node1];///10 9 1 2 1 8 2 3 2 4 2 7 4 5 4 6 8 9 8 10

                    ///5 2
}
int main(){
     int node,edge,x,y;
     scanf("%d %d",&node,&edge);
     for(int i=1;i<=edge;i++){
        scanf("%d %d",&x,&y);
        ar[x].push_back(y);
        ///ar[y].push_back(x);
     }
     dfs(1);
     sparse_table(node);
     int node1,node2;
     scanf("%d %d",&node1,&node2);
     cout<<result_LCA(node,node1,node2);
     return 0;
}
