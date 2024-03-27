#include<stdio.h>
#define MAX 4

//write a program to implement pop() ,a stack in an array stack_arr[] 
//using stack_arr[0] as the top element

int stack_arr[MAX];
int first=-1;

void push(int data){
    int i;
    first+=1;
    for(i=first;i>0;i--){
        stack_arr[i]=stack_arr[i-1];
    }
    stack_arr[0]=data;
}
int pop(){
    int value;
    value=stack_arr[0];
    for(int i=0;i<=first;i++){
        stack_arr[i]=stack_arr[i+1];
    }
    first=first-1;
    return value;
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
int inf;
push(90);
push(34);
push(23);
inf=pop();
print();
}