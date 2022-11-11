#include<bits/stdc++.h>
using namespace std;
int ar[10000],query[100][100];
void Build_rmq(int n)
{
    for(int i=1; i<=n; i++)
    {
        query[i][0]=ar[i];
    }

    for(int j=1; (1<<j)<=n; j++)
    {
        for(int i=1; i+(1<<j)-1<=n; i++)
        {
            query[i][j]=min(query[i][j-1],query[i+(1<<(j-1))][j-1]);
        }
    }
}
int result_query(int l,int r)
{
    int num=(r-l)+1;
    int k=log2(num);
    return min(query[l][k],query[l+num-(1<<k)][k]);
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
    while(q--){
        int left,right;
        scanf("%d %d",&left,&right);
        cout<<result_query(left,right)<<endl;
    }
    return 0;
}
