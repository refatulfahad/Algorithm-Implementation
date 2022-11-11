
#include<bits/stdc++.h>
bool dfs(int node,vector<int>adj[],vector<bool>&start,vector<bool>&end){
	start[node]=true;
	bool ck=false;
	for(int x:adj[node]){
		if(!start[x]){
			ck|=dfs(x,adj,start,end);
		}
		else if(!end[x]){
			return true;
		}
	}
	end[node]=true;
	return ck;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
	vector<int>adj[n+1];
	vector<bool>start(n+1,false),end(n+1,false);
	int sz=(int)edges.size();
	for(auto x:edges){
		adj[x.first].push_back(x.second);
		//adj[x.second].push_back(x.first);
	}
	for(int i=1;i<=n;++i){
		if(!end[i]){
			if(dfs(i,adj,start,end)){
				return 1;
			}
		}
	}
	return 0;
}