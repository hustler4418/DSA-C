#include<stdio.h>
#include<stdlib.h>

typedef struct node{        // As this doubly circular linklist  we need two pointer
struct node *prev;
int data;
struct node *next;
}node;

node *create_node(int d){
    node *temp=malloc(sizeof(node));
    temp->data=d;
    temp->next=temp;
    temp->prev=temp;
    return temp;
}

int main() {
int data=45;
node *tail=malloc(sizeof(node));
tail=create_node(data);
printf("%d",tail->data);
return 0;
}