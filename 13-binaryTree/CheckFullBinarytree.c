#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *left;
    int data;
    struct node *right;
}node;


node * createTree(){
   int input,data;
   printf("Do you want to create node then press 1 or 0");
   scanf("%d",&input);
   if(!input){
    return NULL;
   }
   else{
    node *newnode=malloc(sizeof(node));
    printf("Enter data");
    scanf("%d",&data);
    newnode->data=data;
    printf("left child of %d",newnode->data);
    newnode->left=createTree();
    printf("right child of %d",newnode->data);
    newnode->right=createTree();
    return newnode;
   }
}

int isfullbinarytree(node *root){

    if(root==NULL){
        return 1;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    else if(root->left && root->right){
     int left=isfullbinarytree(root->left);
     int right=isfullbinarytree(root->right);
     return (left&&right);
    }
    return 0;
}


int main() {
node *root=NULL;
root=createTree();
if(isfullbinarytree(root)){
    printf("This is full binary tree");
}
else{
    printf("this is not full binary tree");
}

return 0;
}