#include<stdio.h>
int main() {
int arr[100]={12,58,12,77,88,99,1};
int s=7;
int index;
printf("Enter index to be deleted");
scanf("%d",&index);
for(int i=index;i<s;i++){
    arr[i]=arr[i+1];
}
s--;
for (int i = 0; i <s; i++)
{
    printf("%d ",arr[i]);
}

return 0;
}