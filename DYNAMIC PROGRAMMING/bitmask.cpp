#include<bits/stdc++.h>
using namespace std;

int w[20][20];
int n;
int dp[(1 << 15) + 2];
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
int call(int mask)
{
    if (mask == (1 << n) - 1) return 0;
    if (dp[mask] != -1) return dp[mask];
    int mn = 1 << 28;
    for (int i = 0; i < n; i++)
    {
        if (check(mask, i) == 0)
        {
            int price = w[i][i];
            for (int j = 0; j < n; j++)
            {
                if (i != j and check(mask, j) != 0)
                {
                    price += w[i][j];
                }
            }
            int ret = price + call(Set(mask, i));
            mn = min(mn, ret);
            //if(mask==0)
            //cout<<mn<<endl;

        }
    }
    return dp[mask] = mn;
}
int main()
{
    memset(dp, -1,sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &w[i][j]);

        }
    }

    int ret = call(0);
    printf("%d\n", ret);

    return 0;
}

/***
#include<bits/stdc++.h>
using namespace std;
bool check(int N,int pos) {
    return (bool)(N & (1<<pos));
}
int ar[20];
int main() {
    int n,p=1,res;
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d",&ar[i]);
    }
    for(int i=1; i<=n; i++) {
        p=p*2;
    }
    p-=1;
    //cout<<p;
    for(int i=0; i<=p; i++) {
        res=0;
        for(int j=0; j<n; j++) {
            int ck=check(i,j);
            if(ck==1) {
                res+=ar[j];
            } else {
                res-=ar[j];
            }
            res%=360;
        }
        if(res==0) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}

***/
