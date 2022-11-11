#include<bits/stdc++.h>
using namespace std;
int N = 100;

int dp[N];
stack<int> par;
vector< pair<int, int > > edge;

int solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
       int t;
       scanf("%d", &t);
       dp[t] = i;
    }
    for(int i = 1; i <= n; i++) {
       int t;
       scanf("%d", &t);
       dp[t] = i;
    }
    for(int i = 1; i <= n * 2; i++) {
        if(par.empty()) par.push(dp[i]);
        else if(dp[i] == par.top()) par.pop();
        else {
        	int u = par.top();
        	int v = dp[i];
        	edge.pb({u, v});
        	par.push(dp[i]);
        }
    }
    for(int i = 0; i < n - 1; i++) {
        printf("%d --- %d\n", edge[i].first, edge[i].second);
    }
    return 0;
}
int main(){
    solve();
    return 0;
}
