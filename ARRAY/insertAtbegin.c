#include<stdio.h>
void withoutmaintaingorder(int arr[],int s,int n){
    arr[s]=arr[0];
    arr[0]=n;
    s++;
    for(int i=0;i<s;i++){
        printf("%d ",arr[i]);
    }
}
int main() {
char ch;
int arr[100]={12,58,12,77,88,99,1};
int s=7;
printf("Enter element to insert");
int n;
scanf("%d",&n);
getchar();// to consume previous new line we get after putting value and press enter
        //(as it still in input buffer)
printf("do you want to maintain order or array Y/N");
scanf("%c",&ch);
if(ch=='y'){
for(int i=s-1;i>=0;i--){
    arr[i+1]=arr[i];
}
s++;
arr[0]=n;
for(int i=0;i<s;i++){
    printf("%d ",arr[i]);
}
}
else{
withoutmaintaingorder(arr,s,n);
}
return 0;
}