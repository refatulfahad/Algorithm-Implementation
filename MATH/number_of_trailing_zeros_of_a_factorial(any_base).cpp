#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int lp[N+5];
vector<int>prime;
vector<pair<int,int> >vt;
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
void factorize_base(int n) {
    int limit=sqrt(n*1.0);
    for(int i=0; i<prime.size()&&prime[i]<=limit; i++) {
        int cnt=0;
        if(n%prime[i]==0) {
            while(n%prime[i]==0) {
                n/=prime[i];
                cnt++;
            }
            vt.push_back({prime[i],cnt});
            limit=sqrt(n);
        }
        //printf("%d %d\n",prime[i],cnt)
    }
    if(n!=1) {
        vt.push_back({n,1});
    }

}
int factorize_value(int n) {
    int ans=INT_MAX;
    for(int i=0; i<vt.size(); i++) {
        int x=n;
        int cnt=0;
        while(x) {
            cnt+=(x/vt[i].first);
            x/=vt[i].first;
        }
        //cout<<vt[i].first<<endl;
        ans=min(ans,cnt/vt[i].second);
    }
    return ans;
}
int main() {
    sieve();
    int n,base;
    scanf("%d %d",&n,&base);
    factorize_base(base);
    printf("number of zero:%d",factorize_value(n));
    return 0;
}
