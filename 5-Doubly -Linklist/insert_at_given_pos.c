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


node *insert_at_pos(node *head,int info,int pos){
    node *temp= malloc(sizeof(node));
    temp->prev=NULL;
    temp->data=info;
    temp->next=NULL;

    node *ptr1,*ptr2;
    ptr1=head;
    int i=1;
    while(i!=(pos-1)){
        ptr1=ptr1->next;
        i++;
    }
    ptr2=ptr1->next;
    ptr1->next=temp;
    ptr2->prev=temp;
    temp->prev=ptr1;
    temp->next=ptr2;
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
head=insert_at_pos(head,999,2);  // this willl insert at exact given position
traverse(head);
return 0;
}