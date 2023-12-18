#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};
void insert_at_end(struct node *head,int value){
struct node*ptr,*temp;
ptr=head;
temp=(struct node*)malloc(sizeof(struct node));
temp->data=value;
temp->link=NULL;
while(ptr->link!=NULL){
    ptr=ptr->link;
}
ptr->link=temp;

}
void printlist(struct node *ptr){
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
struct node *head=(struct node*)malloc(sizeof(struct node));
head->data=45;
head->link=NULL;
struct node *current=(struct node*)malloc(sizeof(struct node));
current->data=90;
current->link=NULL;
head->link=current;
current=(struct node*)malloc(sizeof(struct node));
current->data=135;
current->link=NULL;
head->link->link=current;
insert_at_end(head,199);
printlist(head);

return 0;
}