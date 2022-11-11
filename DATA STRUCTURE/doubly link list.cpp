#include<bits/stdc++.h>
using namespace std;
struct node{
     int data;
     node *next=NULL;
     node *pre=NULL;
};
node *head=NULL;
node *tail=NULL;
void createnode(int x){
      node *temp=new node();
      temp->data=x;
      temp->next=NULL;
      if(head==NULL){
        head=temp;
        tail=temp;
        return;
    }
    temp->next=head;
    head->pre=temp;
    head=temp;
   }
   void print(){
       {node *temp1=tail;
       while(temp1!=NULL){
        cout<<temp1->data<<" ";
        temp1=temp1->pre;}
       }
       cout<<endl;
       {node *temp1=head;
       while(temp1!=NULL){
        cout<<temp1->data<<" ";
        temp1=temp1->next;}}
   }
int main(){
   int n,x;
   scanf("%d",&n);

   for(int i=0;i<n;i++){
    scanf("%d",&x);
    createnode(x);

   }
   print();
   return 0;
}
