#include<bits/stdc++.h>
using namespace std;

struct abc
{
    string name;
    int roll;

};
int main()
{
    set<int>cs;

    cs.insert(4);
    cs.insert(2);
    cs.insert(3);
    cs.insert(4);
    cs.insert(1);
    //cs.erase(4);
    if(cs.find(5)==cs.end()){
        cout<<"not";
    }
   else{
    cout<<"YES";
   }

    /** cout<<endl;
    for(it1=cs.rbegin(); it1!=cs.rend(); it1++)
    {
        cout<<*it1<<" ";
    }**/
    return 0;
}
