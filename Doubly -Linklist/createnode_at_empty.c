#include<stdio.h>
#include<stdlib.h>

typedef struct node {         // self referecing structure for doubly linklist
    struct node *prev;
    int data;
    struct node *next;
}node;

node * add_at_empty_list(node *head,int info){
    node *temp=malloc(sizeof(node));
    temp->prev=NULL;
    temp->data=info;
    temp->next=NULL;
    head=temp;
    return head;
}


int main() {
node *head=malloc(sizeof(node));
head=add_at_empty_list(head,45);

printf("%d",head->data);
return 0;
}