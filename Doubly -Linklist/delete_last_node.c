#include<stdio.h>
#include<stdlib.h>

typedef struct node {         // self referecing structure for doubly linklist
    struct node *prev;
    int data;
    struct node *next;
}node;


node *insert_at_end(node *head,int info){
    node *ptr,*temp;
    temp=malloc(sizeof(node));     
    temp->prev=NULL;             // this 3 line for creating last  node
    temp->data=info;
    temp->next=NULL;

    ptr=head;
    while(ptr->next !=NULL){       // this line for reaching last node
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->prev=ptr;
    return head;
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

node * del_at_last(node *head){
    node *ptr=head;
    while(ptr->next !=NULL){
        ptr=ptr->next;
    }
    node *ptr2=ptr->prev;
    ptr2->next=NULL;
    free(ptr);
    
    return head;
}


int main() {
node *head=malloc(sizeof(node));
node *newnode=malloc(sizeof(node));

head->data=34;       // first ndoe
head->prev=NULL;
head->next=newnode;

newnode->prev=head;   // second node
newnode->data=90;
newnode->next=NULL;

head=insert_at_end(head,135);
head=insert_at_end(head,235);
head=insert_at_end(head,435);
head=del_at_last(head);
traverse(head);
return 0;
}