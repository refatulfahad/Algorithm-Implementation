#include<bits/stdc++.h>
using namespace std;
int a[100009];
struct abc
{
    int prop,num;
};
abc tree[4*100009];
void init(int node,int L,int R)
{
    if(L==R)
    {
        tree[node].num=a[L];
        return;
    }
    int mid=(L+R)/2;
    int left=node*2;
    int right=node*2+1;
    init(left,L,mid);
    init(right,mid+1,R);
}
void update(int node,int L,int R,int l,int r,int x)
{
    if(l>R||r<L)
    {
        return ;
    }
    if(l<=L&&r>=R)
    {
        tree[node].prop+=x;
        return;
    }
    int mid=(L+R)/2;
    int left=node*2;
    int right=node*2+1;
    update(left,L,mid,l,r,x);
    update(right,mid+1,R,l,r,x);
    //tree[node].num=tree[left].prop+tree[right].prop+tree[node].prop;
}
int query(int node,int L,int R,int pos,int carry)
{
    if(pos<L||pos>R)
    {
        return 0;
    }
    if(L==R)
    {
        return tree[node].num+carry+tree[node].prop;
    }
    int mid=(L+R)/2;
    int left=node*2;
    int right=node*2+1;
    int x=query(left,L,mid,pos,carry+tree[node].prop);
    int y=query(right,mid+1,R,pos,carry+tree[node].prop);
    return x+y;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    init(1,1,n);
    for(int i=1; i<=m; i++)
    {
        int ck,l,r,pos,x;
        scanf("%d",&ck);
        if(ck==1)
        {
            scanf("%d %d %d",&l,&r,&x);
            update(1,1,n,l,r,x);
        }
        else
        {
            scanf("%d",&pos);
            printf("%d",query(1,1,n,pos,0));
        }
    }
    return 0;
}
