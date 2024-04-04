#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100

int queue[MAX];
int front=-1;
int rear=-1;

int isfull(){
    if(rear==MAX-1){
        return 1;
    }
    else
       return 0;
}

int isempty(){
    if(front==-1|| front==rear+1){
       return 1;
    }
    else
       return 0;
}


void enqueue(int data){
if(isfull()){
    printf("queue overflow");
    exit(1);
}
if(front==-1){
    front++;
}
rear++;
queue[rear]=data;
}

int dequeue(){
    int data;
if(isempty()){
    printf("queue underflow");
    exit(1);
}
data=queue[front];
front++;
return data;
}

int peek(){
    if(isempty()){
    printf("queue underflow");
    exit(1);
}
return queue[front];
}

void print(){
  if(isempty()){
    printf("queue underflow");
    exit(1);
} 
printf("queues are");
for(int i=front;i<=rear;i++){
    printf("%d ",queue[i]);
}
}


int main(){
    int choice,data;
    
    while(true){
        
    switch (choice)
    {
    case 1:printf("enter value to be inserted");
           scanf("%d",&data);
           enqueue(data);
           break;
    case 2:data=dequeue();
           printf("deleted value is %d ",data);
           break;
    case 3:printf("first value is %d",peek());
           break;
    case 4:print();
           break;
    default :printf("wrong choice");
    }
    }
}