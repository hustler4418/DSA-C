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

node * del_at_first(node *head){
    if(head==NULL){
        printf("list is null");
    }
    else{
        node *temp=head;
        head=head->link;
        free(temp);
        temp=NULL;
    }
    return head;
}

int main(){
    node *head=malloc(sizeof(node));
    head->data=45;
    head->link=NULL;
    insert_at_end(head,90);
    insert_at_end(head,135);
    insert_at_end(head,180);
    head=del_at_first(head);
    traverse(head);
}