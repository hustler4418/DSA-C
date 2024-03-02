#include<stdio.h>
#include<stdlib.h>

typedef struct node{     // self referencing structure
    int data;
    struct node *link;
}node;



int main() {   // create linklist  another method
printf("Enter the size of the link list");
int s;
scanf("%d",&s);
node *head=malloc(sizeof(node));
printf("enter the 1st value");
scanf("%d",&(head->data));
head->link=NULL;

node *ptr=head;

for(int i=2;i<=s;i++){
    node *newnode=malloc(sizeof(node));
    printf("Enter the %d node value",i);
    scanf("%d",&(newnode->data));
    ptr->link=newnode;
    ptr=ptr->link;
}



return 0;
}