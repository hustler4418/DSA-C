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

node* createTree(char inArr[],char postArr[],int instart,int inend,int *post){
    if(instart>inend){
        return NULL;
    }
    node *root=createnode(postArr[*post]);
    (*post)--;
    if(instart==inend){
        return root;
    }
    int searchindex=searchInArr(inArr,root->data,instart,inend);
    root->right=createTree(inArr,postArr,searchindex+1,inend,post);
    root->left=createTree(inArr,postArr,instart,searchindex-1,post);
    return root;
}

void postOrderTRaverse(node *root){
    if(root==NULL){
        return ;
    }
    postOrderTRaverse(root->left);
    postOrderTRaverse(root->right);
    printf("%c ",root->data);
}

node *helper(char inArr[],char postArr[],int instart,int inend){
    int postindex=inend-1;
    return createTree(inArr,postArr,instart,inend,&postindex);
}


int main(){
char postArr[]={'A','B','D','E','C'};
char inArr[]={'D','B','E','A','C'};
int lenght=sizeof(inArr)/sizeof(inArr[0]);
node *root=helper(inArr,postArr,0,lenght-1);
postOrderTRaverse(root);
}