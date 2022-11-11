#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll x1, y1;
int inv[100005];
///No condition
int modInverse(int a, int mod) {
    a = a % mod;
    for (int B = 1; B < mod; B++)
        if (((a * B) % mod) == 1)
            return B;
}
///effective modInverse solution using bigmod:condition gcd(a,mod)=1 && MOD value is prime
/*
(a%M)/(b%M)=(a*big_modInverse(b,M-2,M))%M
*/
ll big_modInverse(ll a, ll md, ll mod) {
    if (md == 0)return 1 % mod;
    ll  x = big_modInverse(a, md / 2ll, mod);
    x = (x * x) % mod;
    if (md % 2ll == 1)x = (x * (a % mod)) % mod;
    return x;
}
///no condition && efficient time complexity:log(mod)(part-1)
ll ext_euclid_gcd(ll a, ll b, ll x, ll y) {

    if (a == 0) {
        x1 = 0; ///global variable
        y1 = 1; ///global variable
        return b;
    }
    ll d = ext_euclid_gcd(b % a, a, x, y);
    x = x1, y = y1;
    x1 = y - ((b / a) * x);
    y1 = x;
    return y1;
}
///part-2
ll modInverse(ll a, ll mod) {
    ll inverse = ext_euclid_gcd(mod, a, 0, 0);
    if (inverse < 0)inverse += mod;
    return inverse;
}

void M_inverse(int n, int M) {
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = (-1 * (M / i) * inv[M % i]) % M;
        inv[i] += M;
    }
}
int main() {
    int a, mod;
    scanf("%d %d", &a, &mod);
    cout << modInverse(a, mod) << endl;
    cout << big_modInverse(a, mod - 2, mod);


    ///find moduler inverse 1 to N O(N) solution
    ///note:n<M && M is prime
    scanf("%d %d", &n, &mod);
    M_inverse(n, mod);
    ///print modulo inverse
    for (int i = 1; i <= n; i++) {
        cout << inv[i] << " ";
    }
    return 0;
}
