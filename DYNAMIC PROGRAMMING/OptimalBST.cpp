#include<bits/stdc++.h>
using namespace std;
int ar[10000],fr[10000];
int sum(int i,int j)
{
    int Sum=0;
    for(int i1=i; i1<=j; i1++)
    {
        Sum+=fr[i1];
    }
    return Sum;
}
int optimal(int i,int j)
{
    if(j<i)
    {
        return 0;
    }
    if(i==j)
    {
        return fr[i];
    }
    int fsum=sum(i,j);
    int Min=INT_MAX,cost;
    for(int r=i; r<=j; r++)
    {
        cost=optimal(i,r-1)+optimal(r+1,j);
        if(Min>cost)
        {
            Min=cost;
        }
    }
    return Min+fsum;
}
int main()
{
    int n;
    scanf("%d ",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&ar[i]);
    }
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&fr[i]);
    }
    cout<<optimal(1,n);
    return 0;
}
