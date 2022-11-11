
#include<bits/stdc++.h>
using namespace std;
int ar[1000];
void mergearr(int p,int q,int r) {
    int n1=q-p+1;
    int n2=r-q;
    int arr1[n1+1],arr2[n2+1];
    for(int i=p,j=1; j<=n1&&i<=q; i++,j++) {
        arr1[j]=ar[i];
    }
    for(int i=q+1,j=1; i<=r&&j<=n2; i++,j++) {
        arr2[j]=ar[i];
    }
    arr1[n1+1]=INT_MAX,arr2[n2+1]=INT_MAX;
    for(int i=1,j=1,k=p; i<=n1||j<=n2; k++) {
        if(arr1[i]<arr2[j]) {
            ar[k]=arr1[i];
            i++;
        } else {
            ar[k]=arr2[j];
            j++;
        }
    }
}
void mergesort(int p,int r) {
    if(p<r) {
        int mid=(p+r)/2;
        mergesort(p,mid);
        mergesort(mid+1,r);
        mergearr(p,mid,r);
    }

}
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        scanf("%d",&ar[i]);
    }
    mergesort(1,n);
    for(int i=1; i<=n; i++) {
        printf("%d ",ar[i]);
    }
    return 0;
}


/*******merge sort using one array*****/
#include <bits/stdc++.h>

long long ans=0;
void merge(int l,int mid,int r,long long *arr,int *a){

    long long i=l,j=mid+1,k=l;
    while(i<=mid&&j<=r){
        if(arr[i]<=arr[j]){
            a[k++]=arr[i++];
        }
        else{
            ans+=(mid-i+(long long)1);
            a[k++]=arr[j++];
        }
    }
    while(i<=mid){
        a[k++]=arr[i++];
    }
    while(j<=r){
        a[k++]=arr[j++];
    }
    for(i;i<=r;++i){
        arr[i]=a[i];
    }
}
void divide(int l,int r,long long *arr,int *a){
    if(l<r){
        int mid=(l+r)/2;
        divide(l,mid,arr,a);
        divide(mid+1,r,arr,a);
        merge(l,mid,r,arr,a);
    }
    else{
        return;
    }
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    int a[n+1];
    divide(0,n-1,arr,a);
    return ans;
}
/****


#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define pli pair<ll,int>
#define grv(v) sort(v.begin(),v.end(),greater<int>())
#define sz(s)  (int)s.size()
#define all(s)  s.begin(),s.end()
#define fll(a,b) memset(a,b,sizeof(a))
#define mnv(v) *min_element(v.begin(),v.end())
#define mxv(v) *max_element(v.begin(),v.end())
#define countv(v,a) count(v.begin(),v.end(),a)
#define el "\n"
#define IOS  ios_base::sync_with_stdio(false),cin.tie(NULL)

const int N = 1e5 + 5;
const ll M = (ll)1e9 + 7;
const ll inf=(ll)1e18;
const double pi=2*acos(0.0);
const double eps=1e-9;


int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};

int a[N];

void merg(int l,int m,int r) {
    int tl[m-l+2],tr[m-l+2];
    int ls=1,rs=1;
    for(int i=l; i<=m; ++i,++ls) {
        tl[ls]=a[i];
    }
    for(int i=m+1; i<=r; ++i,++rs) {
        tr[rs]=a[i];
    }
    int k=1,n=1,in=l;
    while(k<ls&&n<rs) {
        if(tl[k]<=tr[n]) {
            a[in]=tl[k];
            ++k;
        } else {
            a[in]=tr[n];
            ++n;
        }
        ++in;
    }
    for(int i=k; i<ls; ++i) {
        a[in]=tl[i];
        ++in;
    }
    for(int i=n; i<rs; ++i) {
        a[in]=tr[i];
        ++in;
    }
}
void divide(int l,int r) {

    if(l<r) {
        int m=(l+r)/2;
        divide(l,m);
        divide(m+1,r);
        merg(l,m,r);
    } else {
        return;
    }
}
int main() {

    //IOS;
    /// freopen("input.txt","r",stdin);
    /// freopen("output.txt","w",stdout);

    int test=1;
    //cin>>test;
    for(int cs=1; cs<=test; ++cs) {
        int n;
        cin>>n;
        for(int i=1; i<=n; ++i) {
            cin>>a[i];
        }
        divide(1,n);
        for(int i=1; i<=n; ++i) {
            cout<<a[i]<<" ";
        }
    }
    return 0;
}


****/
