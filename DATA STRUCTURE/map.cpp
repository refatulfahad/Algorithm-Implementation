#include<bits/stdc++.h>
using namespace std;
map<string,int>m;
map<string,int>::iterator it;
int main(){
m["refat"]=34;
m["apple"]=56;
m["nana"]=67;
m["abbu"]=4;
m["mama"]=78;
for(it=m.begin();it!=m.end();it++)
cout<<it->first<<"  "<<it->second<<endl;
return 0;
}
