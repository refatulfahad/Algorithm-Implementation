#include<bits/stdc++.h>
using namespace std;
///Axy+Bx+Cy=D
///x=?,y=?
bool check(int a,int b,int c,int p,int div) {
    if((div-c)%a!=0)return false;///solution x=(div-c)/a;
    if((p-(b*div))%(a*div)!=0)return false;///solution y=(p-(b*div))/(a*div)
    return true;
}
int diophentine_equation(int a,int b,int c,int d) {
    int p=(a*d)+(b*c);
    if(p==0) {
        if(-c%a==0)return -1;///infinite solution (-(c/a),k)
        else if(-b%a==0)return -1;///infinite solution (k,-(b/a))
        else return 0;///no solution
    }
    int srt=sqrt(p),res=0;
    for(int i=1; i<=srt; i++) {
        if(p%i==0) {
            if(check(a,b,c,p,i)) {
                res++;
                cout<<(i-c)/a<<" "<<(p-(b*i))/(a*i)<<endl;///solution
            }
            if(check(a,b,c,p,-i)) {
                res++;
                cout<<((-i)-c)/a<<" "<<(p-(b*(-i)))/(a*(-i))<<endl;///solution
            }
            if(p/i!=i) {
                if(check(a,b,c,p,p/i)) {
                    res++;
                    cout<<((p/i)-c)/a<<" "<<(p-(b*(p/i)))/(a*(p/i))<<endl;///solution
                }
                if(check(a,b,c,p,-(p/i))) {
                    res++;
                    cout<<((-p/i)-c)/a<<" "<<(p-(b*(-p/i)))/(a*(-p/i))<<endl;///solution
                }
            }
        }
    }
    return res;
}
int main() {
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    int ck=diophentine_equation(a,b,c,d);
    if(ck==-1) {
        printf("infinite solution\n");
    } else if(ck==0) {
        printf("no solution");
    } else {
        printf("total solution= %d\n",ck);
    }
}
