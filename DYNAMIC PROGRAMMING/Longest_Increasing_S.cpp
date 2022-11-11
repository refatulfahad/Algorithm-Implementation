/** LIS O(n^2) Dynamic programming solution
7
5 0 9 2 7 3 4
**/

/*#include<bits/stdc++.h>
using namespace std;

///Author:Refat(BSMRSTU)///

#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define pil pair<int,ll>
const int N = 1e5 + 5;
int ar[10000], n, dp[10000], path[10000];
int LIS(int u) {
	if (dp[u] != -1) {
		//cout<<1;
		return dp[u];
	}
	int mx = 0;
	for (int v = u + 1; v <= n; v++) {
		if (ar[u] < ar[v]) {
			int val = LIS(v);
			if (mx < val) {
				mx = val;
				path[u] = v;
			}
		}
	}
	return dp[u] = 1 + mx;
}
int main() {
	int  mx = INT_MIN, start, index;
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &ar[i]);
	}
	for (int i = 1; i <= n; i++) {
		int val = LIS(i);
		if (mx < val) {
			start = i;
			mx = val;
		}
	}
	printf("%d\nindex: %d ", mx, start);
	while (path[start] != 0) {
		index = path[start];
		printf("%d ", index);
		start = index;
	}
	cout<<"\n";
	return 0;
}*/
/*****LIS O(nlogk) Binary search solution*******/
#include<bits/stdc++.h>
using namespace std;

///Author:Refat(BSMRSTU)///

#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define pil pair<int,ll>
const int N = 1e5 + 5;
int ar[10000], I[10000], br[10000], sequence[10000], index[10000];
int main() {
	int n, low, high, length;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &ar[i]);
	}
	I[0] =0;
	for (int i = 1; i <= n; i++) {
		I[i] = INT_MAX;
	}
	length = 0;
	for (int i = 1; i <= n; i++) {
		low = 0, high = length;
		while (low <= high) {
			int mid = (low + high) >> 1;
			if (I[mid] < ar[i]) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		I[low] = ar[i];
		br[i] = low;
		if (length < low) {
			length = low;
		}
	}
	printf("%d\n", length);
	int ii = 1;
	for (int j = 1; j <= n; j++) {
		if (br[ii] < br[j]) {
			ii = j;
		}
		//cout<<br[j]<<" ";
	}
	//cout<<ii<<endl;
	int l = length;
	sequence[l] = ar[ii];
	index[l] = ii;
	for (int i = ii - 1; i >= 1; i--) {
		if (ar[i] < ar[ii] && br[i] < br[ii]) {
			l--;
			sequence[l] = ar[i];
			ii = i;
			index[l] = i;
		}
	}
	/***Value**/
	for (int i = 1; i <= length; i++) {
		printf("%d ", sequence[i]);
	}
	cout << endl;
	/**Index**/
	for (int i = 1; i <= length; i++) {
		printf("%d ", index[i]);
	}
	cout << endl;
	return 0;
}
/***another dp solution**/
/*
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int ar[100],n,dp[100][100];

int lis(int i,int j) {
    if(j>n) {
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int ans1=-1,ans2=-1;
    if(ar[i]<ar[j]) {
        ans1=1+lis(j,j+1);
    }
    ans2=lis(i,j+1);
    return dp[i][j]=max(ans1,ans2);
}
int main() {
    int mx=-1;
    scanf("%d",&n);
    memset(dp,-1,sizeof(dp));
    for(int i=1; i<=n; i++) {
        scanf("%d",&ar[i]);
    }
    for(int i=1; i<=n; i++) {
        int res=lis(i,i+1);
        if(mx<res) {
            mx=res;
        }
    }
    printf("%d\n",mx+1);
    return 0;
}
*/

/**********LIS length print(nlogn)*****/


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
#define pr(x) cerr << #x << " ** " << x << endl;

const int N = 1e5 + 5;
const ll M = (ll)1e9 + 7;
const ll inf=(ll)1e18;
const double pi=2*acos(0.0);
const double esp=1e-9;

int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};

int a[N];
vi v;
int main() {

    //IOS;
    /// freopen("input.txt","r",stdin);
    /// freopen("output.txt","w",stdout);

    int test=1;
    //cin>>test;
    for(int cs=1; cs<=test; ++cs) {
        int n,mx=-1;
        cin>>n;
        for(int i=1; i<=n; ++i) {
            cin>>a[i];
            v.pb(INT_MAX);
        }
        for(int i=1; i<=n; ++i) {
            ///If question says "strictly increasing" then you have to use lower_bound.
            int in=upper_bound(all(v),a[i])-v.begin();
            v[in]=a[i];
        }//cout<<v[0]<<" "<<v[1]<<el;
        int in=upper_bound(all(v),INT_MAX-1)-v.begin();
        cout<<in<<el;
    }
    return 0;
}

///iterative dp solution
int lengthOfLIS(vector<int>& nums) {
        for(int i=0;i<(int)nums.size();++i){
            dp[i]=1;
        }
        int mx=1;
        for(int i=0;i<(int)nums.size();++i){
            for(int j=0;j<i;++j){
                if(nums[j]<nums[i]&&dp[i]<dp[j]+1){
                    dp[i]=1+dp[j];
                    mx=max(mx,dp[i]);
                }
            }
        }
        return mx;
    }

