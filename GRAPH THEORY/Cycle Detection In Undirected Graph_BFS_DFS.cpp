

#include<bits/stdc++.h>
bool bfs(int node,vector<int> adj[],vector<bool>&vis){
	queue<pair<int,int> >q;
	q.push({node,node});
	vis[node]=true;
	while(!q.empty()){
		int x=q.front().first;
		int parent=q.front().second;
		q.pop();
		for(int y:adj[x]){
			if(!vis[y]){
				q.push({y,x});
				vis[y]=true;
			}
			else if(y!=parent){
				return true;
			}
		}
	}
	return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
	vector<bool>vis(n+2,false);
	vector<int> adj[n+1];
    for(auto it:edges){
		int u=it[0];
		int v=it[1];
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			if(bfs(i,adj,vis)){
				return "Yes";
			}		
		}
	}
	return "No";
}

-----------------------------------------------------------------



bool dfs(int node,vector<int> adj[],vector<bool>&vis,vector<int>&parent){
	vis[node]=true;
	bool ck=false;
	for(int x:adj[node]){
		if(!vis[x]){
			parent[x]=node;
			ck|=dfs(x,adj,vis,parent);
		}
		else if(parent[node]!=x){
			return true;
		}
	}
	return ck;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.

	vector<bool>vis(n+2,false);
	vector<int>parent(n+2,0);
	vector<int> adj[n+1];
    for(auto it:edges){
		int u=it[0];
		int v=it[1];
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			parent[i]=i;
			if(dfs(i,adj,vis,parent)){
				return "Yes";
			}
			
		}
	}
	return "No";
	
}
