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
node *root=createTree(50);
root->left=createTree(60);
root->right=createTree(70);
root->right->left=createTree(79);
root->right->left->right=createTree(123);
return root;
}


int abs(int val){
    if(val<0){
    return val*(-1);
    }
    else return val;
}
int height(node *root){
    if(root==NULL){
        return -1;
    }
    if(root->left==NULL && root->right==NULL){ // if its leaf node
      return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    if(left>right){
        return left+1;
    }
    else{
        return right+1;
    }
}

int isbalance(node *root){
    int l=0,r=0,lh=0,rh=0;
    int diff=0;
    if(root==NULL){
        return 1;
    }
    l=isbalance(root->left);
    r=isbalance(root->right);
    if(l && r){
    lh=height(root->left);
    rh=height(root->right);
    diff=abs((lh+1)-(rh+1));
    if(diff<=1){
        return 1;
    }
    return 0;
    }
}
int main() {
node *root=callComplete();
if(isbalance(root)){
    printf("this is balacne binary tree");
}
else{
    printf("this is not balanced binary tree");
}
return 0;
}