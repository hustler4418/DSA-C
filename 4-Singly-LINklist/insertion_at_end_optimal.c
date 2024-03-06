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
int main() {

    node *head=NULL;
head=(node *)malloc(sizeof(node));
head->data=45;
head->link=NULL;

node *newnode=malloc(sizeof(node));
newnode->data=90;
head->link=newnode;
newnode->link=NULL;

node *newnode1=malloc(sizeof(node));
newnode1->data=135;
head->link->link=newnode1;
newnode1->link=NULL;
insert_at_end(head,34);
traverse(head);
return 0;
}