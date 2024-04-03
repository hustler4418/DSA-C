#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX 100

int stack_arr[MAX];
int top=-1;
char infix[MAX],postfix[MAX];

void push(int data){
    if(top==MAX-1){
        printf("STACK OVERFLOW");
        return;
    }
    top=top+1;
    stack_arr[top]=data;
}

int pop(){
    int value;
    if(top==-1){
        printf("stack underflow");
    }
    value=stack_arr[top];
    top=top-1;
    return value;
}

int isempty(){
    if(top==-1){
        return 1;
    }
    return 0;
}

int precedence(char symbol){
    switch(symbol){
        case '^':return 3;
        case '/':
        case '*':return 2;
        case '+':
        case '-':return 1;
        default :
                 return 0;
    }
}


void inTopost(){
char symbol,next;
int j=0;
for(int i=0;i<strlen(infix);i++){
    symbol=infix[i];
    switch(symbol){
        case '(':push(symbol);
                 break;
        case ')':while((next=pop()) !='('){
                 postfix[j++]=next;
                 }
                 break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':while(!isempty() && precedence(stack_arr[top])>=precedence(symbol)){
                  postfix[j++]=pop();
                  }
                  push(symbol);
                break;
        default :postfix[j++]=symbol;
    }
   }
    while(!isempty()){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
}


void print(){
    int i=0;
    printf("the converted postfix expression is \n");
    while(postfix[i]){
     printf("%c",postfix[i]);
     i++;
    }
}

int postEvalute(){
    char symbol,a,b;
    for(int i=0;i<strlen(postfix);i++){
       
        if(postfix[i]>='0'&&postfix[i]<='9'){
            push(postfix[i]-'0');
        }
        else{
            a=pop();
            b=pop();
            switch(postfix[i]){
                case '+':push(b+a);
                         break;
                case '-':
                        push(b-a);break;
                case '*':push(b*a);break;
                case '/':push(b/a);break;
                case '^':push(pow(b,a));break;
               
            }
        }
    }
    return pop();
}

int main(){
printf("Enter infix expression");
gets(infix);
inTopost();
print();
printf("postfix after evalute : %d ",postEvalute());
}