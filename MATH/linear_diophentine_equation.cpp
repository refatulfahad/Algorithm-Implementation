#include<bits/stdc++.h>
using namespace std;
///Ax+By=C
///x=?,y=?
int X,Y;
void ext_euclid_gcd(int a,int b) {
    int x1,y1,r1,r2,x2,y2,r,q,x,y;
    x1=1,y1=0,x2=0,y2=1;
    for(r1=a,r2=b; r1!=0; x2=x1,r2=r1,x1=x,r1=r) {
        q=r2/r1;
        r=r2%r1;
        x=x2-(q*x1);
        y=y2-(q*y1);
    }
    X=x2,Y=y2;
}
bool linear_diophentine_equation(int A,int B,int C) {
    int g=__gcd(A,B),a,b,c;
    if(C%g!=0)return false;
    a=A/g,b=B/g,c=C/g;
    ext_euclid_gcd(a,b);
    if(g<0)a*=-1,b*=-1,c*=-1;
    X*=c,Y*=c;
    return true;
}
int main() {
    int A,B,C;
    X=0,Y=0;
    scanf("%d %d %d",&A,&B,&C);
    bool ck=linear_diophentine_equation(A,B,C);
    if(ck==false) {
        printf("no solution");
    } else {
        printf("%d %d\n",X,Y);
        int g=__gcd(A,B);
        int k=1;
        printf("another possible solution: %d %d",X+(k*(B/g)),Y-(k*(A/g)));
    }
    return 0;
}
