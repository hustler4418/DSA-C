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

void callFull(){
node *root=createTree(50);
root->left=createTree(60);
root->right=createTree(70);
root->left->left=createTree(79);
root->left->right=createTree(90);
root->right->left=createTree(123);
root->right->right=createTree(343);
root->left->right->left=createTree(566);
root->left->right->right=createTree(566);
}

int main() {
callFull();

return 0;
}