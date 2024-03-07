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

node * insert(node * tail,int data){
    node *newp=malloc(sizeof(node));
    newp->data=data;
    newp->link=NULL;
    newp->link=tail->link;
    tail->link=newp;
    return tail;
}

int main() {
int data=655;
node *tail=malloc(sizeof(node));
tail=create_node(data);
tail=insert(tail,15);
printf("%d",tail->data);
return 0;
}