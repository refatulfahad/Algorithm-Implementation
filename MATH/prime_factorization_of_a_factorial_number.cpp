
///time:N*log2(N)
#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int lp[N+5];
vector<int>prime;
void sieve() {
    for(int i=2; i<=N; i++) {
        if(lp[i]==0) {
            lp[i]=i;

            prime.push_back(i);
        }
        for(int j=0; j<prime.size()&&prime[j]<=lp[i]&&i*prime[j]<=N; j++) {
            lp[i*prime[j]]=prime[j];
        }
    }
}
void factorize(int n) {
    for(int i=0; i<prime.size()&&prime[i]<=n; i++) {
        int x=n;
        int cnt=0;
        while(x) {
            cnt+=(x/prime[i]);
            x/=prime[i];
        }
        printf("%d %d\n",prime[i],cnt);
    }
}
int main() {
    sieve();
    int n;
    scanf("%d",&n);
    factorize(n);
    return 0;
}
