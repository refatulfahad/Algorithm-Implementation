#include<bits/stdc++.h>
using namespace std;
int ar[10000];
int first_largest(int n){
     if(n==1){
        return ar[n];
     }
     return max(ar[n],first_largest(n-1));
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&ar[i]);
    }
    cout<<first_largest(n);
    return 0;
}
