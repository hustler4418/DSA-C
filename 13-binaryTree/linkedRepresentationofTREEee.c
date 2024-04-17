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
int main() {
node *root=createTree();
printf("%d ",root->data);
printf(" %d",root->left->data);
printf(" %d",root->right->data);

return 0;
}