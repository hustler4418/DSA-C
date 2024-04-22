#include<stdio.h>
#include<stdlib.h>
#define MAX 50
typedef struct node{
    struct node *left;
    int data;
    struct node *right;
}node;

node *queue[MAX];
int front=-1,rear=-1;

int isempty(){
    if(front==-1 || front==rear+1){
        return 1;
    }
    else return 0;
}
void enqueue(node *root){
    if(rear==MAX-1){
      printf("queue overflow");
      exit(1);
    }
    if(front==-1){
        front++;
    }
    rear++;
    queue[rear]=root;
}

node *dequeue(){
        if(isempty()) {
        printf("queue underflow");
        }
        node *root=queue[front];
        front++;
        return root;

}

void levelorder(node *root){
    node *ptr=root;
    if(root==NULL){
        printf("empty treee");
        exit(1);
    }
    enqueue(ptr);
    while(!isempty()){
     ptr=dequeue();
    printf("%d ",ptr->data);
    if(ptr->left!=NULL){
        enqueue(ptr->left);
    }
    if(ptr->right!=NULL){
        enqueue(ptr->right);
    }
}
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
root->left->right->right=createTree(566);
return root;
}

int main() {
node *root=callFull();
levelorder(root);

return 0;
}