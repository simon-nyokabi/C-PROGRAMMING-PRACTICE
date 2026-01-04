#include <stdio.h>
#include <string.h>

int main()
{
    char buffer[255];
    FILE *pF=fopen("C:\\Users\\USER\\Downloads\\WALLPAPERS\\TURKIYE BURSLARI\\GIT HUB\\C WITH GEM\\savedgame.txt","r");
    if (pF==NULL)
    {
        printf("\nError in file reading");
        return 1;
    }
    printf("File read successfully");
   while ( fgets(buffer,255,pF)!=NULL)
   {
    printf("%s",buffer);
   }
   
    fclose(pF);
    return 0;
}