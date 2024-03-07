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

node * insert_at_beg(node * tail,int data){
    node *newp=malloc(sizeof(node));
    newp->data=data;
    newp->link=NULL;
    newp->link=tail->link;
    tail->link=newp;
    return tail;
}

void traverse(node *tail){
    node *p=tail->link;
    do{
        printf("%d \n",p->data);
        p=p->link;
    }while(p!=tail->link);
}

int main() {
int data=655;
node *tail=malloc(sizeof(node));
tail=create_node(data);
tail=insert_at_beg(tail,15);
tail=insert_at_beg(tail,95);
tail=insert_at_beg(tail,115);
traverse(tail);
return 0;
}