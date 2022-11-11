/**#include<bits/stdc++.h>
#define MAX 100000
using namespace std;
vector<pair<int,int> > *vertices;
bool check[100000]={true};
void make_vertex(int n)
{
    vertices = new vector<pair<int,int> >[n];
}

void edges(int a,int b,int w)
{

    vertices[a].push_back(make_pair(b,w));
    vertices[b].push_back(make_pair(a,w));
}
void Diaks(int src,int n)
{
    priority_queue< pair<int,int>,vector<pair<int,int> > ,greater< pair<int,int> > > pq;
    vector<int> dis(n,MAX);
    pq.push(make_pair(0,src));
    dis[src]=0;
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        vector< pair<int, int> >::iterator i;
        for(i=vertices[u].begin();i!=vertices[u].end();i++)
        {
            int v = (*i).first;
            int w = (*i).second;
            if(dis[v]>dis[u]+w)
            {
                dis[v] = dis[u]+w;
                pq.push(make_pair(dis[v], v));
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        if(dis[i]==MAX)
        {
            cout<<"Impossible"<<endl;
        }
        else
        {
            cout<<dis[i]<<endl;
        }
    }
}

int main()
{
    int t,n,m,a,b,w,src;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
    cin>>n>>m;
    make_vertex(n);
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>w;
        edges(a,b,w);
    }
    cin>>src;

    cout<<"Case "<<i<<" :"<<endl;
    Diaks(src,n);

    }

    return 0;
}
*/
///optimal
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
#define ROF(i, a, b)   for(int i=r;i>=l;i--)
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
const ll mod = 1e9 + 7;
const int N = 2e5 + 5;

vii g[N];
bool vis[N];
ll dis[N];
int par[N];

void dijkstra(int u, int n) {
    for (int i = 1; i <= n; i++)
        dis[i] = inf;
    priority_queue<pli, vli, greater<pli> >pq;
    pq.push(mp(0LL, u));
    dis[u] = 0LL;
    while (!pq.empty()) {
        u = pq.top().ss;
        pq.pop();
        if (vis[u])continue;
        vis[u] = true;
        for (auto x : g[u]) {
            int v = x.ss;
            ll w = (ll)x.ff;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                par[v] = u;
                if (!vis[v])
                    pq.push(mp(dis[v], v));
            }
        }
    }
}

void path(int u, int v) {
    if (par[v])
        path(u, par[v]);
    u != v ? printf(" %d", v) : printf("%d", v);
}

int main() {
    int n = in(), m = in();
    for (int i = 1; i <= m; i++) {
        int u = in(), v = in(), w = in();
        g[u].pb(mp(w, v));
        g[v].pb(mp(w, u));
    }
    dijkstra(1, n);
    int q = in();
    while (q--) {
        int v = in();
        if (vis[v]) {
            printf("%d\n", dis[v]);
            path(1, v);
            printf("\n");
        } else
            printf("Infinity\n");
    }
    return 0;
}
///************************************************************/
//#include<bits/stdc++.h>
//using namespace std;
//vector<pair<int, int> >g[100000];
//int par[100000], dis[100000], vis[100000];
//dijkstra(int u, int n) {
//    priority_queue< pair<int, int>, vector<pair<int, int> >, greater< pair<int, int> > > pq;
//    dis[u] = 0;
//    pq.push(make_pair(0, u));
//    while (!pq.empty()) {
//        u = pq.top().second;
//        //if (vis[u])continue;
//        if(dis[u]<pq.top().first)continue;
//        pq.pop();
//        vis[u] = 1;
//        for (int i = 0; i < g[u].size(); i++) {
//            int w = g[u][i].first;
//            int v = g[u][i].second;
//            if(vis[v])continue;
//            if (dis[v] > dis[u] + w) {
//                dis[v] = dis[u] + w;
//                par[v] = u;
//                //if (!vis[v]) {
//                    pq.push(make_pair(dis[v], v));
//                //}
//            }
//        }
//    }
//}
//int main() {
//    int n, m, x, y, w;
//    cin >> n >> m;
//    for (int i = 0; i < m; i++) {
//        cin >> x >> y >> w;
//        g[x].push_back(make_pair(w, y));
//    }
//    for (int i = 1; i <= n; i++) {
//        dis[i] = 10000000;
//    }
//    dijkstra(1, n);
//    if (dis[n] == 10000000) {
//        cout << "Impossible" << endl;
//    } else {
//        cout << dis[n] << endl;
//    }
//    return 0;
//}

