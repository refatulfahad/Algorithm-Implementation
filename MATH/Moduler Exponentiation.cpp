#include<bits/stdc++.h>
using namespace std;
#define ll long long

///time complexity:log2(power)
ll bigmod(ll a,ll b,ll m) {
    if(b==0) {
        return 1ll%m;
    }
    ll x=bigmod(a,b>>1,m);
    x=(x*x)%m;
    if(b%2==1)x=(x*(a%M))%m;
    return x;
}

///faster alternate solution:repeated squaring method log2(power)

ll bigmod_rsm(ll a,ll p,ll m) {
    ll res=1%m,x=a%m;
    while(p) {
        if(p&1) {
            res=(res*x)%m;
        }
        x=(x*x)%m;
        p>>=1;
    }
    return res;
}
/****
   int Exponentiation(int a,int b,int m){
        if(b==0)
            return 1%m;
        else if(b%2==0){
            return a*Exponentiation(a*a%m,b/2,m);
        }
        else{
            return a*Exponentiation(a*a%m,(b-1)/2,m);
        }
   }


   ****/
int main() {
    long long int a,b,m;
    scanf("%lld %lld %lld",&a,&b,&m);
    printf("%lld^%lld mod %lld=%lld\n",a,b,m,bigmod(a,b,m));
    printf("%lld^%lld mod %lld=%lld",a,b,m,bigmod_rsm(a,b,m));
    return 0;
}

