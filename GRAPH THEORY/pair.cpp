#include<bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<string,int>&a,const pair<string,int>&b){
    return a.second<b.second;
}
int main(){
 vector < pair<string,int> >p;
p.push_back(make_pair("refat",7));
p.push_back(make_pair("apple",6));
p.push_back(make_pair("banana",5));
sort(p.begin(),p.end(),sortbysec);
for(int i=0;i<p.size();i++)
    cout<<p[i].first<<" "<<p[i].second<<endl ;
return 0;
}
