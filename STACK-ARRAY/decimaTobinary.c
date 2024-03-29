#include<stdio.h>
#include<stdlib.h>
#define MAX 40

int stack_arr[MAX];
int top=-1;

void push(int data){
    if(top==MAX-1){
        printf("STACK OVERFLOW");
        return;
    }
    top=top+1;
    stack_arr[top]=data;
}

int pop(){
    int value;
    if(top==-1){
        printf("stack underflow");
        exit(1);
    }
    value=stack_arr[top];
    top=top-1;
    return value;
}

void decTobin(int decimal){
    int i=2;
    while(decimal!=0){
        int div=decimal%2;
        push(div);
        decimal=decimal/2;
    }
    while(top!=-1){
        printf("%d ",pop());
    }
}

int main(){
decTobin(77);
}