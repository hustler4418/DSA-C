#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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
node *root=createTree(67);
root->left=createTree(34);
root->right=createTree(80);
root->left->left=createTree(10);
root->left->right=createTree(55);
root->left->right->left=createTree(45);
root->left->right->right=createTree(60);
return root;
}


node *deleting(node *root,int dkey){
    node *ptr,*par;
    ptr=root;
    par=NULL;
    while(ptr!=NULL){
        if(ptr->data=dkey){
            break;
        }
        par=ptr;
        if(ptr->data<dkey){
            ptr=ptr->left;
        }
        else{
            ptr=ptr->right;
        }
    }
    root=case1(root,ptr,par);
}

node *case1(node *root,node *ptr,node *par){
    if(par==NULL){
        root=NULL;
    }
    else if(ptr=par->left){
        par->left=NULL;
    }
    else {
        par->right=NULL;
    }
    free(ptr);
    return root;
}


node *case2(node *root,node *ptr,node *par){
    node *child;
    if(ptr->left!=NULL){
        child=ptr->left;
    }
    else child=ptr->right;

    if(par==NULL){
        root=child;
    }
    else if(par->left==ptr){
        par->left=child;
    }
    else{
        par->right=child;
    }
    return root;
}
void preOrder(node *root){ //preorder traversal
if(root==NULL){
    return;

}
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}
int main() {
node *root=callComplete();
root=inserting(root,19);
preOrder(root);
}