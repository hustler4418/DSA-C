#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node{
    int data;
    struct node *link;
}node;

node *top=NULL;

void push(int data){
    node *newnode;
    newnode=malloc(sizeof(node));
    if(newnode==NULL){
        printf("stack overflow");
        exit(1);
    }
    newnode->data=data;
    newnode->link=NULL;
    newnode->link=top;
    top=newnode;
}

void print(){
    node *temp=top;

    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
    printf("\n");
}

int isempty(){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int pop(){
    int value;
    node *temp=top;
    if(top==NULL){
        printf("stack underflow");
        exit(1);
    }
    top=top->link;
    value=temp->data;
    free(temp);
    temp=NULL;
    return value;

}

void ispalindrome(char *str){
int i=0;
while(str[i]!='X'){
    push(str[i]);
    i++;
}
i++;
while(str[i]){
if(isempty() || str[i]!=pop()){
    printf("not a palindrome ");
    exit(1);
}
i++;
}
printf("it is palindrome");
}


int main() {
char str[100];
printf("Entet string");
scanf("%s",&str);
ispalindrome(str);
return 0;
}