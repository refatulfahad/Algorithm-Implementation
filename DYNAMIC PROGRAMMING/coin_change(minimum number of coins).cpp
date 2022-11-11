
/**************Number of coins********/
#include<bits/stdc++.h>
using namespace std;

///Author:Refat(BSMRSTU)///

#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define pil pair<int,ll>
const int N=1e5+5;
const int M=1e9+7;
int coin[10005],show[10005];
int main() {
    int n,taka,ck;
    scanf("%d %d",&n,&taka);
    for(int i=1; i<=n; i++) {
        scanf("%d",&coin[i]);
    }
    int ar[taka+5];
    ar[0]=0;
    for(int i=0; i<=n; i++) {
        for(int j=1; j<=taka; j++) {
            if(i==0) {
                ar[j]=INT_MAX-1;
            } else if(coin[i]<=j) {
                ck=ar[j];
                ar[j]=min(ar[j],ar[j-coin[i]]+1);
                if(ck!=ar[j])
                    show[j]=i;
            }//if(i==n)cout<<show[j]<<" ";
        }

    }//cout<<show[taka];
    printf("%d\n",ar[taka]);
    cout<<"coin"<<endl;
    int jj=taka;
    while(jj>0) {
        cout<<coin[show[jj]]<<" ";
        jj-=coin[show[jj]];
        if(coin[show[jj]]==0) {
            cout<<"Impossible";
            break;
        }
    }
    return 0;
}
**/
/*********Number of ways && infinite coin && combination********
#include<bits/stdc++.h>
using namespace std;

///Author:Refat(BSMRSTU)///

#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define pil pair<int,ll>
const int N=1e5+5;
const int M=1e9+7;
int coin[10005],ar[5000][5000];
int main() {
    int n,taka;
    scanf("%d %d",&n,&taka);
    for(int i=1; i<=n; i++) {
        scanf("%d",&coin[i]);
    }
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=taka; j++) {
            if(i==0||j==0)ar[i][j]=0;
            else if(coin[i]==j) {
                ar[i][j]=ar[i-1][j]+1;
            } else if(coin[i]<=j) {
                if(ar[i][j-coin[i]]!=0) {
                    ar[i][j]=ar[i-1][j]+ar[i][j-coin[i]];
                } else {
                    ar[i][j]=ar[i-1][j];
                }
            } else {
                ar[i][j]=ar[i-1][j];
            }
            cout<<ar[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<ar[n][taka];
    return 0;
}
///Alter solution
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
const long long M=1e9+7;
long long ar[N];
int main() {
    int n;
    scanf("%d",&n);
    ar[0]=1;
    for(int i=1; i<=6; i++) {
        for(int j=i; j<=n; j++) {
            //if(i<j)break;
            ar[j]+=ar[j-i];
            ar[j]%=M;
        }
    }
    cout<<ar[n]<<endl;
    return 0;
}

**/
/*********Number of ways && infinite coin && permutation********
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
const long long M=1e9+7;
long long ar[N];
int main() {
    int n;
    scanf("%d",&n);///n=taka,6=coin
    ar[0]=1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=6; j++) {
            if(i<j)break;
            ar[i]+=ar[i-j];
            ar[i]%=M;
        }
    }
    cout<<ar[n]<<endl;
    return 0;
}
**/
/**********dp solution coin change (infinite)YES or NO print********/
/*#include<bits/stdc++.h>
using namespace std;

///Author:Refat(BSMRSTU)///

#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define pil pair<int,ll>
const int N=1e5+5;
const int M=1e9+7;
int dp[1000][1000],coin[1000],taka,n;
int fun(int i,int amount) {
    if(i>n) {
        if(amount==0) {
            return 1;
        } else {
            return 0;
        }
    }
    int ans1,ans2;
    if(dp[i][amount]!=0)return dp[i][amount];
    if(amount-coin[i]>=0) {
        ans1=fun(i,amount-coin[i]);
    } else {
        ans1=0;
    }
    ans2=fun(i+1,amount);
    return dp[i][amount]=ans1|ans2;
}
int main() {

    scanf("%d %d",&n,&taka);
    for(int i=1; i<=n; i++) {
        scanf("%d",&coin[i]);
    }
    if(fun(1,taka)==1) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}*/

/***dp solution coin change (infinite) minimum number of coins do you need****


#include<bits/stdc++.h>
using namespace std;

///Author:Refat(BSMRSTU)///

#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define pil pair<int,ll>
const int N=1e5+5;
const int M=1e9+7;
int dp[1000][1000],coin[1000],taka,n;
int fun(int i,int amount) {
    if(amount==0) {
        return 0;
    }
    if(i>n) {
        return 1000000000;
    }
    int ans1=INT_MAX,ans2=INT_MAX;
    if(dp[i][amount]!=-1)return dp[i][amount];
    if(amount-coin[i]>=0) {
        ans1=1+fun(i,amount-coin[i]);
    }
    ans2=fun(i+1,amount);
    return dp[i][amount]=min(ans1,ans2);
}
int main() {
    memset(dp,-1,sizeof(dp));
    scanf("%d %d",&n,&taka);
    for(int i=1; i<=n; i++) {
        scanf("%d",&coin[i]);
    }
    cout<<fun(1,taka);
    return 0;
}

*/


















