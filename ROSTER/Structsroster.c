#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct{
    char name[50];
    int id;
    float gpa;    
}Student;
int main()
{
    
    int n=0;
    printf("Enter the number of students : ");
    scanf("%d",&n);
    Student *students=(Student*)malloc(n*sizeof(Student));
    if (students==NULL)
    {
        printf("Error in memory allocation!");
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter the details for student %d: ",i+1);
        printf("\nName : ");
        fgets(students[i].name,50,stdin);
        printf("\nId No: ");
        scanf("%d",&students[i].id);
        printf("\nGpa: ");
        scanf("%f",&students[i].gpa);    
    } 
   
    
    for (int i = 0; i < n; i++)
    {
        printf("\nStudent %d:",(i+1));
        printf("\n Name: %s Id: %d Gpa: %.2f",students[i].name,students[i].id,students[i].gpa);
    }
       
    free(students);
    students=NULL;

    return 0;
}