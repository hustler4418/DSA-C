#include<stdio.h>
#include<stdlib.h>
#define MAX 10

char tree[MAX];

void root(char ch){
    if(tree[0]!='\0'){
        printf("root exist");
    }
    else{
        tree[0]=ch;
    }
}

void left(char ch,int parent){
    if(tree[parent]=='\0'){
        printf("parent does not exist");
    }
    else{
        tree[2*parent+1]=ch;
    }
}

void right(char ch,int parent){
    if(tree[parent]=='\0'){
        printf("parent does not exist");
    }
    else{
        tree[2*parent+2]=ch;
    }
}

void print(){
    for(int i=0;i<MAX;i++){
     printf("%d ",tree[i]);
    }
}

int main() {

root('A');
left('B',0);
right('C',0);
left('D',1);
right('E',2);
print();
return 0;
}