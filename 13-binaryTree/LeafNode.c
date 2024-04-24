// calculatel leafnode

#include<stdio.h>  
#include<stdlib.h>

typedef struct node{
    struct node *left;
    int data;
    struct node *right;
}node;


node * createTree(int data){
    node *newnode=malloc(sizeof(node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
   }

node *callComplete(){
node *root=createTree(50);
root->left=createTree(60);
root->right=createTree(70);
root->left->left=createTree(79);
root->left->right=createTree(90);
root->right->left=createTree(123);
root->right->right=createTree(343);
return root;
}


int leafnode(node *root){
    int value=0;
    if(root!=NULL){
        if(root->left==NULL && root->right==NULL) return 1;
        else {
            value=value+leafnode(root->left)+leafnode(root->right);
        }
        return value;
    }
}

int main() {
node *root=callComplete();
printf("NO. of leaf node in Binary tree is :%d",leafnode(root));
return 0;
}