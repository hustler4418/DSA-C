#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int data;
    struct node *link;
}node;

node *top=NULL;

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

int main() {
int choice,data;

while(true){
printf("Enter 1 for push \n");
printf("Enter 2 for pop \n");
printf("Enter 3 for print\n");
printf("Enter 4 for quit\n");
printf("Enter choice\n");
scanf("%d",&choice);

switch(choice){
    case 1:printf("enter data to push");
           scanf("%d",&data);
           push(data);
           break;
    case 2 :printf("work in progress");
            break;
    case 3:print();
           break;
    case 4:exit(1);
           break;
   default :
       printf("wrong choice");
}
}

return 0;
}