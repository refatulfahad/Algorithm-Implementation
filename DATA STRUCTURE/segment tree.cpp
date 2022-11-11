#include<bits/stdc++.h>
using namespace std;
int a[10000],tree[1000];
void init(int node,int L,int R)
{
    int left;
    if(L==R)
    {
        tree[node]=a[L];
        return ;
    }
    left=node*2;
    int right=node*2+1;
    int mid=(L+R)/2;
    init(left,L,mid);
    init(right,mid+1,R);
    tree[node]=tree[left]+tree[right];
}
int query(int node,int L,int R,int l,int r)
{
    if(r<L||l>R)
    {
        return 0;
    }
    if(l<=L&&r>=R)
    {
        return tree[node];
    }
    //if(left>y || right<x) return 0LL;
    ///if(left>=x && right<=y) return tree[pos];
    int left=node*2;
    int right=node*2+1;
    int mid=(L+R)/2;
    int x=query(left,L,mid,l,r);
    int y=query(right,mid+1,R,l,r);
    return x+y;
}
void update(int node,int L,int R,int pos,int value)
{
    if(pos<L||pos>R)
    {
        return ;
    }
    if(L==R)
    {
        tree[node]=value;
        return;
    }
    int mid=(L+R)/2;
    int left=node*2;
    int right=node*2+1;
    update(left,L,mid,pos,value);
    update(right,mid+1,R,pos,value);
    tree[node]=tree[left]+tree[right];
}
int main()
{
    int n;
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    init(1,1,n);
    printf("%d\n",query(1,1,n,2,3));
    update(1,1,n,3,5);
    printf("%d",query(1,1,n,2,3));
    return 0;
}
