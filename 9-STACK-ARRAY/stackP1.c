#include<stdio.h>
#define MAX 4

//write a program to implement push() ,a stack in an array stack_arr[] 
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

void print(){
    if(first==-1){
        printf("stack is underflow");
    }
    for(int i=0;i<=first;i++){
        printf("%d\n",stack_arr[i]);
    }
}
int main(){
push(90);
push(34);
push(23);
print();

}