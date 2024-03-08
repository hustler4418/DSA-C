#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
}node;

node *addToempty(node *tail){
tail->data=45;
tail->prev=tail;
tail->next=tail;
return tail;
}

int main() {
node *tail=malloc(sizeof(node));
addToempty(tail);
printf("%d",tail->data);
return 0;
}