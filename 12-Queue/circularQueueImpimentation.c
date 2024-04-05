#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 4

int cqueue[MAX];
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


void enqueue(int data){
if(isfull()){
    printf("queue overflow");
    exit(1);
}
if(front==-1){
    front++;
}
if(rear=MAX-1){
    rear=0;
}
else{
    rear=rear+1;
    cqueue[rear]=data;
}
}


int dequeue(){
    int data;
if(isempty()){
    printf("queue underflow");
    exit(1);
}
data=cqueue[front];
if(front==rear) {// if there is only one element in queue
front=rear=-1;
} 
else if(front=MAX-1){  // fot reaching to first index
    front=0;
}
else{
    front++;
}
return data;
}

int peek(){
    if(isempty()){
    printf("queue underflow");
    exit(1);
}
return cqueue[front];
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