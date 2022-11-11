#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int phi[10000],lp[10000];
vector<int>prime;
/*
void sieve(int n) {
    int limit=sqrt(n*1.0)+2ll;

    for(int i=2; i<=limit; i++) {
        if(lp[i]==0) {
            lp[i]=i;
            prime.pb(i);
        }
        for(int j=0; j<(int)prime.size()&&prime[j]<=lp[i]&&i*prime[j]<=limit; j++) {

            lp[i*prime[j]]=prime[j];
        }
    }
}

int totient(int n) {
    //cout<<prime[0]<<" "<<prime[1]<<" "<<prime[2]<<endl;
    int ans=n;
    int n1=sqrt(n);
    for(int i=0; i<prime.size()&&prime[i]<=n1; i++) {
        if(n%prime[i]==0) {
            while(n%prime[i]==0) {
                n/=prime[i];
            }
            n1=sqrt(n);
            ans-=(ans/prime[i]);

        }

    }
    if(n>1) {
        ans-=(ans/n);

    }
    return ans;
}

int main(){
    int n;
    scanf("%d",&n);
    cout<<totient(n);
    return 0;
}*/
///very efficient sieve(find prime) and pre-calculate totient///
void precalculate_totient() {
    phi[1]=1;
    for (int i=2; i<=10; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            phi[i]=i-1;
            prime.push_back (i);
        } else {
            //cout<<i<<" "<<lp[i]<<endl;
            if (lp[i] == lp[i / lp[i]])
                phi[i] = phi[i / lp[i]] * lp[i];
            else
                phi[i] = phi[i / lp[i]] * (lp[i] - 1);
        }
        int len=prime.size();
        for (int j=0; j<len && prime[j]<=lp[i] && i*prime[j]<=10; ++j)
            lp[i * prime[j]] = prime[j];
    }
    for(int i=1; i<=10; i++) {
        phi[i]=phi[i]+phi[i-1];
    }
}


int main() {
    precalculate_totient();
    int test,n;
    //for(int i=1; i<=100; i++)cout<<phi[i]<<endl;
    /*scanf("%d",&test);
    for(int k=1; k<=test; k++) {
        scanf("%d",&n);
        printf("%d\n",phi[n]);
    }*/
    return 0;
}



///range totient
/*#include<bits/stdc++.h>
using namespace std;

///Author:Refat(BSMRSTU)///

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define pil pair<int,ll>
const ll N = 1e7 + 10;
const ll M = 1e5 + 10;
int Set(int N,int pos) {
    return N=N | (1<<pos);
}
int reset(int N,int pos) {
    return N= N & ~(1<<pos);
}
bool check(int N,int pos) {
    return (bool)(N & (1<<pos));
}
ll lp[N];
ll phi[M],value,r[M];
vector<ll>prime;
void sieve(ll m,ll n) {
    ll limit=sqrt(n*1.0)+2ll;

    for(ll i=2; i<=limit; i++) {
        if(lp[i]==0) {
            lp[i]=i;
            prime.pb(i);
        }
        for(ll j=0; j<(ll)prime.size()&&prime[j]<=lp[i]&&i*prime[j]<=limit; j++) {

            lp[i*prime[j]]=prime[j];
        }
    }
}
void precalculate_totient(ll m,ll n) {
    //cout<<prime[0]<<" "<<prime[1]<<" "<<prime[2]<<endl;
    for(ll i=0; i<prime.size(); i++) {
        value=(m/prime[i])*prime[i];
        for(ll j=value; j<=n; j+=prime[i]) {
            if(j<m)continue;
            ll in=j-m;
            phi[in]-=(phi[in]/prime[i]);
            if(r[in]%prime[i]==0) {
                while(r[in]%prime[i]==0) {
                    r[in]/=prime[i];
                }
            }
        }
    }
}
int main() {
    /// freopen("input.txt","r",stdin);
    /// freopen("output.txt","w",stdout);
    ll n,m;
    scanf("%lld %lld",&m,&n);

    for(ll i=m; i<=n; i++) {
        //cout<<i-m<<" ";
        ll in=i-m;
        phi[in]=i;
        r[in]=i;
    }
    sieve(m,n);
    precalculate_totient(m,n);
    for(int i=0; i<=n-m; i++) {

        if(r[i]>1ll) {
            phi[i]-=(phi[i]/r[i]);
        }
        printf("%lld\n",phi[i]);

    }
    return 0;
}*/



