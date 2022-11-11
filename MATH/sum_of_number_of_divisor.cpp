#include<bits/stdc++.h>
using namespace std;
///time complexity O(sqrt(n))
int main() {
    int n,SNOD,sum=0;///SNOD=sum of number of divisor
    scanf("%d",&n);
    int limit=sqrt(n);
    for(int i=1; i<=limit; i++) {
        sum+=(n/i)-i;
    }
    SNOD=sum*2;
    SNOD+=limit;
    printf("%d\n",SNOD);
    return 0;
}
