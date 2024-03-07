#include<stdio.h>
#include<stdlib.h>

typedef struct node{
struct node *link;
int data;
}node;

node *create_node(int d){
    node *temp=malloc(sizeof(node));
    temp->data=d;
    temp->link=temp;
    return temp;
}

void traverse(node *tail){
    node *p=tail->link;
    do{
        printf("%d \n",p->data);
        p=p->link;
    }while(p!=tail->link);
}

node *insert_end(node *tail,int data){
    node *newp=malloc(sizeof(node));
    newp->data=data;
    newp->link=NULL;
    newp->link=tail->link;
    tail->link=newp;
    tail=tail->link;
    return tail;
}

node *del_last(node *tail){
    node *temp=tail->link;
    while(temp->link!=tail){
        temp=temp->link;
    }
    temp->link=tail->link;
    free(tail);
    tail=NULL;
    return temp;
}

int main() {
int data=655;   
node *tail=malloc(sizeof(node));
tail=create_node(data);      // insert node at empty list

tail=insert_end(tail,999);  // 2nd node
tail=insert_end(tail,569);  // 3rd node
tail=insert_end(tail,239);  // 4th node
tail=del_last(tail);
traverse(tail);

return 0;
}