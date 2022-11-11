#include<bits/stdc++.h>
using namespace std;
struct abc
{
    double p,w,u;
};
abc e[10000];
bool compare(abc a,abc b)
{
    return a.u<b.u;
}
int main()
{
    int n,capacity;
    double profit=0;
    scanf("%d %d",&n,&capacity);
    for(int i=1; i<=n; i++)
    {
        scanf("%lf %lf",&e[i].p,&e[i].w);
    }
    for(int i=1; i<=n; i++)
    {
        e[i].u=e[i].p/e[i].w;
    }
    sort(e+1,e+n+1,compare);
    for(int i=n; i>=1; i--)
    {
        if(e[i].w<=capacity)
        {
            capacity-=e[i].w;
            profit+=e[i].w*e[i].u;
        }
        else
        {
            profit+=capacity*e[i].u;
            break;
        }
    }
    printf("%f",profit);
    return 0;
}
