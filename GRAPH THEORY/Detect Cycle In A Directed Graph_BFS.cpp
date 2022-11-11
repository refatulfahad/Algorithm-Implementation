
#include<bits/stdc++.h>
bool bfs(int n,vector<int>adj[],vector<int>&indegree){
	queue<int>q;
	for(int i=1;i<=n;++i){
		if(!indegree[i]){
			q.push(i);
		}
	}
	int cnt=0;
	while(!q.empty()){
		int node=q.front();
		q.pop();
		++cnt;
		for(int x:adj[node]){
			--indegree[x];
			if(!indegree[x]){
				q.push(x);
			}
		}
	}
	if(cnt==n)return false;
	return true;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
	vector<int>adj[n+1];
	vector<int>indegree(n+1,0);
	int sz=(int)edges.size();
	for(auto x:edges){
		adj[x.first].push_back(x.second);
		++indegree[x.second];
		//adj[x.second].push_back(x.first);
	}
	if(bfs(n,adj,indegree)){
		return 1;
	}
	return 0;
}