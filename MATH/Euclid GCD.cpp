#include<bits/stdc++.h>
using namespace std;
#define ll long long
/*ll gcd(ll a,ll b){
     if(b==0){
        return a;
     }
     else{
        return gcd(b,a%b);
     }
}*
/// more faster than recursion
ll gcd(ll a,ll b){
     while(b){
        a=a%b;
        swap(a,b);
     }
     return a;
}
int main(){
   cout<<gcd(12,4);
   return 0;
}*/


///gcd calculate 1 to n  *************

#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6;
ll gd[N+5],phi[N+5];
void precalculate_totient() {
    for(int i=2; i<=N; i++) {
        phi[i]=i;
    }
    for(int i=2; i<=N; i++) {
        if(phi[i]==i) {
            for(int j=i; j<=N; j+=i) {
                if(j%i==0) {
                    phi[j]-=(phi[j]/i);
                }
            }
        }
    }

}
void precalculate_gcd() {
    for(ll i=1; i<N; i++) {
        for(ll j=i; j<=N; j+=i) {
            gd[j]+=(i*phi[j/i]);///(1,n),(2,n),(3,n)....(n-1,n)
                                ///if you can calculate (n,n),just change phi[1]=1;
        }
    }

    for(int i=2; i<=6; i++) {
        gd[i]=(gd[i]+gd[i-1]);///(1,2),(1,3),(1,4)
                              ///(2,3),(2,4),(3,4)(all pair gcd)
        //cout<<gd[i]<<endl;
    }
}
int main() {
    precalculate_totient();
    precalculate_gcd();
    ll n;
    while(1) {
        scanf("%lld",&n);
        if(n==0)break;
        printf("%lld\n",gd[n]);
    }
    return 0;
}


