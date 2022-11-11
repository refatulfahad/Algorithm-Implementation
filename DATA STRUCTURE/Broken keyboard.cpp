#include<bits/stdc++.h>
using namespace std;
struct NODE{
    char ch;
    NODE* next;
};
NODE* head=NULL;
NODE* tail=NULL;
NODE* current=NULL;
void inEnd(char c){
    NODE* node = new NODE();
    node->ch=c ;
    node->next=NULL ;
    if(head==NULL){
        head=node;
        tail=node;
    }
    else{
        tail->next=node;
        tail=node;

    }
}
void inHead(char c){
    NODE* node = new NODE();
    node->ch=c ;
    if(head==NULL){
        node->next=NULL ;
        head=node;
        tail=node;
        current=node;
    }
    else{
        node->next=head;
        head=node;
        current=node;
    }

}
void inCurrent(char c){
    NODE* node = new NODE();
    node->ch=c ;
    node->next=current->next;
    current->next=node;
    current= node;
}
void printRifatPrint(){
    NODE* temp=head;
    while(temp!=NULL)
    {
        printf("%c",temp->ch);
        temp=temp->next;
    }
    printf("\n");
}
void dlt(){
    /*NODE* tmp=head;
    NODE* dl;
    while(tmp!=NULL){
        dl=tmp;
        tmp=tmp->next;
        delete(dl);
    }
    delete(tmp);
    */
    head=NULL;
    tail=NULL;
    current=NULL;
}
int main()
{
    char s[100005];
    while(scanf(" %[^\n]",s)!=EOF){
        int len=strlen(s);
        int f=0;
        for(int i=0; i<len; i++){
            if(s[i]==']'){
                f=0;
                continue;
            }
            else if(s[i]=='['){
                f=1;
                continue;
            }
            if(f==0){
                inEnd(s[i]);
            }
            else if(f==1){
                inHead(s[i]);
                f=2;
            }
            else if(f==2){
                inCurrent(s[i]);
            }
        }
        printRifatPrint();
        dlt();
    }
    return 0;
}
