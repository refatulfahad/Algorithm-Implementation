#include<bits/stdc++.h>
using namespace std;
int area(int a, int b, int c, int d) {
    return (c - a) * (d - b);
}

int solve() {
    int a1, b1, c1, d1, a2, b2, c2, d2;
    scanf("%d %d %d %d", &a1, &b1, &c1, &d1);
    scanf("%d %d %d %d", &a2, &b2, &c2, &d2);
    printf("%d\n", area(max(a1, a2), max(b1, b2), min(c1, c2), min(d1, d2)));
    return 0;
}
int main(){
   solve();///1st rectangle bottom left (a1,b1),top right(c1,d1)
           ///2nd rectangle bottom left (a2,b2),top right(c2,d2)
   return 0;
}
