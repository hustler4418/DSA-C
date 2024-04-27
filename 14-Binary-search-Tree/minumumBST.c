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

node *minimumVAL(node *root){ //non recursive apprach
   if(root!=NULL){
    while(root->left!=NULL){
        root=root->left;
    }
   }
   return root;
}

node *minimumRecursive(node *root){
    if(root==NULL) return NULL;
    else if(root->left==NULL)return root;
    else return minimumRecursive(root->left);
}

int main() {
node *root=callComplete();
node *ptr=minimumVAL(root);
if(ptr==NULL){
    printf("no element found");
}
else{
    printf("element is found  %d ",ptr->data);
}
return 0;
}