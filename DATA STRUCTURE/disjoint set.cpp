#include<bits/stdc++.h>
using namespace std;
#define val 100005
int u,v,n,m,parent[100005],parrank[val],x,y,number[val],cont[val];
void parentfun(int n)
{
    for(int i=1; i<=n; i++)
    {
        parent[i]=i;
        cont[parent[i]]=1;
    }
}
int unionall(int j)
{
    //if(cont[parent[j]]==0){cont[parent[j]]++;}
    if(parent[j]!=j)
    {
        return parent[j]=unionall(parent[j]);
    }
    else
    {
        return j;
    }
}
void ranknum(int p,int l)
{
    //every call takes for worst-case logn.total time complexity nlogn.
    int px=unionall(p);
    int py=unionall(l);
    if(px==py)
    {
        return;
    }
    //if(parrank[px]<parrank[py]){parent[px]=py;}
    //else if(parrank[px]>parrank[py]){parent[py]=px;}
    cont[parent[px]]=cont[parent[px]]+cont[parent[py]];
    if(px!=py)
    {
        parent[py]=px;
        //parrank[px]++;

    }
}
void print()
{
    //for(int i=1;i<=n;i++){
    //for(int j=1;j<=n;j++){
    // if(i==j){continue;}
    // else if(parent[i]==parent[j]){
    //  number[i]++;
    //}
    // }
    //}
    for(int i=1; i<=n; i++)
    {
        printf("%d ",cont[unionall(parent[i])]-1);
    }
}
int main()
{

    scanf("%d",&n);
    parentfun(n);
    scanf("%d",&m);
    for(int i=1; i<=m; i++)
    {
        scanf("%d %d",&u,&v);
        ranknum(u,v);
    }
    print();
    return 0;
}
