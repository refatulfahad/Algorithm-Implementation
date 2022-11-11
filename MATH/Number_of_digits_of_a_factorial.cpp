#include<bits/stdc++.h>
using namespace std;
const int esp=1e-9;
int digit(int n,int base) {
    double x=0;
    for(int i=1; i<=n; i++) {
        x+=(log10(i)/log10(base));///it means i=base^x,when x=(log10(i)/log10(base))
    }
    int cnt=x+1+esp;
    return cnt;
}
int main() {
    int n,base;///base=which base do you want to convert
    scanf("%d %d",&n,&base);
    printf("%d\n",digit(n,base));
    return 0;
}
