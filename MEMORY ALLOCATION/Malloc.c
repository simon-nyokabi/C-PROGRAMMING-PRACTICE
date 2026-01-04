#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0;
    printf("How many numbers do you want to input? :");
    scanf("%d",&n);
    int *arr=(int*)malloc(n * sizeof(int));
    if (arr==NULL)
    {
        printf("Error in memory allocation!");
        return 1;
    }
       
    for (int i = 0; i < n; i++)
    {
        printf("Enter number %d :",i+1); 
        scanf("%d",&arr[i]);
    }
    printf("You entered: ");
    for (int i = 0; i <n; i++)
    {
        printf("\n%d",arr[i]);    
    }   
     
    free(arr);   
    arr=NULL;
    return 0;
}