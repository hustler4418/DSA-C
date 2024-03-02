#include<stdio.h>
#include<stdlib.h>

struct node{     // self referencing structure
    int data;
    struct node *link;
};

void insertion_at_begining(struct node **head,int info){
  struct node *temp=NULL;
  temp=malloc(sizeof(struct node));
  temp->data=info;
  temp->link=*head;
  *head=temp;
}

void print(struct node* head){
  struct node* ptr=head;
  while(ptr!=NULL){
    printf("%d \n",ptr->data);
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
    
    insertion_at_begining(&head,324);
  
    printf("\n");
    print(head);
    
return 0;
}