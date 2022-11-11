/**
    CRT
x=a[i]mod m[i];
x=a[i+1]mod m[i+1];
--------------
--------------
x=a[n]mod m[n];

x=M[i]*a[i]*(M[i]mod m[i]+......
*/
/*
3
1031 1473
1141 1234
50 1827
*/

/// pairwise co-prime CRT  ***********

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll a[100],m[100],M[100],y[100],x1,y1;

///pairwise co-prime
/*ll modInverse(ll a,ll mod) {  /// sol:1
    a=a%mod;
    for(ll B=1; B<mod; B++)
        if(((a*B)%mod)==1ll)
            return B;
}*

/// condition gcd(a,mod)=1&& mod value is prime && pairwise co-prime
///bigmod version
ll modInverse(ll a,int md,int mod) {   /// sol:2
    if(md==0)return 1%mod;
    ll  x=modInverse(a,md/2,mod);
    x=(x*x)%mod;
    if(md%2==1)x=(x*a)%mod;
    return x;
}
/// no condition log10(a)+log10(b) && pairwise co-prime
///   START
ll ext_euclid_gcd(ll A,ll b,ll x,ll y) {   ///sol:3,4

    if(A==0) {
        x1=0;///global variable
        y1=1;///global variable
        return b;
    }
    ll d=ext_euclid_gcd(b%A,A,x,y);
    x=x1,y=y1;
    x1=y-((b/A)*x);
    y1=x;
    return y1;   ///sol:3
}
ll modInverse(ll a,ll mod) {   ///sol:3
    ll res=ext_euclid_gcd(mod,a,0,0);
    if(res<0)res+=mod;
    return res;
}
/// END

/// Another efficient solution for pairwise co-prime (use this solution)
int CRT(int len) {   ///sol:4
    int n=len,a2,m2;
    int a1=a[1];
    int m1=m[1];
    for(int i=2; i<=n; i++) {
        a2=a[i];
        m2=m[i];
        ll mod=m1*m2;
        ext_euclid_gcd(m1,m2,0,0);
        ll x=((a1*(m2%mod)*(y1%mod))+(a2*(m1%mod)*(x1%mod)))%mod;
        a1=x;
        m1=m1*m2;
    }
    if(a1<0)a1+=m1;
    return a1;
}

int main() {
    ll t,n,mul,result,Case=0;
    scanf("%lld",&t);
    while(t--) {
        scanf("%lld",&n);
        mul=1;
        result=0;
        for(int i=1; i<=n; i++) {   ///sol:3
            scanf("%lld %lld",&a[i],&m[i]);
            mul*=m[i];
        }
        ///
        ///  start  (use this solution)
        int res=CRT(n);   ///sol:4
        cout<<res<<endl;
        ///  end
        ///
        for(int i=1; i<=n; i++) {   ///sol:3
            M[i]=mul/m[i];//x1=0,y1=0;
            y[i]=modInverse(M[i],m[i]);
            //cout<<M[i]<<" "<<m[i]<<" "<<y[i]<<endl;
        }
        for(int i=1; i<=n; i++) {
            result+=(a[i]*M[i]*y[i]);
        }
        Case++;
        printf("Case %lld: %lld\n",Case,result%mul);
    }

    return 0;
}
*/

///************************************************************************************
///pairwise not co-prime || pairwise co-prime

ll ext_euclid_gcd(ll A,ll b,ll x,ll y) {

    if(A==0) {
        x1=0;///global variable
        y1=1;///global variable
        return b;
    }
    ll d=ext_euclid_gcd(b%A,A,x,y);
    x=x1,y=y1;
    x1=y-((b/A)*x);
    y1=x;
}

ll CRT(int len) {
    int n=len,a2,m2,mod;
    int a1=a[1];
    int m1=m[1];
    for(int i=2; i<=n; i++) {
        a2=a[i];
        m2=m[i];
        ll g=__gcd(m1,m2);
        if(a1%g!=a2%g)return -1;
        ext_euclid_gcd(m1/g,m2/g,0,0);
        mod=((m1/g)*m2);  ///LCM
        ll x=((a1*((m2/g)%mod)*(y1%mod))+(a2*((m1/g)%mod)*(x1%mod)))%mod;
        a1=x;
        if(a1<0)a1+=mod;
        m1=mod;
    }

    return a1;
}

int main() {
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        scanf("%d %d",&a[i],&m[i]);
    }
    ll ans=CRT(n);
    printf("%lld\n",ans);
    return 0;
}

/**     SAME CODE for all condition

vector<int>A,M;int p,q;

ll ext_euclid_gcd(ll A,ll b,ll x,ll y) {

    if(A==0) {
        p=0;///global variable
        q=1;///global variable
        return b;
    }
    ll d=ext_euclid_gcd(b%A,A,x,y);
    x=p,y=q;
    p=y-((b/A)*x);
    q=x;
}
pair<int, int> chinese_remainder_theorem( ) {
    if(A.size() != M.size()) return {-1,-1}; /// Invalid input

    int n = A.size();

    int a1 = A[0];
    int m1 = M[0];
    /// Initially x = a_0 (mod m_0)

    /// Merge the solution with remaining equations
    for ( int i = 1; i < n; i++ ) {
        int a2 = A[i];
        int m2 = M[i];

        ll g = __gcd(m1, m2);
        if ( a1 % g != a2 % g ) return {-1,-1}; /// No solution exists

        /// Merge the two equations

        ext_euclid_gcd(m1/g, m2/g, 0, 0);

        ll mod = ((m1/g) * m2); /// LCM of m1 and m2
           cout<<mod<<" ";
        /// We need to be careful about overflow, but I did not bother about overflow here to keep the code simple.
        ll x = (a1*((m2/g)%mod)*(q%mod) + a2*((m1/g)%mod)*(p%mod)) % mod;

        /// Merged equation
        a1 = x;
        if (a1 < 0) a1 += mod; /// Result is not suppose to be negative
        m1 = mod;
    }
    //return {a1, m1};
    cout<<a1;
}
int main(){
      int n,a,m;
      scanf("%d",&n);
      for(int i=1;i<=n;i++){
        scanf("%d %d",&a,&m);
        A.pb(a),M.pb(m);
      }
      pair<int,int>ans[100];
      chinese_remainder_theorem( );
      //cout<<ans[0].first;
}
*/

