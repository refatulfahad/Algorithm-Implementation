#include<bits/stdc++.h>
using namespace std;

const double esp=1e-9;
int mul[10];



int leading_digits(int n,int k) {
    double x=0.0;

    for(int i=1; i<=n; i++) {
        x+=log10(i);
    }
    double fraction_part=x-floor(x+esp);
    double power=powl(10,fraction_part);
    double ans=power*mul[k-1];
    return floor(ans+esp);
}
int main() {
    mul[0]=1;
    for(int i=1; i<=7; i++) {
        mul[i]=mul[i-1]*10;
    }
    int n,k;///k=how many leading digits you want to see
    scanf("%d %d",&n,&k);
    printf("%d\n",leading_digits(n,k));
    return 0;
}
