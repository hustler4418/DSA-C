#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

char stack_arr[MAX];
int top=-1;

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
        exit(1);
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

int mach_char(char a,char b){
    if(a== '[' && b==']')
       return 1;
     if(a== '{' && b=='}')
       return 1;
     if(a== '(' && b==')')
       return 1;
     return 0;
}
int scan_string(char *str){
    int i;char temp;
    for(i=0;i<strlen(str);i++){
       if(str[i]=='[' || str[i]=='(' ||str[i]=='{'){
        push(str[i]);
       }
       if(str[i]==']' || str[i]==')' ||str[i]=='}'){
        if(isempty()){
            printf("Right bracket more than left bracket\n");
            return 0;
        }
        else{
        temp=pop();
        if(!mach_char(temp,str[i])){
            printf("mismathed bracket\n");
            return 0;
        }
       }
    }
}
if(isempty()){
    printf("bracker are well balanced \n");
    return 1;
}
else{
    printf(":left braket more than right brakcet \n");
    return 0;
}
}

int main(){
char str[100];
printf("Enter expresssion\n");
scanf("%s",str);
int ans=scan_string(str);
if(ans==1){
    printf("valid expression");
}
else{
    printf("invalid exprssoion");
}
}