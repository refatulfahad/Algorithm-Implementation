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

ll a[505][505];
void ini(int n) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j)continue;
			a[i][j] = inf;
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
	//IOS;
	/// freopen("input.txt","r",stdin);
	/// freopen("output.txt","w",stdout);

	int test = 1;
	//cin>>test;
	for (int cs = 1; cs <= test; ++cs) {
		int n, m, q;
		cin >> n >> m >> q;
		ini(n);
		for (int i = 1; i <= m; ++i) {
			int x, y, z;
			cin >> x >> y >> z;
			a[x][y] = z;
			a[y][x] = z;
		}
		for (int k = 1; k <= n; ++k) {
			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					if (a[i][j] > a[i][k] + a[k][j]) {
						a[i][j] = a[i][k] + a[k][j];
					}
				}
			}
		}
		while (q--) {
			int x, y;
			cin >> x >> y;
			if (a[x][y] == inf) {
				cout << -1 << el;
			}
			else {
				cout << a[x][y] << el;
			}
		}
	}
	return 0;
}

