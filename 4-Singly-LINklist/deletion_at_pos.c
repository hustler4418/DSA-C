#include<stdio.h>       //deletion node at specific position
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}node;

void insert_at_end(node *head,int info){
    if(head==NULL){
        printf("Empty linklist");
    }
    node *ptr,*temp;
    ptr=head;
    temp=(node *)malloc(sizeof(node));
    temp->data=info;
    temp->link=NULL;

    while(ptr->link !=NULL){
        ptr=ptr->link;
    }
    ptr->link=temp;
}

void traverse(node *head){
    if(head==NULL){
        printf("no list is available");
    }
    //node *ptr=head;
    while(head!=NULL){
        printf("%d \n",head->data);
        head=head->link;
    }
}

void del_at_pos(node **head,int pos){
    node *current=*head;
    node *previous=*head;
    if(*head==NULL){
        printf("list is null");
    }
    else if(pos==1){
        *head=current->link;
        free(current);
        current=NULL;
    }
    else{
        int i=1;
        while(i!=pos){
            previous=current;
            current=current->link;
            i++;
        }
            previous->link=current->link;
            free(current);
            current=NULL;

    }
}

int main() {
    node *head=malloc(sizeof(node));
    head->data=45;
    head->link=NULL;
    insert_at_end(head,90);
    insert_at_end(head,135);
    insert_at_end(head,180);
    del_at_pos(&head,2);
    traverse(head);
}