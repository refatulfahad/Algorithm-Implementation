#include<bits/stdc++.h>
using namespace std;
void print();
struct node
{
    int data;
    node *next;
    node *pre;
};
node *head=NULL;
node *tail=NULL;
int main()
{
    int n,k,num,t;
    scanf("%d",&t);
    while(t--){
    scanf("%d %d",&n,&k);
    num=0;
    int x;
    scanf("%d",&x);
    node *temp;
    temp=new node();
    temp->data=x;
    temp->next=NULL;
    head=temp;
    tail=temp;
    node *temp1=head;
    for(int i=0; i<n-1; i++)
    {
        scanf("%d",&x);
        node *temp=new node();
        temp->data=x;
        temp->next=NULL;
        tail=temp;
        temp1=head;
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        temp1->next=temp;
        temp->pre=temp1;

    }
    if(k==0)
        print();
    else
    {
        while(num<=k)
        {
            if(num==k)
            {
                break;
            }
            node *temp1=head,*temp2;
            temp2=temp1->next;
            if(temp1->data<temp2->data)
            {
                head=temp1->next;
                num++;
            }
            else
            {temp1=temp1->next;
                    temp2=temp2->next;
                while(num<=k&&temp1->next!=NULL)
                {
                    node *temp3=NULL;
                    if(temp1->data<temp2->data)
                    {
                        temp3=temp1->pre;
                        temp3->next=temp1->next;
                        temp2->pre=temp3;
                        num++;
                        delete(temp1);
                        break;
                    }
                    temp1=temp2;
                        temp2=temp2->next;

                }
                if(num==k)
                    {break;}
            }
        }
        print();
    }}
    return 0;
}
void print()
{
    node *temp2=head;
    while(temp2!=NULL)
    {
        cout<<temp2->data<<" ";
        temp2=temp2->next;
    }
    cout<<endl;
    head=NULL;
     tail=NULL;
}
