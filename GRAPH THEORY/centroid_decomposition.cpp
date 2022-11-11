#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e4 + 5;
int nd, sz[N], ans = 0, dis[N], k;
vector<int>vertex[N];
bool visit[N];

void getsz(int node, int p = -1) {
    nd++;
    sz[node] = 1;
    for (int v : vertex[node]) {
        if (!visit[v] && p != v) {
            getsz(v, node);
            sz[node] += sz[v];
        }
    }
    //return nd;
}

int centroid(int node, int p = -1) {
    for (int v : vertex[node]) {
        if (!visit[v] && p != v && sz[v] > nd / 2)return centroid(v, node);
    }
    return node;
}

void update_res(int node, int p, int d) {
    if (d > k)return;
    ans += dis[k - d];
    for (int v : vertex[node]) {
        if (!visit[v] && p != v)update_res(v, node, d + 1);
    }
}

void update_dis(int node, int p, int d) {
    if (d > k)return;
    dis[d]++;
    for (int v : vertex[node]) {
        if (!visit[v] && p != v)update_dis(v, node, d + 1);
    }
}
void decompose(int u) {
    nd = 0;
    memset(dis, 0, sizeof(dis));
    dis[0]++;
    getsz(u);
    int center = centroid(u);
    visit[center] = true;
    for (int v : vertex[center]) {
        if (!visit[v]) {
            update_res(v, center, 1);
            update_dis(v, center, 1);
        }
    }
    for (int v : vertex[center]) {
        if (!visit[v]) {
            decompose(v);
        }
    }
}


int main() {
    int n,x,y;
    scanf("%d %d", &n, &k);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &x, &y);
        vertex[x].push_back(y);
        vertex[y].push_back(x);
    }
    decompose(1);
    printf("%d\n", ans);
    return 0;
}
