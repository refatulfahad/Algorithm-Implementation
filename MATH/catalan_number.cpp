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
const ll inf = (ll)1e18;
const double pi = 2 * acos(0.0);
const double eps = 1e-9;
int Set(int N, int pos) {
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

ll catalan[105], fact[20];
ll cata(ll n) {
	if (n == 0 || n == 1)return 1;
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		res += (cata(i) * cata(n - i - 1)) % M;
	}
	return res;
}

ll big_modInverse(ll a, ll md, ll mod) {
	if (md == 0)return 1 % mod;
	ll  x = big_modInverse(a, md / 2, mod);
	x = (x * x) % mod;
	if (md % 2 == 1)x = (x * (a % mod)) % mod;
	return x;
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

		//case:1 for loop
		// catalan[0] = 1, catalan[1] = 1;
		// for (int i = 2; i <= 20; ++i) {
		// 	ll res = 0;
		// 	for (int j = 0; j < i; ++j) {
		// 		res += (catalan[j] * catalan[i - j - 1])%M;
		// 	}
		// 	catalan[i] = res;
		// 	cout << res << el;
		// }

		/**********/

		// case 2: recursive function
		//cout << cata(5) << el;

		/**********/

		//case 3: analytical method
		//catalan[n]=(2n)!/(n!*(n+1)!)
		fact[0] = 1;
		for (ll i = 1; i <= 10; ++i) {
			fact[i] = fact[i - 1] * i;
		}
		int n = 4;
		ll ans = (fact[2 * n] * big_modInverse(fact[n] * fact[n + 1], M - 2, M)) % M;
		cout << ans << el;
	}
	return 0;
}

