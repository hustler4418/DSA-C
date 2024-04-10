// impliment queue using two stack

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 4
int stack1[];
int stack2[];
int top1=-1,top2=-1;

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