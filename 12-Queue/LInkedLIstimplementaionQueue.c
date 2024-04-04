#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct node{
    int data;
    struct node *link;
}node;

node *rear=NULL,*front=NULL;

void enqueue(int data){
 node *temp=malloc(sizeof(node));
 if(temp==NULL){
    printf("no space");
 }
 temp->data=data;
 temp->link=NULL;
 if(rear==NULL){
    rear=front=temp;
 }
 else{
    rear=rear->link;
    rear=temp;
 }
}

int isempty(){
    if(front==NULL){
        return 1;

    }
    else{
        return 0;
    }
}

int dequeue(){
node *temp=front;
if(isempty()){
    printf("quque under fllow");
    exit(1);
}
int data=temp->data;
front=front->link;
if(front==NULL){
    rear=NULL;
}
free(temp);
temp=NULL;
return data;
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
    int choice,data;
    
    while(true){
        printf("enter choice \n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:printf("enter value to be inserted");
           scanf("%d",&data);
           enqueue(data);
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