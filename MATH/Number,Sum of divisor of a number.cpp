#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int len,ar[N],prime[N];
void scieve(int n) {
    len=1;
    int limit=sqrt(n*1.0)+2;
    prime[1]=2;
    for(int i=3; i<=limit; i+=2) {
        if(ar[i]==0) {
            for(int j=i*i; j<=n; j+=i*2) {
                ar[j]=1;
            }
        }
    }
    /// number of prime upto n
    for(int i=3; i<=n; i+=2) {
        if(ar[i]==0) {
            //cout<<i<<" ";
            len++;
            prime[len]=i;
        }
    } //cout<<len<<" ";
}
int main() {
    ///sod (sum of divisor)
    ///nod (number of divisor)
    int n,nod=1,res,sod=1,p,val,cnt,temsum;
    scanf("%d",&n);
    scieve(n);
    val=n;
    int n1=sqrt(n*1.0);///time complexity(sqrt(N)/ln(sqrt(N)))+log2(N):
    for(int i=1; i<=len&&prime[i]<=n1; i++) {
        if(n%prime[i]==0) {
                cnt=0,temsum=1,p=1;
            while(n%prime[i]==0) {
                cnt++;
                n/=prime[i];
                p*=prime[i];
                temsum+=p;
            }
            n1=sqrt(n*1.0);
            nod*=(cnt+1);
            sod*=temsum;
        }
    }
    if(n!=1)nod*=2;///number of divisor
    if(n!=1)sod*=(n+1); ///sum of divisor
    printf("%d %d",nod,sod);
    return 0;
}

