#include<bits/stdc++.h>
using namespace std;

  deque<int>d;
  deque<int >::iterator it;
  pushfront(int a){
    d.push_front(a);
   }
   pushback(int a){
      d.push_back(a);
   }
   popfront( ){
     d.pop_front();
   }
   popback(){
     d.pop_back();
   }
   display(){
      for(it=d.begin();it!=d.end();it++){
        cout<<*it<<" s";
      }
   }

int main(){
    pushfront(3);
    pushfront(5);
    pushfront(7);
    pushback(8);
    pushback(9);
    popback();
    display();
}
