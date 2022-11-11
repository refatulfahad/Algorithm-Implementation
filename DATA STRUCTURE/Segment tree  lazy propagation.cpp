#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int in()
{
    int n;///17312754
    scanf("%d", &n);
    return n;
}

int tree[3 * N];

void propagate(int pos)
{
    tree[pos]=0;
    tree[pos*2]^=1;
    tree[pos*2+1]^=1;
}

void update(int pos, int left, int right, int x, int y)
{
    if(left>y || right<x) return;
    if(left>=x && right<=y)
    {
        tree[pos]^=1;
        return;
    }
    if(tree[pos]) propagate(pos);
    int mid=(left+right)>>1;
    update(pos*2, left, mid, x, y);
    update(pos*2+1, mid+1, right, x, y);
}

int query(int pos, int left, int right, int x)
{
    if(left>x || right<x) return 0;
    if(left==right) return tree[pos];
    if(tree[pos]) propagate(pos);
    int mid=(left+right)>>1;
    if(x<=mid) return query(pos*2, left, mid, x);
    else return query(pos*2+1, mid+1, right, x);
}

int main()
{
    int n=in(), q=in();

    while(q--)
    {
        int ck=in();
        if(ck==1)
        {
            int x=in(), y=in();
            //cout<<n<<" ";
            update(1, 1, n, x, y);
        }
        else
        {
            int x=in();
            printf("%d\n", query(1, 1, n, x));
        }
    }
    return 0;
}
/**
#include<bits/stdc++.h>
using namespace std;
int a[100009],cont=0;
struct abc {
    int sum,prop;
};
abc tree[4*100009];

void propagate(int node,int L,int R) {
    tree[node*2].prop=tree[node*2+1].prop=tree[node].prop;
    int mid=(L+R)/2;
    tree[node*2].sum=(mid-L+1)*tree[node].prop;
    tree[node*2+1].sum=(R-mid)*tree[node].prop;
    tree[node].prop=-1;
}
void update(int node,int L,int R,int l,int r,int x) {
    if(l>R||r<L) {
        return;
    }
    if(l<=L&&r>=R) {
        //int val=x-(tree[node].sum/(R-L+1));
        tree[node].sum=(R-L+1)*x;
        cont=(R-L+1);
        //cout<<R<<L<<" "<<tree[node].sum<<endl;//<<" "<<tree[node].prop<<" ";
        tree[node].prop=x;
        //cout<<tree[node].prop<<endl;
        return;
    }
    if(tree[node].prop>=0)propagate(node,L,R);
    int mid=(L+R)/2;
    int left=node*2;
    int right=node*2+1;
    update(left,L,mid,l,r,x);
    update(right,mid+1,R,l,r,x);
    tree[node].sum=tree[left].sum+tree[right].sum;
    //cout<<tree[node].sum<<" ";
}
int query(int node,int L,int R,int l,int r) {
    if(l>R||r<L) {
        return 0;
    }
    if(l<=L&&r>=R) {
        return tree[node].sum;////
    }
    if(tree[node].prop>=0)propagate(node,L,R);
    int mid=(L+R)/2;
    int left=node*2;///R-L+1)*(R-L+1)*
    int right=node*2+1;
    int x1=query(left,L,mid,l,r);//-carrycarry-carry-
    int x2=query(right,mid+1,R,l,r);//carry+carry-carry-
    return x1+x2;
}
int main() {
    int n,m,l,r,t,Case=0;
    scanf("%d",&t);
    while(t--) {
        Case++;
        printf("Case %d:\n",Case);
        scanf("%d %d",&n,&m);
        for(int i=1; i<=m; i++) {
            int ck;
            scanf("%d",&ck);
            if(ck==1) {
                int x;
                cont=0;
                scanf("%d %d %d",&l,&r,&x);
                update(1,1,n,l+1,r+1,x);
            } else {
                scanf("%d %d",&l,&r);
                int res=query(1,1,n,l+1,r+1);
                if(res%(r-l+1)==0) {
                    printf("%d\n",res/(r-l+1));
                } else {
                    int GCD=__gcd(res,r-l+1);
                    printf("%d/%d\n",res/GCD,(r-l+1)/GCD);
                }
            }
        }
        for(int i=1; i<=n; i++) {
            tree[i].sum=0,tree[i].prop=0;
        }
    }
    return 0;
}

**/
