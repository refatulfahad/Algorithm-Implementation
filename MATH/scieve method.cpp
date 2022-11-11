#include<bits/stdc++.h>
using namespace std;

///Prime factorize
/*
vector <int> factors;
void factorize( int n ) {
    int sqrtn = sqrt ( n );
    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {
        if ( n % prime[i] == 0 ) {
            while ( n % prime[i] == 0 ) {
                n /= prime[i];
                factors.push_back(prime[i]);
            }
            sqrtn = sqrt ( n );
        }
    }
    if ( n != 1 ) {
        factors.push_back(n);
    }
}*/

/**
bitwise sieve

bool check(int num,int index) {
    return (bool)(num & (1<<index));
}
int Set(int num,int index) {
    return num | (1<<index);
}
const int N=1e3;
int ar[(N+5)/32],prime[N+5],in=1;




void sieve() {
    int limit=sqrt(N*1.0)+2;
    prime[1]=2;

    for(int i=3; i<=limit; i+=2) {
        if(check(ar[i/32],i%32)==0) {
            cout<<i<<endl;
            for(int j=i*i; j<=N; j+=i*2) {
                ar[j/32]=Set(ar[j/32],j%32);
            }
        }
    }
    /// number of prime upto n

    for(int i=3; i<=N; i+=2) {
        if(check(ar[i/32],i%32)==0) {
            //cout<<i<<" ";
            in++;
            prime[in]=i;
        }
    }
}
**/
/*sieve
#include<bits/stdc++.h>
using namespace std;
const int N=1e7;
int cont[1000000],prime[10000005],len,phi[10000];
bool ar[N+5];
void fun(int n) {
    for(int i=2; i*i<=n; i++) {
        if(cont[i]==0) {
            for(int j=i*i; j<=n; j+=i) {
                cont[j]=1;
            }
        }
    }
}
///more efficient O(Nloglog(N))
void sieve(int n) {
    len=1;
    int limit=sqrt(n*1.0)+2;
    prime[1]=2;
    for(int i=3; i<=limit; i+=2) {
        if(ar[i]==false) {
            for(int j=i*i; j<=n; j+=i*2) {
                ar[j]=true;

                //if(j==10001)cout<<j<<" "<<i<<endl;
            }
        }
    }
    /// number of prime upto n
    for(int i=3; i<=n; i+=2) {
        if(ar[i]==false) {
            //cout<<i<<" ";
            len++;
            prime[len]=i;//cout<<i<<" ";
        }
    }
    cout<<len<<" ";
}*/
///more efficient O(n)
///https://codeforces.com/blog/entry/10119(explanation for phi function)
int phi[10000],lp[10000];
vector<int>prime;
void sieve_phi(int N) {
    phi[1]=1;
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            cout<<i<<" ";
            phi[i]=i-1;
            prime.push_back (i);
        } else {
            if (lp[i] == lp[i / lp[i]])
                phi[i] = phi[i / lp[i]] * lp[i];
            else
                phi[i] = phi[i / lp[i]] * (lp[i] - 1);
        }
        for (int j=0; j<(int)prime.size() && prime[j]<=lp[i] && i*prime[j]<=N; ++j) {
            lp[i * prime[j]] = prime[j];
            ///cout<<i<<" "<<prime[j]<<endl;
        }
    }
}

///
int main() {
    sieve_phi(1000);
}
///segmented sieve
/*
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=1e5+10;
const int M=1e6+10;
vector<int>prime;
int ar[N],ck[N];
bool st[M];
void segmented_sieve(int n) {
    for(int i=2; i<=n; ++i) {
        if(ar[i]==0) {
            ar[i]=i;
            prime.push_back(i);
        }
        for(int j=0; j<(int)prime.size()&&prime[j]<=ar[i]&&i*prime[j]<=n; ++j) {
            ar[i*prime[j]]=prime[j];
        }
    }
}
int main() {
    segmented_sieve(50000);
    //cout<<prime.size();
    int n,m,test,cnt;
    scanf("%d",&test);
    for(int k=1; k<=test; ++k) {
        scanf("%d %d",&n,&m);
        if(m<=50000) {
            for(int i=0; i<prime.size()&&prime[i]<=m; i++) {
                if(prime[i]>=n)printf("%d\n",prime[i]);
            }
            continue;
        }
        int val=ceil((float)sqrt(m));
        cnt=0;
        for(int i=0; i<(int)prime.size()&&prime[i]<=val; ++i) {
            int r=prime[i];
            int in=prime[i]*prime[i];
            if(in<n)
                in=((n+prime[i]-1)/prime[i])*prime[i];
            //if(prime[i]==2)continue;
            for(; in<=m ; in+=(prime[i]) ) {
                st[in-n]=true;
            }
        }
        for(int i=0; i<=m-n; ++i) {
            if(st[i]==0) {
                if(i+n==1)continue;
                printf("%d\n",i+n);
                cnt++;
            }
        }
        memset(st,0,sizeof st);
    }
    return 0;
}*/


