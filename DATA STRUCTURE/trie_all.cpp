#include<bits/stdc++.h>
using namespace std;
struct node {
    int cnt;
    bool endmark;
    node *next[30];
    node() {
        endmark=false;
        cnt=0;
        for(int i=0; i<=26; i++) {
            next[i]=NULL;
        }
    }
};
node *root=new node();
void Insert(string s) {
    node *temp=root;
    for(int i=0; i<s.length(); i++) {
        int id=s[i]-'a';
        if(temp->next[id]==NULL) {
            temp->next[id]=new node();
        }
        temp=temp->next[id];
        temp->cnt++;
    }
    temp->endmark=true;
}
bool Search(string s) {
    node *temp=root;
    for(int i=0; i<s.length(); i++) {
        int id=s[i]-'a';
        if(temp->next[id]==NULL) {
            return false;
        }
        temp=temp->next[id];
    }
    return temp->endmark;
}
void del(node *temp) {
    for(int i=0; i<=25; i++) {
        if(temp->next[i]!=NULL)
            del(temp->next[i]);
    }
    delete(temp);
}
int cont(string s) {
    node *temp=root;
    for(int i=0; s[i]; i++) {
        int id=s[i]-'a';
        if(!temp->next[id]) {
            return 0;
        }
        temp=temp->next[id];
    }
    return temp->cnt;
}
int main() {
    int n;
    string s,s1;
    ///insert
    scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        cin>>s;
        Insert(s);
    }
    ///search
    int query;
    scanf("%d",&query);
    for(int i=1; i<=query; i++) {
        cin>>s1;
        bool ck=Search(s1);
        if(ck) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    ///number of a word as a prefix
    cin>>s1;
    int ck=cont(s1);
    if(ck==0) {
        printf("NO\n");
    } else {
        printf("%d\n",ck);
    }
    ///delete
    del(root);
    return 0;
}
