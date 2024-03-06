#include<stdio.h>
#include<stdlib.h>

typedef struct node{
struct node *link;
int data;
}node;

node *create_node(int d){
    node *temp=malloc(sizeof(node));
    temp->data=d;
    temp->link=temp;
    return temp;
}

int main() {
int data=45;
node *tail=malloc(sizeof(node));
tail=create_node(data);
printf("%d",tail->data);
return 0;
}