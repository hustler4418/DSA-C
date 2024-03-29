#include<stdio.h>
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

void insert_at_pos(node **head,int info,int pos){     // insert at certain position
    node *ptr,*newnode;
    ptr=*head;
    newnode=malloc(sizeof(node));
    newnode->data=info;
    newnode->link=NULL;
   int i=1;
   if(pos==1){
    newnode->link=*head;
    *head=newnode;
   }
   else{
   while(i!=(pos-1)){
    ptr=ptr->link;
    i++;
   }
   newnode->link=ptr->link;
   ptr->link=newnode;
}
}

int main(){
    node *head=malloc(sizeof(node));
    head->data=45;
    head->link=NULL;
    insert_at_end(head,90);
    insert_at_end(head,135);
    insert_at_end(head,180);
    insert_at_pos(&head,1923,1);
    traverse(head);
}