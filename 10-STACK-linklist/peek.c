#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int data;
    struct node *link;
}node;


node *top=NULL;

int isEmpty(){
    if(top==NULL){
        return 1;
    }
    else
       return 0;
}

void push(int data){
    node *newnode;
    newnode=malloc(sizeof(node));
    if(newnode==NULL){
        printf("stack overflow");
        exit(1);
    }
    newnode->data=data;
    newnode->link=NULL;
    newnode->link=top;
    top=newnode;
}

void print(){
    node *temp=top;

    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}

int peek(){
    if(isEmpty()){
        printf("stack underflow");
    }
    return top->data;
}


int pop(){
    int value;
    node *temp=top;
    if(top==NULL){
        printf("stack underflow");
        exit(1);
    }
    top=top->link;
    value=temp->data;
    free(temp);
    temp=NULL;
    return value;

}
int main() {
int choice,data,val;

while(true){
printf("Enter 1 for push \n");
printf("Enter 2 for pop \n");
printf("Enter 3 for print\n");
printf("Enter 4for peek\n");
printf("Enter 5for quit\n");
printf("Enter choice\n");
scanf("%d",&choice);

switch(choice){
    case 1:printf("enter data to push");
           scanf("%d",&data);
           push(data);
           break;
    case 2 :val=pop();
            printf("popped value is  :%d \n",val);
            break;
    case 3:print();
           break;
    case 4:
          printf("peek value is :%d \n",peek());
          break;
    case 5:exit(1);
           break;
   default :
       printf("wrong choice");
}
}

return 0;
}