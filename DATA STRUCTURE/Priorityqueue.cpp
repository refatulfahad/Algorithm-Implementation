#include<bits/stdc++.h>
using namespace std;
//***********decending order***************
priority_queue<int>q;
void display(){
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
}
int main(){
  q.push(6);
  q.push(1);
  q.push(8);
  q.push(3);
  q.push(2);
  display();
}
/*******************
priority_queue<int>q;
struct match{
   bool operator()(const int &l,const int &r){
    return l<r;
   }
};

int main(){
   priority_queue<int,vector<int>,match>q;
  q.push(6);
  q.push(1);
  q.push(8);
  q.push(3);
  q.push(2);
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
       }
}****/
