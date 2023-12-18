#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};

struct node* insert_at_end(struct node *ptr,int d){
struct node *temp=malloc(sizeof(struct node));
temp->data=d;
temp->link=NULL;

ptr->link=temp;
return temp;
}

int main() {
    struct node *head=malloc(sizeof(struct node));
    head->data=45;  
    head->link=NULL;

    struct node *ptr=head;
    ptr=insert_at_end(ptr,90);
   ptr= insert_at_end(ptr,98);
    ptr=insert_at_end(ptr,135);
    ptr=head;
    while(ptr!=NULL){
        printf("%d \n",ptr->data);
        ptr=ptr->link;
    }
return 0;
}