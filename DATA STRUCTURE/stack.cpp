#include <bits/stdc++.h>
using namespace std;
stack <int>s;
void show(){
    /**stack<int>s1;int j;
    while(!s.empty()){
    j=s.top();
    s.pop();
    s1.push(j);}**/
    //cout<<
   while(!s.empty()){
    cout<<s.top()<<endl;
    s.pop();
   }
}
int main(){

    s.push(2);
    s.push(3);
    s.push(4);
    show();
   //cout<<s.size()<<endl;
   // s.pop();
    //cout<<s.top()<<endl;
    //s.pop();
    //s.pop();
    //cout<<s.empty();
}
/*********reverse print*********/
/**#include <bits/stdc++.h>
using namespace std;
void Reverse(char *c,int n){
    stack<char>s;
     for(int i=0;i<n;i++){
        s.push(c[i]);
     }
     for(int i=0;i<n;i++){
        c[i]=s.top();
        s.pop();
     }
}
int main(){
    char s[100];
    gets(s);
    ///int l=strlen(s);
    Reverse(s,strlen(s));
    printf("%s",s);
    return 0;
}
/**struct node{
    int data;
    node *next;
};
node *head=NULL;
int push(int n){
    node *temp=new node();
    temp->data=n;
    temp->next=head;
    head=temp;
}
int pop(){
   node *temp1=head,*temp2;
   if(head==NULL){return 0;}
   else{
        temp2=head;
        head=temp2->next;
        delete(temp2);
    }
   }
void print(){
    node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}
int main(){
    push(1);
    print();
    push(2);
    print();
    push(3);
    print();
    pop();
    print();
    pop();
    print();
    push(4);
    print();
    return 0;
}**/
