#include<bits/stdc++.h>
using namespace std;
struct node {
    node *pre;
    node *post;
    int data;
};
node *root=NULL;
void value(int n) {
    node *temp=new node();
    temp->data=n;
    if(root==NULL) {
        root=temp;
    } else {
        node *temp1=root;
        while(1) {
            if(temp->data<=temp1->data) {
                if(temp1->pre==NULL) {
                    temp1->pre=temp;
                    break;
                } else {
                    temp1=temp1->pre;
                }
            } else {
                if(temp1->post==NULL) {
                    temp1->post=temp;
                    break;
                } else {
                    temp1=temp1->post;
                }
            }
        }
    }
}
void serch(int n) {
    node *temp=root;
    int x=1;
    while(1) {
        if(temp->data==n) {
            break;
        } else if(n<=temp->data) {
            temp=temp->pre;
        } else if(n>temp->data) {
            temp=temp->post;
        }
        if(temp==NULL) {
            x=0;
            break;
        }
    }
    if(x==0)
        cout<<"no"<<endl;
    else
        cout<<"yes"<<endl;
}
int main() {
    int n;
    scanf("%d",&n);
    value(55);
    value(40);
    value(80);
    value(34);
    serch(n);
    return 0;
}
