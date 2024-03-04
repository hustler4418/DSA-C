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

node *insert_at_first(node *head,int info){
    node *temp= malloc(sizeof(node));
    temp->prev=NULL;
    temp->data=info;
    temp->next=NULL;
    temp->next=head;
    head->prev=temp;
    head=temp;
    return  head;
}

void traverse(node *head){
    node *ptr=malloc(sizeof(node));
    if(head==NULL){
        printf("list is empty");
    }
    ptr=head;
    while(ptr!=NULL){
        printf("%d \n",ptr->data);
        ptr=ptr->next;
    }
}

int main() {
node *head=malloc(sizeof(node));
head=add_at_empty_list(head,45);
head=insert_at_first(head,90);
traverse(head);
return 0;
}