#include <stdio.h>
#include <string.h>
typedef struct
{
    char name[20];
    char class[20];
    int hp;
}Character;

int main()
{
    Character hero;
    strcpy(hero.name,"Geralt");
    strcpy(hero.class,"Witcher");
    hero.hp=100;
    
    FILE *pF=fopen("C:\\Users\\USER\\Downloads\\WALLPAPERS\\TURKIYE BURSLARI\\GIT HUB\\C WITH GEM\\savedgame.txt","w");
    if (pF==NULL)
    {
        printf("\nError in file creation");
        return 1;
    }
    printf("File created successfully");
    fprintf(pF,"\nName: %s\nClass: %s \nHP: %d",hero.name,hero.class,hero.hp);
    printf("\nGame saved");
    fclose(pF);
    return 0;
}