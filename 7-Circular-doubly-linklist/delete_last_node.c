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


node *insert_at_end(node *tail,int data){
    node *newp=addToempty(data);
    if(tail==NULL){
        printf("Empty linklist");
        return newp;
    }
    node *temp=tail->next;
    newp->next=temp;
    newp->prev=tail;
    tail->next=newp;
    tail->prev=newp;
    tail=newp;
    return tail;
}


void traverse(node *tail){
    node *ptr=tail->next;
    do{
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=tail->next);
}


node *del(node *tail){   // delete last node
    node *ptr=tail;
    tail=tail->prev;
    tail->next=ptr->next;
    ptr->next->prev=tail;
    free(ptr);
    ptr=NULL;
    return tail;
}


int main() {
node *tail=malloc(sizeof(node));
tail=addToempty(45);
tail=insert_at_end(tail,90);
tail=insert_at_end(tail,90*2); 
tail=del(tail);  // delete last node
traverse(tail);
return 0;
}