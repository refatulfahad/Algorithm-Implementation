#include<bits/stdc++.h>
using namespace std;
int call(int a1, int b1, int a2, int b2) {
    return a1 * b2 - a2 * b1;
}

int solve() {
    int a1, b1, c1, a2, b2, c2;
    scanf("%d %d %d", &a1, &b1, &c1);
    scanf("%d %d %d", &a2, &b2, &c2);
    double x, y;
    x = (double)call(c1, b1, c2, b2) / call(a1, b1, a2, b2);
    y = (double)call(a1, c1, a2, c2) / call(a1, b1, a2, b2);
    x = -x;
    y = -y;
    printf("%.2f %.2f\n", x, y);
    return 0;
}
int main(){
   solve();
   return 0;
}
