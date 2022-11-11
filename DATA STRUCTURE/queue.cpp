#include<bits/stdc++.h>
using namespace std;

int main(){

    queue<int >s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.pop();
    cout<<s.size()<<endl;
    cout<<s.front()<<endl;
    cout<<s.back()<<endl;
    return 0;

}
