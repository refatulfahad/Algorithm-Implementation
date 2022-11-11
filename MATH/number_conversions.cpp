#include<bits/stdc++.h>
using namespace std;
string s;
///convert decimal from base
int basetodecimal(int base) {
    int len=s.length();
    int res=0;
    for(int i=0; i<len; i++) {
        if(s[i]>='A'&&s[i]<='Z') {
            res=(res*base)+(s[i]-'A'+10);
        } else {
            res=(res*base)+(s[i]-'0');
        }
    }
    return res;
}
///convert base from decimal
char symbol[]= {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
string decimaltobase(int x,int base){
      string res="";
      while(x){
        int remain=x%base;
        res+=symbol[remain];
        x/=base;
      }
      if(res=="")res+='0';
      reverse(res.begin(),res.end());
      return res;
}
int main() {
    int base,x;
    cin>>s>>base;
    cout<<basetodecimal(base)<<endl;
    cin>>x>>base;
    cout<<decimaltobase(x,base);
    return 0;
}
