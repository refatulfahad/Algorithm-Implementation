#include<bits/stdc++.h>
using namespace std;

#define ll             long long
#define gcd(a,b)       __gcd(a,b)
#define lcm(a,b)       a*(b/gcd(a,b))
#define pii            pair<int, int>
#define pll            pair<ll, ll>
#define pil            pair<int, ll>
#define pli            pair<ll, int>
#define vi             vector<int>
#define vl             vector<ll>
#define vii            vector<pii>
#define vll            vector<pll>
#define vil            vector<pil>
#define vli            vector<pli>
#define mii            map<int, int>
#define mll            map<ll, ll>
#define pb             push_back
#define ppb            pop_back
#define mp             make_pair
#define mt             make_tuple
#define lb             lower_bound
#define ub             upper_bound
#define ff             first
#define ss             second
#define all(v)         v.begin(),v.end()
#define fill(a,b)      memset(a,b,sizeof a)
#define smax(a, b)     a=max(a, b)
#define smin(a, b)     a=min(a, b)
#define sqr(x)         x*x
#define cube(x)        x*x*x
#define asort(a, n)    sort(a+1, a+n+1)
#define FOR(i, l, r)   for(int i=l;i<=r;i++)
#define ROF(i, l, r)   for(int i=r;i>=l;i--)
#define endl           '\n'

int in() {
    int n;
    scanf("%d", &n);
    return n;
}

ll Lin() {
    ll n;
    scanf("%lld", &n);
    return n;
}

double Din() {
    double n;
    scanf("%lf", &n);
    return n;
}

const double gama = 0.57721566490;
const double eps = 0.00000001;
const ll inf = 1e17;
const ll mod = 1e9 + 9;
const int N = 1e3 + 5;

vector<pii>g[N];
ll dis[N];
int par[N];

bool bellman_ford(int n, int s) {
    for (int i = 1; i <= n; i++)
        dis[i] = inf;
    dis[s] = 0;
    for (int i = 1; i <= n; i++) {
        for (int u = 1; u <= n; u++) {
            for (auto x : g[u]) {
                int v = x.ss;
                ll w = (ll)x.ff;
                if (dis[u] == inf)continue;
                if (dis[v] > dis[u] + w) {
                    if (i == n) return false;
                    dis[v] = dis[u] + w;
                    par[v] = u;
                }
            }
        }
    }
    return true;
}

void path(int u, int v) {
    if (par[v]) path(u, par[v]);
    if (u == v) printf("%d", v);
    else printf(" %d", v);
}

int main() {
    int n = in(), m = in();
    for (int i = 0; i < m; i++) {
        int u = in(), v = in(), w = in();
        g[u].pb(mp(w, v));
    }
    int s = in(), q = in();
    if (bellman_ford(n, s)) {
        while (q--) {
            int d = in();
            if (dis[d] == inf)
                printf("Infinite\n");
            else {
                printf("%lld\n", dis[d]);
                path(s, d);
                printf("\n");
            }
        }
    } else
        printf("Negative Cycle Exists\n");
    return 0;
}




