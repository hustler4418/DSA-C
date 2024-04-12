// reverse queue using stack

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 4

int stack[MAX];
int queue[MAX];
int top=-1,rear=-1,front=-1;

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

void push(int data){
       top=top+1;
       stack[top]=data;
}


int pop(){
    int val =stack[top];
    top=top-1;
    return val;
}

void enqueue(int data){
if(isfull()){
    printf("queue overflow 8");
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
    printf("queue underflow 8");
    exit(1);
}
data=queue[front];
front++;
return data;
}


void reverse(){
    while(!isempty()){
        push(dequeue());
    }
    front=-1;
    rear=-1;
    while(top!=-1){
        enqueue(pop());
    }
}

void print(){
    if(isempty()){
        printf("Queueu underflow 9 ");
        exit(1);
    }
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
}

int main(){
enqueue(10);
enqueue(20);
enqueue(30);
enqueue(40);
reverse();
print();
}