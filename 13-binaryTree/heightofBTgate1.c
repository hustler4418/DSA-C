#include<stdio.h>  // calculate height of binary tree in another process
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


int height(node *root){
    int h1,h2;
    if(root==NULL) return -1;

    if(root->left==NULL){        // no left child,toward right subtree
        if(root->right==NULL)   // if this leaf node
            return 0;
        else                      //if there is right child
          return 1+height(root->right); 
    }
    else{                      //if there is left child
       h1=height(root->left);
       if(root->right==NULL)   //no right child ,toward left subtree
         return(1+h1);
       else{            // if there is right chlid
         h2=height(root->right);
         if(h1>h2) return h1+1;
         else return h2+1;
    }
}
}


int main() {
node *root=callComplete();
printf("height of BINary tree is %d",height(root));
return 0;
}