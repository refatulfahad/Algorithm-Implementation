#include<bits/stdc++.h>
using namespace std;
int par[1000009], dis[1000009];
vector<pair<int, int>>v[1000009];
int bellman_ford(int s, int n) {
    for (int i = 1; i <= n; i++) {
        dis[i] = INT_MAX;
    }
    dis[s] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int i1 = 0; i1 < v[j].size(); i1++) {
                int ver = v[j][i1].second;
                int w = v[j][i1].first;
                if (dis[j] == INT_MAX)continue;
                if (dis[ver] > dis[j] + w) {
                    if (i == n)
                        return 0;
                    dis[ver] = dis[j] + w;
                    par[ver] = j;
                }
            }

        }
    }


    return 1;
}
void path(int u, int v) {
    if (par[v])
        path(u, par[v]);
    if (u == v) {
        printf("%d ", v);
    } else {
        printf("%d ", v);
    }
}
int main() {
    int n, m, x, y, w, s, num, d;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &x, &y, &w);
        v[x].push_back(make_pair(w, y));
    }
    scanf("%d %d", &s, &num);
    if (bellman_ford(s, n)) {
        while (num--) {
            scanf("%d", &d);
            {
                printf("%d\n", dis[d]);
            }
            path(s, d);
            printf("\n");
        }
    } else {
        printf("negative cycle exits\n");
    }
    return 0;
}
