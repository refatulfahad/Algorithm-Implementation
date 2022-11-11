#include<bits/stdc++.h>
using namespace std;
int ar[1000],query[1000][1000];
void Build_rmq(int n)
{
    for(int i=1; i<=n; i++)
    {
        query[i][0]=ar[i];
    }
    for(int j=1; (1<<j)<=n; j++)
    {
        for(int i=1; i+(1<<(j-1))<=n; i++)
        {
            query[i][j]=query[i][j-1]+query[i+(1<<(j-1))][j-1];
        }
    }
}
int result_query(int l,int r)
{
    int sum=0;
    int k=log2(r-l+1);
    for(int i=k; i>=0; i--)
    {
        if(l+(1<<i)-1<=r)
        {
            sum+=query[l][i];
            l+=(1<<i);
        }
    }
    return sum;
}
int main()
{
    int n,q;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&ar[i]);
    }
    Build_rmq(n);
    scanf("%d",&q);
    while(q--)
    {
        int left,right;
        scanf("%d %d",&left,&right);
        cout<<result_query(left,right)<<endl;
    }
    return 0;
}
