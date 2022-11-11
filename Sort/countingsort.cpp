#include<bits/stdc++.h>
using namespace std;
int cont[100000000],a[100000000],tem[100000000];
int main()
{
    int n,x=-1;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        if(x<a[i])
        {
            x=a[i];
        }
        cont[a[i]]++;
    }
    for(int i=1; i<=x; i++)
    {
        cont[i]=cont[i]+cont[i-1];
    }
    for(int i=n-1; i>=0; i--)
    {
        tem[cont[a[i]]]=a[i];
        cont[a[i]]--;
    }
    int j=0;
    for(int i=1; i<=n; i++)
    {
        if(tem[i]>0)
            cout<<tem[i]<<" ";
        a[j]=tem[i];
        j++;
    }
    return 0;
}
