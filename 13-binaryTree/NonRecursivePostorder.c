#include<stdio.h>
#include<stdlib.h>
#define MAX 10



typedef struct node{
    struct node *left;
    int data;
    struct node *right;
}node;

node *stack[MAX];
int top=-1;

void push(node *root){
if(top==MAX-1){
    printf("stack overflow");
    exit(1);
}
top++;
stack[top]=root;
}

node *pop(){
    node *root;
    if(top==-1){
        printf("stack underflow");
        exit(1);
    }
    root=stack[top];
    top=top-1;
    return root;
}

int isempty(){
    if(top==-1){
        return 1;
    }
    else return 0;
}


node * createTree(int data){
    node *newnode=malloc(sizeof(node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
   }

node *callFull(){
node *root=createTree(50);
root->left=createTree(60);
root->right=createTree(70);
root->left->left=createTree(79);
root->left->right=createTree(90);
root->right->left=createTree(123);
root->right->right=createTree(343);
root->left->right->left=createTree(566);
root->left->right->right=createTree(565);
return root;
}

void postorder(node *root){  // Postorder traversal using stack (without recursion)
    node *ptr=root;
    node *temp=root;
    while(1){
        while(ptr->left!=NULL){
            push(ptr);
            ptr=ptr->left;
        }
        while(ptr->right==NULL || ptr->right==temp){
            printf("%d ",ptr->data);
            temp=ptr;
            if(isempty())return;
            ptr=pop();
        }
        push(ptr);
        ptr=ptr->right;
    }
}


int main() {
node *root=callFull();
postorder(root);
return 0;
}