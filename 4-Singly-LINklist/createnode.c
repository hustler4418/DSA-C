#include<stdio.h>
#include<stdlib.h>


struct node{          // node self refencing structure 
    int age;
    char name;
    struct node *link;
};


int main(){
struct node *head=NULL;
head=(struct node *)malloc(sizeof(struct node));
(*head).age=13;   // usng pointer
head->name='a';   // using arrow operator 
head->link=NULL;

printf("age is %d\n",head->age);
printf("name is %c",head->name);
}