#include<bits/stdc++.h>
using namespace std;
int ar[10000],mx,mx2;
int second_largest(int n,int x,int x2){
    mx=x,mx2=x2;
      if(n==1){
        mx=ar[n],mx2=-100000;
        return mx2;
      }
       second_largest(n-1,mx,mx2);
      if(ar[n]>mx){mx2=mx;mx=ar[n];}
      else if(ar[n]>mx2&&ar[n]<mx){mx2=ar[n];}
      return mx2;

}
int main(){
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d",&ar[i]);
  }
   cout<<second_largest(n,0,0);
   return 0;
}
