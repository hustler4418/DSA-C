#include<stdio.h>
int main() {
int arr[100]={12,58,12,77,88,99,1};
int s=7;
printf("Enter element to insert");
int n,index;
scanf("%d",&n);
printf("enter index");
getchar();
scanf("%d",&index);
for(int i=s-1;i>=index;i--){
    arr[i+1]=arr[i];
}
arr[index]=n;
s++;

for (int i = 0; i <s; i++)
{
    printf("%d ",arr[i]);
}

return 0;
}