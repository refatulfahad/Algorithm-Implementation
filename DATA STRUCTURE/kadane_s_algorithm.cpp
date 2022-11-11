/**Bismillahir Rahmanir Raheem
    Author:Refatul Fahad
    Gmail: refatm452@gmail.com
**/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define pli pair<ll,int>
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
const ll inf=(ll)1e18;
const double pi=2*acos(0.0);
const double eps=1e-9;


int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};


int main() {

    //IOS;
    /// freopen("input.txt","r",stdin);
    /// freopen("output.txt","w",stdout);

    int test=1;
    //cin>>test;
    for(int cs=1; cs<=test; ++cs) {
        int nums[1005],n;
        cin>>n;
        for(int i=0;i<n;++i){
            cin>>nums[i];
        }
        int mx=nums[0],sum=0;
        for(int i=0;i<sz(nums);++i){
            sum=max(sum+nums[i],nums[i]);
            mx=max(mx,sum);
        }
    }
    return 0;
}


