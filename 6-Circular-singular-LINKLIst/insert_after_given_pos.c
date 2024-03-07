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

node * insert_at_beg(node * tail,int data){
    node *newp=malloc(sizeof(node));
    newp->data=data;
    newp->link=NULL;
    newp->link=tail->link;
    tail->link=newp;
    return tail;
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

node * insert_at_pos(node *tail,int info,int pos){
    node *newp=malloc(sizeof(node));   // creating the node which we will insert
    newp->data=info;
    newp->link=NULL;
 
    node* ptr=tail->link;
    int i=1;
    while(i!=pos){
        ptr=ptr->link;
        i++;
    }
    if(ptr==tail){
    newp->link=tail->link;
    tail->link=newp;
    tail=tail->link;
    }
    else{
        newp->link=ptr->link;
        ptr->link=newp;
    }
return tail;

}

int main() {
int data=655;   // 2nd node
node *tail=malloc(sizeof(node));
tail=create_node(data);
tail=insert_at_beg(tail,15);  // firsr node
tail=insert_end(tail,999);  // 3rd node
tail=insert_end(tail,569);  // 4th node
tail=insert_end(tail,239);  // 5th node
tail=insert_at_pos(tail,2519,2);
traverse(tail);

return 0;
}