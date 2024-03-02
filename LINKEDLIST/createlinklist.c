#include<stdio.h>
#include<stdlib.h>

struct node{     // self referencing structure
    int data;
    struct node *link;
};



int main() {   // create linklist 
struct node *head=NULL;
head=(struct node *)malloc(sizeof(struct node));
head->data=45;
head->link=NULL;

struct node *newnode=malloc(sizeof(struct node));
newnode->data=90;
head->link=newnode;
newnode->link=NULL;

struct node *newnode1=malloc(sizeof(struct node));
newnode1->data=135;
head->link->link=newnode1;
newnode1->link=NULL;

printf("%d ",head->data);
printf("%d ",newnode->data);
printf("%d ",newnode1->data);
return 0;
}