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
    
    else {
    // Find the insertion point
    while (temp->link != NULL && temp->link->priority <= priority) {
        // If next node has the same priority but greater data, stop here.
        if (temp->link->priority == priority && temp->link->data > data) {
            break;
        }
        temp = temp->link;
    }
    // Insert the new node
    newnode->link = temp->link;
    temp->link = newnode;
}
}


int dequeue(){
    node *temp=front;
    if(isempty()){
        printf("queue underflow");
    }
    int val=temp->data;
    front=front->link;
    free(temp);
    temp=NULL;
    return val;
}

void sequence(){
    node *temp=front;
    if(isempty()){
    printf("quque under fllow");
    exit(1);
}
while(temp!=NULL){
    printf("%d ",temp->priority);
    temp=temp->link;
}
}

void print(){
    node *temp=front;
    if(isempty()){
    printf("quque under fllow");
    exit(1);
}
while(temp!=NULL){
    printf("%d ",temp->data);
    temp=temp->link;
}
}

int main(){
    int choice,data,priority;
    
    while(true){
        printf("enter choice \n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:printf("enter value to be inserted and priority");
           scanf("%d %d",&data,&priority);
           enqueue(data,priority);
           break;
    case 2:data=dequeue();
           printf("deleted value is %d ",data);
           break;
    
    case 3:print();
           break;
    case 4:sequence();
            break;
    default :printf("wrong choice");
    }
    }
}