/*
                                                   INCLUSION-EXCLUSION


#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll M=1e9+7;

ll f[1005],dp[1005][1005];

ll ncr(int n,int r) {
    if(n==r)return 1ll;
    if(r==1)return n;
    if(dp[n][r]!=-1)return dp[n][r];
    return dp[n][r]=(ncr(n-1,r-1)%M+ncr(n-1,r)%M)%M;
}

int main() {
    memset(dp,-1,sizeof(dp));
    f[0]=1ll;
    for(ll i=1; i<=1000; i++) {
        f[i]=(f[i-1]*i)%M;
    }
    int test;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++) {
        ll n,m,k;
        scanf("%lld %lld %lld",&n,&m,&k);
        ll ans=f[n-k];
        for(int i=1; i<=m-k; i++) {
            if(i%2) {
                ans-=((ncr(m-k,i)%M)*(f[n-k-i]%M))%M;
            } else {
                ans+=((ncr(m-k,i)%M)*(f[n-k-i]%M))%M;
            }
            ans=(ans+M)%M;
        }
        ans=(ans*(ncr(m,k)%M))%M;
        printf("Case %d: %lld\n",cs,ans);
        //if(cs!=test)cout<<endl;
    }
    return 0;
}

*/

/*
                                       D-ARRANGEMENT


#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll dar[25],dp[25][25];

ll ncr(int n,int r) {
    if(n==r||r==0)return 1ll;
    if(r==1)return n;
    if(dp[n][r]!=-1)return dp[n][r];
    return dp[n][r]=ncr(n-1,r-1)+ncr(n-1,r);
}
int main() {
    ll n,m,ans;
    memset(dp,-1,sizeof(dp));
    dar[1]=0ll,dar[2]=1ll,dar[0]=1ll;
    for(int i=3; i<=20; i++) {
        dar[i]=(i-1)*(dar[i-1]+dar[i-2]);
    }
    while(scanf("%lld %lld",&n,&m)!=EOF) {
        ans=0ll;
        for(int i=0; i<=m; i++) {
            ans+=ncr(n,i)*dar[n-i];

        }
        printf("%lld\n",ans);
    }
    return 0;
}

*/
