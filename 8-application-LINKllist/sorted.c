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

struct node *insert(node *head,int data){  // insertin at sortedl linklist
node *temp=malloc(sizeof(node));
temp->data=data;
temp->link=NULL;

node *ptr=head;
int key=data;
if(head==NULL || key<head->data){      // for first node
   temp->link=head;
   head=temp;
   return head;
}
else{                               // for intermidiate and last node
    while(ptr->link !=NULL && ptr->link->data <key){     
        ptr=ptr->link;
    }
 temp->link=ptr->link;
 ptr->link=temp;
 return head;
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
insert_at_end(head,134);
insert_at_end(head,154);
insert_at_end(head,194);
head=insert(head,994);
traverse(head);
return 0;
}