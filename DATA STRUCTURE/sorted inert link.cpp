#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
};
node *head=NULL;
void insart(int n){
     node *temp=new node();
     temp->data=n;
     temp->next=head;
     head=temp;
}
void print(){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void sot(int n){
    node *temp=head,*tem,*temp1;
    tem=new node();
     tem->data=n;
     if(n<=temp->data){
        tem->next=head;
        head=tem;
     }
     else{
    while(temp->next!=NULL){
        if(temp->data>=n){
            break;
        }
        temp1=temp;
        temp=temp->next;
    }
    if(n<=temp->data)
    {tem->next=temp1->next;
    temp1->next=tem;}
    else{
       temp->next=tem;
    }

}}
int main(){
    int n;
    scanf("%d",&n);
    //insart(8);
    //insart(5);
    insart(4);
    print();
    sot(n);
    print();
    return 0;
}
