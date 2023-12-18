#include<stdio.h>
#include<stdlib.h>

struct node{     // self referencing structure
    int data;
    struct node *link;
};
struct node* insertion_at_begining(struct node* head,int data){
struct node* ptr=malloc(sizeof(struct node));
ptr->data=data;
ptr->link=NULL;
ptr->link=head;
head=ptr;
return head;
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
    int data=5;
    head=insertion_at_begining(head,data);
    print(head);
return 0;
}