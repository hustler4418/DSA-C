#include<stdio.h>
#include<stdlib.h>

struct node{     // self referencing structure
    int data;
    struct node *link;
};

void print_linklist(struct node *ptr){
    int count=1;
    if(ptr==NULL){
        printf("empty linklist");
    }
    while(ptr!=NULL){
        printf("value %d : %d \n",count++,ptr->data);
        ptr=ptr->link;
    }
}
int main() {
    struct node *head=NULL;
    head=(struct node*)malloc(sizeof(struct node));   // fitst node
    head->data=45;
    head->link=NULL;

    struct node *current=malloc(sizeof(struct node)); // second node
    current->data=90;
    current->link=NULL;
    head->link=current;

    current=malloc(sizeof(struct node));  // thidrd node
    current->data=135;
    current->link=NULL;
    head->link->link=current;
    print_linklist(head);
return 0;
}