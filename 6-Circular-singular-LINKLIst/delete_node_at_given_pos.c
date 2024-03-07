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

node *del_at_pos(node *tail,int pos){
    node *temp=tail->link,*temp2;
    int i=1;
    while(i!=pos){
        temp=temp->link;
        i++; 
    }
    temp2=temp->link;
    temp->link=temp2->link;
    free(temp2);
    temp2=NULL;
    return tail;
}

int main() {
int data=655;   
node *tail=malloc(sizeof(node));
tail=create_node(data);      // insert node at empty list

tail=insert_end(tail,999);  // 2nd node
tail=insert_end(tail,569);  // 3rd node
tail=insert_end(tail,239);  // 4th node
tail=del_at_pos(tail,3);
traverse(tail);

return 0;
}
