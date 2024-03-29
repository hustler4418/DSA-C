#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
}node;

node *addToempty(int data){
    node *tail=malloc(sizeof(node));
tail->data=data;
tail->prev=tail;
tail->next=tail;
return tail;
}

node *insert_at_beg(node *tail,int data){
    node *newp=addToempty(data);
    if(tail==NULL){
        printf("Empty linklist");
        return newp;
    }
    node *temp=tail->next;
    newp->next=temp;
    newp->prev=tail;
    temp->prev=newp;
    tail->next=newp;
    return tail;
}

void traverse(node *tail){
    node *ptr=tail->next;
    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=tail->next);
}

int main() {
node *tail=malloc(sizeof(node));
tail=addToempty(45);
tail=insert_at_beg(tail,90);
tail=insert_at_beg(tail,135);
traverse(tail);
return 0;
}