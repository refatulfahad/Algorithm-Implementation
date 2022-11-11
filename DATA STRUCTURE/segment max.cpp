#include<bits/stdc++.h>
using namespace std;
int a[10000],tree[10000];
void init(int node,int L,int R)
{
    if(L==R)
    {
        tree[node]=a[L];
        return;
    }
    int mid=(L+R)/2;
    int left=node*2;
    int right=node*2+1;
    init(left,L,mid);
    init(right,mid+1,R);
    if(tree[left]>tree[right])
    {
        tree[node]=tree[left];
    }
    else
    {
        tree[node]=tree[right];
    }
}
int query(int node,int L,int R,int l,int r)
{
    if(l>R||r<L)
    {
        return -1;
    }
    if(l<=L&&r>=R)
    {
        return tree[node];
    }
    int mid=(L+R)/2;
    int left=node*2;
    int right=node*2+1;
    int x=query(left,L,mid,l,r);
    int y=query(right,mid+1,R,l,r);
    if(x>y)
        return x;
    else
        return y;
}
void update(int  node,int L,int R,int pos,int value)
{
    if(pos<L||pos>R)
    {
        return;
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
    if(tree[left]>tree[right])
    {
        tree[node]=tree[left];
    }
    else
    {
        tree[node]=tree[right];
    }
}
int main()
{
    int n,m;
    scanf("%d ",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    init(1,1,n);
    printf("%d\n",query(1,1,n,2,4));
    //update(1,1,n,2,1000);
    //printf("%d",query(1,1,n,2,4));
    return 0;
}
