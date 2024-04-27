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

node *search(node *root,int skey){         // recursive approach
if(root==NULL){
    return NULL;
}
else if(skey<root->left){
    root=search(root->left,skey);
}
else if(skey>root->right){
    root=search(root->right ,skey);
}
else return root;
}


int main() {
node *root=callComplete();
if(search(root,15)==NULL){
    printf("no element found");
}
else{
    printf("element is found");
}
return 0;
}