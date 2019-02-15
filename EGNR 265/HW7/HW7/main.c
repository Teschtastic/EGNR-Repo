/*--------------------------------------------------------------------------*\
|* name: Sean Tesch                                                         *|
|* class: EGNR265                                                           *|
|* program: HW 7                                                            *|
|* date: 10/22/18                                                           *|
|* purpose:  Query the user for 10 names and their ages, then prints them   *|
|*           out i order of their ages                                      *|
|* compiled on: XCode                                                       *|
\*--------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

void Get_Names(char [10][50], int);
void Get_Ages(int [10], int);
void Display_Person(char [10][50], int [10]);

int main()
{
    int ages[10];
    char names[10][50];
    
    for(int i = 0; i < 10; i++)
        Get_Names(names, i);
    
    printf("\n");
    
    for(int i = 0; i < 10; i++)
    {
        Get_Ages(ages, i);
        while (ages[i] < 0 || ages[i] > 150)
        {
            printf("Age is not within boundaries\n");
            Get_Ages(ages, i);
        }
    }
    
    printf("\n");
    Display_Person(names, ages);
    printf("\n");
    
    return 0;
}

void Get_Names(char names[10][50], int count)
{
    printf("Enter a name for person %d: ", count+1);
    fflush(stdin);
    gets(names[count]);
}

void Get_Ages(int ages[10], int count)
{
    printf("Enter person %d's age: ", count+1);
    scanf("%d", &ages[count]);
}

void Display_Person(char names[10][50], int ages[10])
{
    for(int i = 0; i < 150; i++)
        for(int j = 0; j < 10; j++)
            if(ages[j] == i)
                printf("%s has an age of:\t%3d\n", names[j], ages[j]);
}
