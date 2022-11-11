#include<bits/stdc++.h>
using namespace std;

///Author:Refat(BSMRSTU)///

#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define pb push_back
#define vi vector<int>
#define pii pair<int,int>
#define pil pair<int,ll>
const int N = 1e5 + 5;
const ll M = 719;
int Set(int N,int pos) {
    return N=N | (1<<pos);
}
int reset(int N,int pos) {
    return N= N & ~(1<<pos);
}
bool check(int N,int pos) {
    return (bool)(N & (1<<pos));
}
///First highly composite number :1, 2, 4, 6, 12, 24, 36, 48, 60, 120, 180, 240, 360, 720
int resnum=0;///highly composite number
int resdiv=0;///number of divisor
int prime[]= {2,3,5,7,11,13,17,19,23,29,31};
void recursion(int position,int limit,ll number,int NOD) {
    if(NOD>resdiv) {
        resdiv=NOD;
        resnum=number;
    } else if(NOD==resdiv&&number<resnum) {
        resnum=number;
    }
    if(position==5)return;
    ll prime_value=prime[position];
    for(int i=1; i<=limit; i++) {
        if(prime_value*number>M)return;
        recursion(position+1,i,prime_value*number,NOD*(i+1));
        number*=prime[position];
    }
}
int main() {
    /// freopen("input.txt","r",stdin);
    /// freopen("output.txt","w",stdout);

    recursion(0,30,1,1);
    printf("%d %d",resnum,resdiv);
    return 0;
}

