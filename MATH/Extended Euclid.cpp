#include<bits/stdc++.h>
using namespace std;
#define ll long long


/// another solution:1

ll X,Y;
ll gcd(int a,int b) {
    int x1,y1,x2,y2,r,q,x,y,r1,r2;
    x1=1,y1=0,x2=0,y2=1;
    ///b>=a
    for(r1=a,r2=b; r1!=0; r2=r1,r1=r,x2=x1,x1=x,y2=y1,y1=y) {
        q=r2/r1;
        r=r2%r1;
        x=x2-(q*x1);
        y=y2-(q*y1);
    }
    X=x2,Y=y2;
    cout<<X<<" "<<Y<<endl;
    return r2;
}


///recursive solution:2

ll x1,y1,l=0;
ll gcd(ll a,ll b,ll x,ll y) {
    if(a==0) {
        x1=0;
        y1=1;
        return b;
    }
    l++;
    ll d=gcd(b%a,a,x,y);
    x=x1,y=y1;
    l--;

    x1=y-((b/a)*x);
    y1=x;
    if(l==0)
        cout<<"x= a*"<<x1<<" "<<"y= b*"<<y1<<" ";
    return d;
}
int main() {
    ll a,b,c;
    scanf("%lld %lld",&a,&b);
    /*if(a>b) {
        //c=a;
        //a=b;
       // b=c;
    }*/
    cout<<"gcd= "<<gcd(a,b)<<" ";///solution:1
    cout<<"gcd= "<<gcd(a,b,0,0)<<" ";///solution:2
    return 0;
}
