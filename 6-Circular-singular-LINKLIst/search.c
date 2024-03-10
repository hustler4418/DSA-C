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




void search_element(node *tail,int element){
    node *ptr=tail->link;
    int node=0;
    do{
        if(element==ptr->data){
            printf("elemnet at node: %d",node);
        }
        ptr=ptr->link;
        node++;
    }while(ptr!=tail->link);

}

int main() {
int data=655;   
node *tail=malloc(sizeof(node));
tail=create_node(data);      // insert node at empty list

tail=insert_end(tail,999);  // 2nd node
tail=insert_end(tail,569);  // 3rd node
tail=insert_end(tail,239);  // 4th node

search_element(tail,569);

return 0;
}
