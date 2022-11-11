#include<bits/stdc++.h>
using namespace std;
int ar[10000];
int main(){
    int n,t;
    scanf("%d",&n);
    ar[0]=INT_MIN;
    for(int i=1;i<=n;i++){
        scanf("%d",&ar[i]);
    }
    for(int j=2;j<=n;j++){
        t=ar[j];
        int i=j-1;
        while(t<ar[i]){
            ar[i+1]=ar[i];
            i--;
        }
        ar[i+1]=t;
    }
    for(int i=1;i<=n;i++){
        printf("%d ",ar[i]);
    }
    return 0;
}
