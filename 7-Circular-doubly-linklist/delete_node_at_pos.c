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
    newp->next->prev=newp;
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

node *del(node *tail,int pos){
    node *ptr=tail->next;
    int i=1;
    while(i!=pos){
        ptr=ptr->next;
        i++;
    }
    node *temp=ptr->prev;
    temp->next=ptr->next;
    ptr->next->prev=temp;
    free(ptr);
    ptr=NULL;
    if(temp==tail){
        tail=temp;
    }
    return tail;
}

int main() {
    node *tail=malloc(sizeof(node));
    tail=addToempty(45);
    tail=insert_at_end(tail,90);
    tail=insert_at_end(tail,90*2); 
    tail=insert_at_end(tail,90*3); 
    tail=del(tail,2);  // delete last node
    traverse(tail);
return 0;
}