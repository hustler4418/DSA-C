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

node *inserting(node *root,int ikey){
    node *ptr,*par,*temp;
    ptr=root;
    par=NULL;
    while(ptr!=NULL){
        par=ptr;
     if(ikey<ptr->data){
        ptr=ptr->left;
     }
     else if(ikey>ptr->data){
        ptr=ptr->right;
     }
     else{
        printf("duplicate value ");
        return root;
     }
    }
    temp=createTree(ikey);
    if(par==NULL){
      root=temp;
    }
    else if(ikey<par->data){
        par->left=temp;
    }
    else{
        par->right=temp;
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