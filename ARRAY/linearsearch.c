#include<stdio.h>
int main() {
int arr[100]={12,26,2,25,02,1,7,8};
int s=8;
int i;
int key=71;
for(i=0;i<s;i++)

{
    if(arr[i]==key){
        printf("element at index  %d",i);
        break;
    }
}
if(i==s){
    printf("element not found ");
}
return 0;
}