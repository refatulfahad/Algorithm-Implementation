#include<bits/stdc++.h>
using namespace std;
vector<int>ar[10000];
int visit[1000], p[1000], length[1000], par[1000][1000];
void dfs(int node, int d = 0) {
    visit[node] = 1;
    length[node] = d;
    for (int i = 1; i <= 16; i++) {
        par[i][node] = par[i - 1][par[i - 1][node]];
    }
    for (int i = 0; i < ar[node].size(); i++) {
        int b = ar[node][i];
        if (!visit[b]) {
            par[0][b] = node;
            dfs(b, d + 1);
        }
    }
}

int result_LCA(int u, int v) {
    if (length[u] < length[v]) swap(u, v);
    for (int i = 16; i >= 0 && u != v; i--) {
        if (length[par[i][u]] >= length[v] && par[i][u] != 0) u = par[i][u];
    }
    if (u == v) return u;
    for (int i = 16; i >= 0 && u != v; i--) {
        if (par[i][u] != par[i][v]) u = par[i][u], v = par[i][v];
    }
    return par[0][u];
}

int main() {
    int node, edge, x, y;
    scanf("%d %d", &node, &edge);
    for (int i = 1; i <= edge; i++) {
        scanf("%d %d", &x, &y);
        ar[x].push_back(y);
        ///ar[y].push_back(x);
    }
    par[0][1] = 1;
    dfs(1);
    //sparse_table(node);
    int node1, node2;
    scanf("%d %d", &node1, &node2);
    cout << result_LCA(node1, node2);
    return 0;
}

