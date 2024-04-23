// create binary tree using pre order and INorder
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *left;
    int data;
    struct node *right;
}node;

node* createnode(char ch){
    node* temp=malloc(sizeof(node));
    temp->left=NULL;
    temp->data=ch;
    temp->right=NULL;
    return temp;
}

int searchInArr(char inArr[],char ch,int instart,int inend){
for(int i=instart;i<=inend;i++){
    if(inArr[i]==ch) {
        return i;
        }
}
return -1;
}

node* createTree(char inArr[],char preArr[],int instart,int inend){
    static int preindex=0;
    if(instart>inend){
        return NULL;
    }
    node *root=createnode(preArr[preindex]);
    preindex++;
    if(instart==inend){
        return root;
    }
    int searchindex=searchInArr(inArr,root->data,instart,inend);
    root->left=createTree(inArr,preArr,instart,searchindex-1);
    root->right=createTree(inArr,preArr,searchindex+1,inend);
    return root;
}

void preorder(node *root){
if(root==NULL){
    printf("empty treee");
    exit(1);
}
printf("%c ",root->data);
preorder(root->left);
preorder(root->right);
}


int main(){
char preArr[]={'A','B','D','E','C'};
char inArr[]={'D','B','E','A','C'};
int lenght=sizeof(inArr)/sizeof(inArr[0]);
node *root=createTree(inArr,preArr,0,lenght-1);
preorder(root);
}