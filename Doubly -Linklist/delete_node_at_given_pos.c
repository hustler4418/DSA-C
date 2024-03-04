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

node * del_at_given(node *head,int pos){
    node *ptr=head;
    int i=1;
    while(i != pos){
        ptr=ptr->next;
        i++;
    }
    node *ptr2=ptr->prev;  // pointing ptr2 before given node
    ptr2->next=ptr->next;
    ptr->next->prev=ptr2;
    free(ptr);
    ptr=NULL;
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

head=insert_at_end(head,135);   // 3rd node
head=insert_at_end(head,235);// 4th node
head=insert_at_end(head,435);// 5th node
head=del_at_given(head,4);
traverse(head);
return 0;
}