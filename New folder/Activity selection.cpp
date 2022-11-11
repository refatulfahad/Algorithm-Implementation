#include<bits/stdc++.h>
using namespace std;
struct abc
{
    int s,f,pos;
};
abc Time[10000];
bool compare(abc a,abc b)
{
    return a.f<b.f;
}
void activity_selection(int n)
{
    int j=1;
    printf("%d ",Time[j].pos);
    for(int i=2; i<=n; i++)
    {
        if(Time[i].s>=Time[j].f)
        {
            printf("%d ",Time[i].pos);
            j=i;
        }
    }
}
int main()
{
    int n,x,y;
    scanf("%d",&n);///{5, 9}, {1, 2}, {3, 4}, {0, 6},{5, 7}, {8, 9}
                    ///1, 3, 0, 5, 8, 5
                   ///2, 4, 6, 7, 9, 9
    for(int i=1; i<=n; i++)
    {
        scanf("%d %d",&Time[i].s,&Time[i].f);
        Time[i].pos=i;
    }
    sort(Time+1,Time+n+1,compare);
    activity_selection(n);
    return 0;
}
