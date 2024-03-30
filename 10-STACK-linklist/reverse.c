#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

void push(int data,node **head){
node *newnode=malloc(sizeof(node));
if(newnode==NULL){
    printf("stack overflow");
    exit(1);
}
newnode->data=data;
newnode->link=NULL;
newnode->link=*head;
*head=newnode;
}

int pop(node **head){
    node *temp=*head;
    int value;
    if(*head==NULL){
        printf("stack underflow");
        exit(1);
    }
    value=temp->data;
    *head=temp->link;
    free(temp);
    return value;
}


void print(node **top){
 node *ptr=*top;
 if(*top==NULL){
    printf("stack underflow \ng");
   // exit(1);
 }
 while(ptr!=NULL){
    printf("%d \n",ptr->data);
    ptr=ptr->link;
 }  
}


int main() {
node *top=NULL;  // original stack
node *top1=NULL; // temporary stack 1
node *top2=NULL; // temporary stack 2
int value;
// push value to original stack
push(1,&top);
push(2,&top);
push(3,&top);
print(&top);
//pop value from original stack and push to temporary stack 1
value=pop(&top);
push(value,&top1);
value=pop(&top);
push(value,&top1);
value=pop(&top);
push(value,&top1);
print(&top);
print(&top1);
//pop value from temporay stack 1 and push to temporary stack 2

value=pop(&top1);
push(value,&top2);
value=pop(&top1);
push(value,&top2);
value=pop(&top1);
push(value,&top2);
print(&top1);
print(&top2);
// pop value from temporary stack and push to original stack

value=pop(&top2);
push(value,&top);
value=pop(&top2);
push(value,&top);
value=pop(&top2);
push(value,&top);
print(&top2);
print(&top);


return 0;
}