#include<bits/stdc++.h>
using namespace std;
int a[100];int i,j,n;
void quicks(int f,int l)
{
    int i,j;
    if(f<l)
    {
        i=f+1;
        j=l;
        while(a[f]>a[i]&&i<n)///akhane pivot first number
        {
            i++;
        }
        while(a[f]<a[j])
        {
            j--;
        }
        while(i<j)
        {
            swap(a[i],a[j]);
            while(a[f]>a[i])
            {
                i++;
            }
            while(a[f]<a[j])
            {
                j--;
            }
        }

        swap(a[j],a[f]);
        quicks(f,j-1);
        quicks(j+1,l);
    }
}
int main()
{

    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);}

        quicks(0,n-1);
        for(i=0; i<n; i++)
        {
            printf("%d ",a[i]);
        }

    return 0;
}
/***



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

void quick(int pi,int si,int ei) {
    int tsi=si,tei=ei;//pi=pivot_index,si=start_index,ei=end_index
    if(tsi<tei) {//tpi=temporary_pivot_index
        while(tsi<=tei) {
            while(a[tsi]<=a[pi]&&tsi<=tei) {
                ++tsi;
            }
            while(a[tei]>a[pi]&&tsi<=tei) {
                --tei;
            }
            if(tsi<tei)swap(a[tsi],a[tei]);
        }
        swap(a[pi],a[tei]);
        quick(si,si,tei-1);
        quick(tei+1,tei+1,ei);
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
        int pi=1,si=1,ei=n;
        quick(1,1,n);
        for(int i=1;i<=n;++i){
            cout<<a[i]<<" ";
        }
    }
    return 0;
}


*/
