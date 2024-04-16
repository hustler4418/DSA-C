#include <stdio.h>

int main() {
    int a[11];
    for (int i=0;i<20;i++)
    a[i]=i*100+i+10;
    for (int i=0;i<20;i++)
    printf("%d -- %d \n",a[i],i+1);

    return 0;
}