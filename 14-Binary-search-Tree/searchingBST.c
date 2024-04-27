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

node *search(node *root,int skey){         // non recursive approach
    while(root!=NULL){
        if(skey<root->data){
            root=root->left;
        }
        else if(skey>root->data){
            root=root->right;
        }
        else{
            return root;
        }
    }
    return NULL;
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