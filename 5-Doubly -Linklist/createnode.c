#include<stdio.h>
#include<stdlib.h>

typedef struct node {         // self referecing structure for doubly linklist
    struct node *prev;
    int data;
    struct node *next;
}node;

int main() {
node *head=malloc(sizeof(node));
node *newnode=malloc(sizeof(node));

head->data=34;
head->prev=NULL;
head->next=newnode;

newnode->prev=head;
newnode->data=90;
newnode->next=NULL;

head=head->next;
printf("%d",head->data);
return 0;
}