/*
/**Bismillahir Rahmanir Raheem
    Author:Refat(BSMRSTU)**
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define pil pair<int,ll>
const int N = 1e5 + 5;
const int M = 1e9 + 7;
const double pi=2*acos(0.0);
const double esp=1e-9;
int Set(int N,int pos) {
    return N=N | (1<<pos);
}
int reset(int N,int pos) {
    return N= N & ~(1<<pos);
}
bool check(int N,int pos) {
    return (bool)(N & (1<<pos));
}

int ar[105];
int main() {
    /// freopen("input.txt","r",stdin);
    /// freopen("output.txt","w",stdout);

    int test=1;
    scanf("%d",&test);
    for(int cs=1; cs<=test; ++cs) {
        int n,cnt=0,sum=0;
        scanf("%d",&n);
        for(int i=1; i<=n; ++i) {
            scanf("%d",&ar[i]);
            if(ar[i]<0)cnt++;
            sum+=abs(ar[i]);
        }
        int v1,v2;
        bool ck=false;
        if(cnt==0) {
            int g=__gcd(sum,n);
            v1=sum/g,v2=n/g;
            ck=true;
        } else {
            if(n-cnt>0) {
                n-=cnt;
                int g=__gcd(sum,n);
                v1=sum/g,v2=n/g;
                ck=true;
            }
        }
        if(ck) {
            printf("Case %d: %d/%d\n",cs,v1,v2);
        } else {
            printf("Case %d: inf\n",cs);
        }
    }
    return 0;
}

*/

/*
#include<bits/stdc++.h>
using namespace std;

double ar[105];
int main() {
    int test,n;
    scanf("%d",&test);
    for(int cs=1; cs<=test; ++cs) {
        scanf("%d",&n);
        for(int i=1; i<=n; ++i) {
            scanf("%lf",&ar[i]);
        }
        for(int i=n-1; i>=1; --i) {
            double cnt=0.0,sum=0.0;
            for(int j=i+1; j<=n&&cnt<6; ++j) {
                sum+=ar[j];
                cnt++;
            }
            if(cnt!=0) {
                ar[i]+=(1.0/cnt)*sum;
            }
        }
        printf("Case %d: %.10f\n",cs,ar[1]);
    }
    return 0;
}

*/
