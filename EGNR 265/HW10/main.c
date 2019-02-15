/*--------------------------------------------------------------------------*\
|* name: Sean Tesch                                                         *|
|* class: EGNR265                                                           *|
|* program: HW 10                                                           *|
|* date: 11/12/18                                                           *|
|* purpose:  Saves file information into a structure and allows the user to *|
|*           search for people within the structure                         *|
|* compiled on: XCode                                                       *|
\*--------------------------------------------------------------------------*/

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Filename constant
#define FILE_I "island.txt"

// Crew structure storing aspects
// Name, height, and weight
struct crew
{
    char name[50];
    int feet;
    int inches;
    int weight;
};

// Function prototype
void Find_Crew(int, int, struct crew[50], char[5]);

int main()
{
    // Initializing structure
    struct crew crewmate[50];

    // Declaring variales to use for
    // File, name, and iterations
    FILE *fp;
    char u_name[50];
    int v, j;
    
    // Asks user for name for searching
    printf("Enter the name (or part) of a crewmate: ");
    fflush(stdin);
    scanf("%s", u_name);

    // Opens the file
    fp = fopen(FILE_I, "r");
    if (fp == NULL)
        return -1;
    
    // Stores the pieces of the file
    // Into the structure in the same format
    v = 0;
    while (fscanf(fp, "%[^0-9]%d'%d'' %dlb\n", crewmate[v].name, &crewmate[v].feet, &crewmate[v].inches, &crewmate[v].weight) != EOF)
        v++;
    // Close the file
    fclose(fp);
    
    // Calls the function to search the structure
    Find_Crew(v, j, crewmate, u_name);
    
    return 0;
}

// Function used for searching for names that match the names in the
// Structure and prints them out to the screen
void Find_Crew(int v, int j, struct crew crewmate[50], char u_name[50])
{
    // Iterates through the amount of people in the file
    for (j = 0; j < v; j++)
    {
        // If the user string has any match with the names in the struct
        if (strncmp(crewmate[j].name, u_name, strlen(u_name)) == 0)
            // Print each name that has a match
            printf("%s%d'%d''\t%dlb\n", crewmate[j].name, crewmate[j].feet, crewmate[j].inches, crewmate[j].weight);
    }
}
