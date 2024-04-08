#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 4

int deque[MAX];
int front=-1;
int rear=-1;

int isfull(){
    if(front==0 && rear==MAX-1 ||front==rear+1){
        return 1;
    }
    else
       return 0;
}

int isempty(){
    if(front==-1){
       return 1;
    }
    else
       return 0;
}


void enqueueFront(int data){
if(isfull()){
    printf("queue overflow");
    exit(1);
  
}
if(front==-1){
    front=rear=0;
}
else if(front==0){
    front=MAX-1;
}
else{
    front=front-1;
}
deque[front]=data;
}

void enqueueRear(int data){
if(isfull()){
    printf("queue overflow");
    exit(1);
  
}
if(front==-1){
    front=rear=0;
}
else if(rear==MAX-1){
    rear=0;
}
else{
    rear++;
}
deque[rear]=data;
}


int dequeueFront(){
int data;
if(isempty()){
    printf("queue underflow");
    exit(1);
}
data=deque[front];
if(front==rear) {// if there is only one element in queue
front=rear=-1;
} 
else if(front==MAX-1){  // fot reaching to first index
    front=0;
}
else{
    front++;
}
return data;
}

int dequeueRear(){
int data;
if(isempty()){
    printf("queue underflow");
    exit(1);
}
data=deque[front];
if(front==rear) {// if there is only one element in queue
front=rear=-1;
} 
else if(rear==0){  // fot reaching to first index
    rear=MAX-1;
}
else{
    rear--;
}
return data;
}


int peek(){
    if(isempty()){
    printf("queue underflow");
    exit(1);
}
return deque[front];
}



void print(){
    int temp;
    if(isempty()){
        printf("queue underflow \n");
        exit(1);
    }
    temp=front;
    if(front<=rear){
        while(temp<=rear){
            printf("%d ",deque[temp]);
            temp++;
        }
    }
    else{
        while(temp<=MAX-1){
            printf("%d ",deque[temp]);
            temp++;
        }
        temp=0;
        while(temp<=rear){
            printf("%d ",deque[temp]);
            temp++;
        }
    }
    printf("\n");
}


int main(){
    int choice,data;
    
    while(true){
    printf("Enter choice \n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:printf("enter value to insert from front");
           scanf("%d",&data);
           enqueueFront(data);
           break;
    case 2:printf("enter value to insert from rear");
           scanf("%d",&data);
           enqueueRear(data);
           break;
    case 3:data=dequeueFront();
           printf("\n deleted value from  front is %d ",data);
           break;
    case 4:data=dequeueRear();
           printf("\n deleted value from behind is %d ",data);
           break;
    case 5:printf(" \nfirst value is %d",peek());
           break;
    case 6:print();
           break;
    default :printf("\n wrong choice");
    }
    }
}