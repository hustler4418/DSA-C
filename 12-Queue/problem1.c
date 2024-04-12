// impliment queue using two stack

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 4

int stack1[MAX];
int stack2[MAX];
int top1=-1,top2=-1;

void push1(int data){
       top1=top1+1;
       stack1[top1]=data;
}

void push2(int data){
       top2=top2+1;
       stack2[top2]=data;
}

int pop1(){
    int val =stack1[top1];
    top1=top1-1;
    return val;
}

int pop2(){
    int val =stack2[top2];
    top2=top2-1;
    return val;
}

int enqueue(int data){
       if(top1==MAX-1){
        printf("queue over flow");
        exit(1);
       }
       else{
              push1(data);
       }
}

int dequeue(){
       int temp;
       if(top2==-1){
              if(top1==-1){
                     printf("queue underflow");
              }
              while(top1!=-1){
                     temp=pop1();
                     push2(temp);
              }
       }
       return pop2();
}

void print(){
       if(top2==-1 && top1==-1){
              printf("queue underflow");
              exit(1);
       }
       for(int i=top2;i>=0;i--){
              printf("%d ",stack2[i]);
       }
       for(int i=0;i<=top1;i++){
              printf("%d ",stack1[i]);
       }
}

int peek(){
       if(top1!=-1){
              return stack1[0];
       }
       else{
              return stack2[top2];
       }
}


int main(){
    int choice,data;
    
    while(true){
    printf("enter choice");
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
    case 3:printf("first value is %d",peek());
           break;
    case 4:print();
           break;
    default :printf("wrong choice");
    }
    }
}