#include<stdio.h>
#include<stdlib.h>

typedef struct node{     // self referencing structure
    int data;
    struct node *link;
}node;

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

int main() {   // create linklist  another method
printf("Enter the size of the link list");
int s;
scanf("%d",&s);
node *head=NULL;
head=malloc(sizeof(node));
printf("enter the 1st value");
scanf("%d",&(head->data));
head->link=NULL;

node *ptr=head;

for(int i=2;i<=s;i++){
    node *newnode=malloc(sizeof(node));
    printf("Enter the %d node value",i);
    scanf("%d",&(newnode->data));
    newnode->link = NULL;
    ptr->link=newnode;
    ptr=ptr->link;
}

traverse(head);

return 0;
}