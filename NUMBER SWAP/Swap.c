#include <stdio.h>

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int main()
{
    int val1=100;
    int val2=500;
    swap(&val1,&val2);
    printf("Val1: %d Val2: %d",val1,val2);

    return 0;
}