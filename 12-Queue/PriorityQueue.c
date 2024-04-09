#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node {
    int priority;
    int data;
    struct node *link;
}node;
node *front=NULL;

int isempty(){
    if(front==NULL){
        return 1;
    }
    else 
       return 0;
}


void enqueue(int data,int priority){
    node *newnode=malloc(sizeof(node));
    newnode->data=data;
    newnode->priority=priority;
    newnode->link=NULL;
    node *temp=front;
    if(isempty() ||priority<front->priority){
        newnode->link=front;
        front=newnode;
    }
    else{
          while(temp->link !=NULL &&temp->link->priority<=priority){
            temp=temp->link;
          }
          newnode->link=temp->link;
          temp->link=newnode;
    }
}

int main(){
    int choice,data;
    
    while(true){
        printf("enter choice \n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:printf("enter value to be inserted");
           scanf("%d",&data);
           enqueue(data,priority);
           break;
    case 2:data=dequeue();
           printf("deleted value is %d ",data);
           break;
    
    case 3:print();
           break;
    default :printf("wrong choice");
    }
    }
}