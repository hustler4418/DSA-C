#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack_arr[MAX];
int first=-1;

int isfull(){
    if(first==MAX-1)
      return 1;
    else 
      return 0;
}

int isempty(){
    if(first==-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(int data){
    int i;
    if(isfull()){
        printf("stack overflow");
        exit(1);
    }
    first+=1;
    for(i=first;i>0;i--){
        stack_arr[i]=stack_arr[i-1];
    }
    stack_arr[0]=data;
}

int pop(){
    int value;
    if(isempty()){
        printf("stack underflow");
        exit(1);
    }
    value=stack_arr[0];
    for(int i=0;i<=first;i++){
        stack_arr[i]=stack_arr[i+1];
    }
    first=first-1;
    return value;
}

int peek(){
    if(isempty()){
        printf("stack underflow");
        exit(1);
    }
    return stack_arr[0];
}

void print(){
    if(first==-1){
        printf("stack is underflow");
    }
    for(int i=0;i<=first;i++){
        printf("%d\n",stack_arr[i]);
    }
}
int main(){
    int choice,data;
    while(1){
        printf("\n");
        printf("1.for push\n");
        printf("2.for pop\n");
        printf("3.print the top element\n");
        printf("4.print all the elemtn in stack\n");
        printf("5 quit\n");
        printf("enter your choice ");
        scanf("%d",&choice);
    switch(choice){
        case 1:
               printf("enter the element to be push");
               scanf("%d",&data);
               push(data);
               break;
        case 2:
              data=pop();
              printf("The deleted element is %d",data);
              break;        
        case 3:
             printf("the top most element %d",peek());
             break;
        case 4:
             print();
             break;
        case 5:
             exit(1);
        default :
             printf("wrong choice");
}
}
}