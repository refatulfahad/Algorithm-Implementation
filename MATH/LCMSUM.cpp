#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+5;
vector<ll>prime;
ll gd[N],lp[N],phi[N];
void precalculate_totient() {

    for(int i=2; i<=N-3; i++) {
        if(lp[i]==0) {
            lp[i]=i;
            phi[i]=i-1;
            prime.push_back(i);

        } else {
            if(lp[i]==lp[i/lp[i]]) {
                phi[i]=phi[i/lp[i]]*lp[i];
            } else {
                phi[i]=phi[i/lp[i]]*(lp[i]-1);
            }
        }
        for(int j=0; j<prime.size()&&prime[j]<=lp[i]&&i*prime[j]<=N; j++) {
            lp[i*prime[j]]=prime[j];
        }
    }
}

void precalculate_gcd() {
    for(ll i=2; i<=N-5; i++) {
        for(int j=i; j<=N-5; j+=i) {
            gd[j]+=(phi[i]*i);///(1,n),(2,n),(3,n).....(n,n)
        }
    }
}
int main() {

    precalculate_totient();
    precalculate_gcd();
    //cout<<gd[6];
    //for(int i=1;i<=10;i++)cout<<gd[i]<<endl;
    ll test,n,ans;
    //cout<<gd[2];
    scanf("%lld",&test);
    for(int p=1; p<=test; p++) {
        scanf("%lld",&n);
        if(n==1)cout<<1<<endl;
        else {
            //cout<<gd[n]<<endl;
            ans=gd[n]/2ll;
            ans=ans*n;
            printf("%lld\n",ans+n);
        }
    }
    return 0;
}
