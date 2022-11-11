/**#include<bits/stdc++.h>
using namespace std;
int a[100009];
struct abc
{
     int sum,prop;
};
abc tree[4*100009];
void init(int node,int L,int R)
{
    if(L==R)
    {
        tree[node].sum=a[L];
        return;
    }
    int mid=(L+R)/2;
    int left=node*2;
    int right=node*2+1;
    init(left,L,mid);
    init(right,mid+1,R);
    tree[node].sum=tree[left].sum+tree[right].sum;
}
void update(int node,int L,int R,int l,int r,int x)
{
    if(l>R||r<L)
    {
        return;
    }
    if(l<=L&&r>=R)
    {
        tree[node].sum+=(R-L+1)*x;
        tree[node].prop+=x;
        return;
    }
    int mid=(L+R)/2;
    int left=node*2;
    int right=node*2+1;
    update(left,L,mid,l,r,x);
    update(right,mid+1,R,l,r,x);
    tree[node].sum=tree[left].sum+tree[right].sum+((R-L+1)*tree[node].prop);
}
int query(int node,int L,int R,int l,int r, int carry)
{
    if(l>R||r<L)
    {
        return 0;
    }
    if(l<=L&&r>=R)
    {   //cout<<carry<<" ";
        return tree[node].sum+(R-L+1)*carry;
    }
    int mid=(L+R)/2;
    int left=node*2;///R-L+1)*(R-L+1)*
    int right=node*2+1;
    int x1=query(left,L,mid,l,r,carry+(tree[node].prop));
    int x2=query(right,mid+1,R,l,r,carry+(tree[node].prop));
    return x1+x2;
}
int main()
{
    int n,m,l,r;
    scanf("%d %d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    init(1,1,n);
    for(int i=1; i<=m; i++)
    {  int ck;
        scanf("%d",&ck);
        if(ck==1)
        {
            int x;
            scanf("%d %d %d",&l,&r,&x);
            update(1,1,n,l,r,x);
        }
        else
        {
            scanf("%d %d",&l,&r);
            printf("%d",query(1,1,n,l,r,0));
        }
    }
    return 0;
}**/
/****wrong alternate**/
#include<bits/stdc++.h>
using namespace std;
int a[100009], cont = 0;
struct abc {
    int sum, prop;
};
abc tree[4 * 100009];
void init(int node, int L, int R) {
    if (L == R) {
        tree[node].sum = a[L];
        return;
    }
    int mid = (L + R) / 2;
    int left = node * 2;
    int right = node * 2 + 1;
    init(left, L, mid);
    init(right, mid + 1, R);
    tree[node].sum = tree[left].sum + tree[right].sum;
}
void propagate(int node, int L, int R) {
    tree[node * 2].prop = tree[node * 2 + 1].prop = tree[node].prop;
    int mid = (L + R) / 2;
    tree[node * 2].sum = (mid - L + 1) * tree[node].prop;
    tree[node * 2 + 1].sum = (R - mid) * tree[node].prop;
    tree[node].prop = -1;
}
void update(int node, int L, int R, int l, int r, int x) {
    if (l > R || r < L) {
        return;
    }
    if (l <= L && r >= R) {
        //int val=x-(tree[node].sum/(R-L+1));
        tree[node].sum = (R - L + 1) * x;
        cont = (R - L + 1);
        //cout<<R<<L<<" "<<tree[node].sum<<endl;//<<" "<<tree[node].prop<<" ";
        tree[node].prop = x;
        //cout<<tree[node].prop<<endl;
        return;
    }
    if (tree[node].prop >= 0)propagate(node, L, R);
    int mid = (L + R) / 2;
    int left = node * 2;
    int right = node * 2 + 1;
    update(left, L, mid, l, r, x);
    update(right, mid + 1, R, l, r, x);
    tree[node].sum = tree[left].sum + tree[right].sum;
    cout << tree[node].sum << " ";
}
int query(int node, int L, int R, int l, int r) {
    if (l > R || r < L) {
        return 0;
    }
    if (l <= L && r >= R) {
        //cout<<carry<<" ";
        //if(tree[node].prop!=0) carry=0;//tree[node].sum;return
        //else
        //cout<<tree[node].sum<<endl;
        return tree[node].sum;////
    }
    int mid = (L + R) / 2;
    int left = node * 2; ///R-L+1)*(R-L+1)*
    int right = node * 2 + 1;
    int x1 = query(left, L, mid, l, r); //-carrycarry-carry-
    int x2 = query(right, mid + 1, R, l, r); //carry+carry-carry-
    return x1 + x2;
}
int main() {
    int n, m, l, r;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    init(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int ck;
        scanf("%d", &ck);
        if (ck == 1) {
            int x;
            cont = 0;
            scanf("%d %d %d", &l, &r, &x);
            update(1, 1, n, l + 1, r + 1, x);
        } else {
            scanf("%d %d", &l, &r);
            printf("%d", query(1, 1, n, l + 1, r + 1));
        }
    }
    return 0;
}

