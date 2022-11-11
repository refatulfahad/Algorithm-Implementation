#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *left,*right;
};
node *root=NULL;
void Insert(int key) {
    node *node_insert=new node();
    node_insert->data=key;
    node_insert->left=NULL;
    node_insert->right=NULL;
    if(root==NULL) {
        root=node_insert;
    } else {
        node *temp=root;
        while(1) {

            if(node_insert->data<=temp->data) {
                if(temp->left==NULL) {
                    temp->left=node_insert;
                    break;
                } else {
                    temp=temp->left;
                }
            } else {
                if(temp->right==NULL) {
                    temp->right=node_insert;
                    break;
                } else {
                    temp=temp->right;
                }
            }

        }
    }
}
void Search(int key) {
    node *temp=root;
    int x=0;
    while(1) {
        if(temp->data==key) {
            x=1;
            break;
        } else if(key<=temp->data) {
            temp=temp->left;
        } else if(key>temp->data) {
            temp=temp->right;
        }
        if(temp==NULL) {
            break;
        }
    }
    if(x==1) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

}
node *Min(node *root2) {
    node *current=root2;
    while(current->left!=NULL) {
        current=current->left;
    }
    return current;
}
void Delete(node *root1,int key) {
    node *temp;
    //cout<<temp3<<" "<<root1<<endl;
    while(1) {
        if(root1==NULL) {
            //return root1;
            return;
        } else if(key<root1->data) {
            //int  t=root1->left->data;
            cout<<"2";
            root1=root1->left;
        } else if(key>root1->data) {
            //temp=root1->right;
            cout<<"1";
            root1=root1->right;
        } else {
            if(root1->left==NULL) {
                node *temp1=root1->right;
                free(root1);
                cout<<"***"<<" ";
                temp->left=temp1;
                break;
            } else if(root1->right==NULL) {
                node *temp1=root1->left;
                cout<<"*"<<" ";
                free(root1);
                temp->right=temp1;
                break;
            }
            cout<<"**"<<" ";
            node *temp2=Min(root1->right);
            root1->data=temp2->data;
            Delete(root1->right,temp2->data);
        }
    }
}
int main() {
    Insert( 50);
    Insert( 30);
    Insert( 25);
    Insert( 40);
    Insert( 70);
    Insert( 60);
    Insert( 80);
    //Insert( 20);
    Insert( 27);
    //Insert( 26);


    Search(50);
    //Delete(root,50);
    Delete(root,25);
    //Delete(root,60);
    //Delete(root,100);
    //Search(80);
    Search(30);
    //Search(60);
    //Search(70);
    //Search(27);
    //Search(45);
    return 0;
}
*/

//Recursive solution
/*
#include<bits/stdc++.h>
using namespace std;

struct BstNod {
    BstNod *left,*right;
    int data;
};

BstNod *create_node(int val) {
    BstNod *node=new BstNod();
    node->data=val;
    node->left=node->right=NULL;

    return node;
}
BstNod *Insert(BstNod *root,int val) {
    if(root==NULL) {
        root=create_node(val);
    } else if(val<=root->data) {
        root->left=Insert(root->left,val);
    } else {
        root->right=Insert(root->right,val);
    }
    return root;
}

bool Search(BstNod *root,int val) {
    bool ck;
    if(root==NULL) {
        ck=false;
    } else if(root->data==val) {
        ck=true;
    } else if(val<=root->data) {
        ck=Search(root->left,val);
    } else {
        ck=Search(root->right,val);
    }
    return ck;
}

int findmin(BstNod *root){
    if(root==NULL){
        return -1;
    }
    if(root->left==NULL){
        return root->data;
    }
    return findmin(root->left);
}

int Findheight(BstNod *root,int height){
     if(root==NULL){
        return height;
     }
     int h1=Findheight(root->left,height+1);
     int h2=Findheight(root->right,height+1);
     return max(h1,h2);
}
int main() {

    BstNod *root=NULL;
    root=Insert(root, 10);
    //cout<<root->data;
    Insert(root, 30);
    //cout<<root->data;
    Insert(root, 25);
    Insert(root, 40);
    //cout<<root->data;
    Insert(root, 70);
    //cout<<root->data;
    Insert(root, 60);
    Insert(root, 90);
    Insert(root, 6);

    if(Search(root,100)) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }

    cout<<findmin(root)<<endl;
    cout<<Findheight(root,-1)<<endl;


    return 0;
}
*/

//Level order traversal
/*
#include<bits/stdc++.h>
using namespace std;

struct level {
    char data;
    level *left,*right;
};

void preorder(level *root) {
    if(root==NULL)return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(level *root) {
    if(root==NULL)return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(level *root) {
    if(root==NULL)return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
level *Insert(level *root,char val) {
    if(root==NULL) {
        root=new level();
        root->data=val;
        root->left=root->right=NULL;
    } else if(val<=root->data) {
        root->left=Insert(root->left,val);
    } else {
        root->right=Insert(root->right,val);
    }
    return root;
}
int main() {
    level *root=NULL;
    //root = Insert(root,'M');
    root=Insert(root,'F');
    Insert(root,'D');
    Insert(root,'B');
    Insert(root,'E');
    Insert(root,'A');
    Insert(root,'C');
    Insert(root,'J');
    Insert(root,'G');
    Insert(root,'K');
    Insert(root,'I');
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    return 0;
}

*/
///check binary tree is a binary search tree or not
/*
#include<bits/stdc++.h>
using namespace std;

struct level {
    int data;
    level *left,*right;
};

level *Insert(level *root,char val) {
    if(root==NULL) {
        root=new level();
        root->data=val;
        root->left=root->right=NULL;
    } else if(val<=root->data) {
        root->left=Insert(root->left,val);
    } else {
        root->right=Insert(root->right,val);
    }
    return root;
}

bool leftsubtreeLesser(level *root,int val) {
    if(root==NULL)return true;
    if(root->data<=val&&leftsubtreeLesser(root->left,val)&&leftsubtreeLesser(root->right,val)) {
        return true;
    } else {
        return false;
    }
}

bool rightsubtreeGreater(level *root,int val) {
    if(root==NULL)return true;
    if(root->data>val&&rightsubtreeGreater(root->left,val)&&rightsubtreeGreater(root->right,val)) {
        return true;
    } else {
        return false;
    }
}
bool rootchange(level *root) {
    if(root==NULL)return true;

    if(leftsubtreeLesser(root->left,root->data)&&rightsubtreeGreater(root->right,root->data)&&
            rootchange(root->left)&&rootchange(root->right)) {
        return true;
    } else {
        return false;
    }

}


bool rootchange1(level* root,int minbound,int maxbound) {
    if(root==NULL)return true;
    if(root->data<=maxbound&&root->data>=minbound&&rootchange1(root->left,minbound,root->data)
            &&rootchange1(root->right,(root->data)+1,maxbound)) {
        return true;
    } else {
        return false;
    }
}
///1.rootchange
///2.subtreecheck leftlesser or rightgreater
int main() {
    level *root=NULL;
    //root = Insert(root,'M');
    root=Insert(root,7);
    Insert(root,4);
    Insert(root,9);
    Insert(root,1);
    Insert(root,6);
    //cout<<root->data<<endl;
    Insert(root,7);
    //cout<<root->data<<endl;
//    leftmax=;
//    rightmin=minval(root->right);
///one solution
    if(rootchange(root)) {
        cout<<"Binary Search Tree";
    } else {
        cout<<"Not Binary Search Tree";
    }
    cout<<endl;
///another solution(efficient)
    if(rootchange1(root,INT_MIN,INT_MAX)) {
        cout<<"Binary Search Tree";
    } else {
        cout<<"Not Binary Search Tree";
    }
    return 0;
}

*/

///Delete a node from BST




