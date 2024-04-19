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

root->right->right=createTree(343);
;
return root;
}


int count_node(node *root){
    int left,right;
    if(root==NULL){
        return 0;
    }
    else if(root->left==NULL && root->right==NULL){
        return 1;
    }
    else{
    left=count_node(root->left);
    right=count_node(root->right);
    return(1+left+right); //1 represent=root node;
    }
}

int checkCompletebin(node *root,int index,int count){
if(root==NULL){
    return 1;
}
if(index>=count){
    return 0;
}
int left=checkCompletebin(root->left,2*index+1,count);
int right=checkCompletebin(root->right,2*index+2,count);
return(left&&right);
}

int main() {
node *root=callComplete();
int count=count_node(root);
printf("%d ",count);
int index=0;
if(checkCompletebin(root,index,count)){
    printf("This is compelte binary tree");
}
else{
    printf("This is snot complete binary tree");
}
}