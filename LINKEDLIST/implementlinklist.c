#include<stdio.h>
#include<stdlib.h>

struct node{     // self referencing structure
    int data;
    struct node *link;
};
//void traverse(struct node* head);
void traverse(struct node* head){
  struct node* ptr=head;
  while(ptr!=NULL){
    printf("%d \n",ptr->data);
    ptr=ptr->link;
  }
}


int main() {   // create linklist in another way

    int n;
    printf("enter the linklist size");
    scanf("%d",&n);

    struct node *head=NULL;
    head=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&(head->data));
    head->link=NULL;
   
    struct node*ptr=head;

    for(int i=1;i<n;i++){
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&(newnode->data));
        newnode->link=NULL;
        ptr->link=newnode;
        ptr=ptr->link;
    }
    traverse(head);
return 0;
}