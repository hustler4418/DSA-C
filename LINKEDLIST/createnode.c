#include<stdio.h>
#include<stdlib.h>

struct node{     //  self referencing structure
    int data;
    struct node *link;
};

int main(){
    struct node *head=NULL;
    head=(struct node*)malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
      
    printf("%d",head->data);
}