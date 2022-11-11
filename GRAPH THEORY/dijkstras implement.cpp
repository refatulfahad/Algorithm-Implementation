#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int> >g[100000];
int par[100000], dis[100000], vis[100000];
void initial(int n)
{
    for (int i = 0; i <= n; i++)
    {
        dis[i] = 0;
        vis[i] = 0;
        par[i] = 0;
    }
}
dijkstra(int u, int n)
{
    priority_queue< pair<int, int>, vector<pair<int, int> >, greater< pair<int, int> > > pq;
    dis[u] = 0;
    pq.push(make_pair(0, u));
    while (!pq.empty())
    {
        u = pq.top().second;
        pq.pop();
        vis[u] = 1;
        for (int i = 0; i < g[u].size(); i++)
        {
            int w = g[u][i].first;
            int v = g[u][i].second;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                par[v] = u;
                if (!vis[v])
                {
                    pq.push(make_pair(dis[v], v));
                }
            }
        }
    }
}
int main()
{
    int n, m, x, y, w, t, l = 0;
    //cin>>t;
    //while(t--)
    //{
    cin >> n >> m;
    initial(n);
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> w;
        g[x].push_back(make_pair(w, y));
        g[y].push_back(make_pair(w, x));
    }
    for (int i = 0; i <= n; i++)
    {
        dis[i] = 100000000;
    }
    dijkstra(0, 2);
    l++;
    if (dis[2] == 100000000)
    {
        cout << "Case " << l << ": " << "Impossible" << endl;
        //cout<<dis[1]<<dis[3]<<dis[5]<<dis[6];
    }
    else
    {
        cout << "Case " << l << ": " << dis[2] << endl;
    }
    for (int i = 0; i <= n; i++)
    {
        g[i].clear();
    }
    // }
    return 0;
}

/*********modified_dijkstra**********/


#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define grv(v) sort(v.begin(),v.end(),greater<int>())
#define sz(s)  (int)s.size()
#define all(s)  s.begin(),s.end()
#define fill(a,b) memset(a,b,sizeof(a))
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define countv(v,a) count(v.begin(),v.end(),a)
#define el "\n"
#define IOS  ios_base::sync_with_stdio(false),cin.tie(NULL)

const int N = 1e5 + 5;
const ll M = (ll)1e9 + 7;
const ll inf = (ll)1e16;
const double pi = 2 * acos(0.0);
const double eps = 1e-9;
int set(int N, int pos) {
    return N = N | (1 << pos);
}
int reset(int N, int pos) {
    return N = N & ~(1 << pos);
}
bool check(int N, int pos) {
    return (bool)(N & (1 << pos));
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

std::vector<pii> adj[N];
bool vis[N]; int par[N];
ll dis[N], full[N];
void dijks(int node) {
    priority_queue<pair<ll, int> >pq;
    pq.push({ -0, 1});
    while (!pq.empty()) {
        node = pq.top().ss;
        pq.pop();
        if (vis[node])continue;
        vis[node] = true;
        for (pair<ll, int>x : adj[node]) {
            if (dis[x.ss] > dis[node] + x.ff) {
                dis[x.ss] = dis[node] + x.ff;
            }
            if (dis[x.ss] > full[node] + (x.ff / 2ll)) {
                //par[x.ss] = node;
                dis[x.ss] = full[node] + (x.ff / 2ll);

            }
            if (full[x.ss] > full[node] + x.ff) {
                //par[x.ss] = node;
                full[x.ss] = full[node] + x.ff;
            }

            if (!vis[x.ss]) {
                pq.push({ -dis[x.ss], x.ss});
            }
        }
    }
}
int main() {
#ifndef ONLINE_JUDGE
    //read input from input.txt
    freopen("input.txt", "r", stdin);
    //write output from output.txt
    freopen("output.txt", "w", stdout);
#endif
    IOS;
    /// freopen("input.txt","r",stdin);
    /// freopen("output.txt","w",stdout);

    int test = 1;
    //cin>>test;
    for (int cs = 1; cs <= test; ++cs) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= m; ++i) {
            int x, y; ll z;
            cin >> x >> y >> z;
            adj[x].pb({z, y});
        }

        for (int i = 2; i <= n; ++i) {
            dis[i] = inf, full[i] = inf;
        }
        dijks(1);
        cout << min(dis[n], full[n]) << el;
    }
    return 0;
}

/*********************************************************************************/
/**Bismillahir Rahmanir Raheem
    Author:Refatul Fahad**/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define grv(v) sort(v.begin(),v.end(),greater<int>())
#define sz(s)  (int)s.size()
#define all(s)  s.begin(),s.end()
#define fill(a,b) memset(a,b,sizeof(a))
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define countv(v,a) count(v.begin(),v.end(),a)
#define el "\n"
#define IOS  ios_base::sync_with_stdio(false),cin.tie(NULL)

const int N = 1e5 + 5;
const ll M = (ll)1e9 + 7;
const ll inf = (ll)1e16;
const double pi = 2 * acos(0.0);
const double eps = 1e-9;
int set(int N, int pos) {
    return N = N | (1 << pos);
}
int reset(int N, int pos) {
    return N = N & ~(1 << pos);
}
bool check(int N, int pos) {
    return (bool)(N & (1 << pos));
}

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

std::vector<pair<ll, int> > adj[N];
int n, k;

void dijks(int start) {
    priority_queue<pair<ll, int> > pq;
    ll len[n + 5][k + 5];
    //cout << 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < k; ++j) {
            len[i][j] = inf;
        }
    }
    len[1][0] = 0;
    for (int i = 1; i < k; ++i)len[start][i] = inf;
    pq.push({ -0, start});
    while (!pq.empty()) {
        start = pq.top().ss;
        ll val = pq.top().ff * -1ll;
        pq.pop();
        if (len[start][k - 1] < val)continue;
        for (pair<ll, int>p : adj[start]) {
            if (len[p.ss][k - 1] > val + p.ff) {
                len[p.ss][k - 1] = val + p.ff;
                pq.push({ -len[p.ss][k - 1], p.ss});
                sort(len[p.ss], len[p.ss] + k);
                //cout << len[p.ss][0] << " " << len[p.ss][1] << " " << len[p.ss][2] << el;
            }

        }
    }
    for (int i = 0; i < k; ++i) {
        cout << len[n][i] << " ";
    }
}
int main() {
#ifndef ONLINE_JUDGE
    //read input from input.txt
    freopen("input.txt", "r", stdin);
    //write output from output.txt
    freopen("output.txt", "w", stdout);
#endif
    IOS;
    /// freopen("input.txt","r",stdin);
    /// freopen("output.txt","w",stdout);

    int test = 1;
    //cin>>test;
    for (int cs = 1; cs <= test; ++cs) {
        int m;
        cin >> n >> m >> k;
        for (int i = 1; i <= m; ++i) {
            int x, y, z;
            cin >> x >> y >> z;
            adj[x].pb({z, y});
        }
        //cout << 1;
        dijks(1);

    }
    return 0;
}


