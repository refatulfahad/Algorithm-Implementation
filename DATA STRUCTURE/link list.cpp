#include<bits/stdc++.h>
using namespace std;
/*struct node
{
    int data;
    node *next;
};
node *head=NULL;
void print()
{
    node *temp2;
    temp2=head;
    while(temp2!=NULL)
    {
        cout<<temp2->data<<" ";
        temp2=temp2->next;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int x;
    scanf("%d",&x);
    node *temp=new node();
    temp->data=x;
    temp->next=NULL;
    head=temp;
    for(int i=0; i<n-1; i++)
    {
        scanf("%d",&x);
        node *temp=new node();
        temp->data=x;
        temp->next=NULL;
        node *temp1=head;
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        temp1->next=temp;
    }
    print();
    {
        int d;
        scanf("%d",&d);
        node *temp,*temp1,*temp2;
        temp1=new node();
        temp1->data=d;
        temp1->next=NULL;
        temp=head;
        if(temp->data>temp1->data)
        {
            temp1->next=temp;
            head=temp1;
        }
        else
        {
            temp2=temp->next;
            while(temp1->data>temp2->data)
            {
                temp=temp->next;
                temp2=temp2->next;
            }
            temp1->next=temp->next;
            temp->next=temp1;
        }
        print();
    }
    return 0;
}
/*****************insertion******************/

/*struct node {
    int data;
    node *next;
};
node *head=NULL;
void print() {
    node *temp2;
    temp2=head;
    while(temp2!=NULL) {
        cout<<temp2->data<<" ";
        temp2=temp2->next;
    }
}
int main() {
    int n;
    scanf("%d",&n);
    int x;
    scanf("%d",&x);
    node *temp=new node();
    temp->data=x;
    temp->next=NULL;
    head=temp;
    for(int i=0; i<n-1; i++) {
        scanf("%d",&x);
        node *temp=new node();
        temp->data=x;
        temp->next=NULL;
        node *temp1=head;
        while(temp1->next!=NULL) {
            temp1=temp1->next;
        }
        temp1->next=temp;
    }
    print();
    {
        int d,x;
        scanf("%d",&d);
        node *temp1;
        node *temp2=head;
        if(d==1) {
            scanf("%d",&x);
            temp1=new node();
            temp1->data=x;
            temp1->next=NULL;
            temp1->next=temp2;
            head=temp1;
        } else {
            for(int i=1; i<=d-2; i++) {
                temp2=temp2->next;
            }
            scanf("%d",&x);
            temp1=new node();
            temp1->data=x;
            temp1->next=NULL;
            temp1->next=temp2->next;
            temp2->next=temp1;
        }
        print();
    }
    return 0;
}****************/
///**********************node delete*************************///
struct node {
    int data;
    node *next;
};
node *head=NULL;
void print() {
    node *temp2;
    temp2=head;
    while(temp2!=NULL) {
        cout<<temp2->data<<" ";
        temp2=temp2->next;
    }
}
int main() {
    int n;
    scanf("%d",&n);
    int x;
    scanf("%d",&x);
    node *temp=new node();
    temp->data=x;
    temp->next=NULL;
    head=temp;
    for(int i=0; i<n-1; i++) {
        scanf("%d",&x);
        node *temp=new node();
        temp->data=x;
        temp->next=NULL;
        node *temp1=head;
        while(temp1->next!=NULL) {
            temp1=temp1->next;
        }
        temp1->next=temp;
    }
    print();
    int d;
    scanf("%d",&d);
    node *temp3;
    if(d==1) {
        temp3=head;
        head=temp3->next;
        delete(temp3);
        print();
    } else {
        node *temp3=head;
        for(int i=1; i<=d-2; i++) {
            temp3=temp3->next;
        }
        node *temp4;
        temp4=temp3->next;
        temp3->next=temp4->next;
        delete(temp4);
        print();
    }

    return 0;
}/**/
///*******************serial print************************///
/**#include<bits/stdc++.h>
using namespace std;
void print();
    struct node{
       int data;
       node *next;
    };
    node *head=NULL;
    int main(){
       int n;
       scanf("%d",&n);
       int x;
       scanf("%d",&x);
       node *temp;
       temp=new node();
       temp->data=x;
       temp->next=NULL;

       head=temp;

        node *temp1=head;
       for(int i=0;i<n-1;i++)
        {scanf("%d",&x);
        node *temp=new node();
        temp->data=x;
        temp->next=NULL;
        temp1=head;
       while(temp1->next!=NULL)
       {
           temp1=temp1->next;
       }
       temp1->next=temp;
       }
       print();
       return 0;
    }
void print(){
      node *temp2=head;
      while(temp2!=NULL){
        cout<<temp2->data<<" ";

        temp2=temp2->next;
      }
      cout<<endl;
}**/
///*****************************reverse print********************///
/**#include<bits/stdc++.h>
using namespace std;
void print();
struct node
{
    int data;
    node *next;
};
node *head=NULL;
void createnode(int x){
   node *temp=new node();
   temp->data=x;
   temp->next=head;
   head=temp;
}
int main()
{
    int n;
    scanf("%d",&n);
    int x;for(int i=0;i<n;i++){
    scanf("%d",&x);
    createnode(x);
    }
    print();
    return 0;
}
void print()
{
    node *temp2=head;
    while(temp2!=0)
    {
        cout<<temp2->data<<endl;
        temp2=temp2->next;
    }
}**/

/*
Symmetric Tree
bool check(TreeNode* left_node,TreeNode* right_node){
        if(left_node==NULL&&right_node==NULL){
            return true;
        }
        if((left_node!=NULL&&right_node==NULL)||((left_node==NULL&&right_node!=NULL)))
            return false;
        if(left_node->val!=right_node->val)return false;
        return check(left_node->left,right_node->right)&&check(left_node->right,right_node->left);
    }
    bool isSymmetric(TreeNode* root) {
       if(root==NULL){
           return true;
       }
       return check(root->left,root->right);
    }

*/
