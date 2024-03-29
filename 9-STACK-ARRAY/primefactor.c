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

void prime_fact(int num){
    int i=2;
    while(num!=1){
        while(num%i==0){
            push(i);
         num=num/i;
        }
        i++;
    }
    while(top!=-1){
        printf("%d ",pop());
    }
}

int main(){
prime_fact(256);
}