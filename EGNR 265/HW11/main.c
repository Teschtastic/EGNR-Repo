/*--------------------------------------------------------------------------*\
 |* name: Sean Tesch                                                         *|
 |* class: EGNR265                                                           *|
 |* program: HW 11                                                           *|
 |* date: 11/16/18                                                           *|
 |* purpose:  Saves file information into a structure and allows the user to *|
 |*           search for people within the structure                         *|
 |* compiled on: XCode                                                       *|
 \*--------------------------------------------------------------------------*/

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define FILE_I "island.txt"
#define MAX 50
#define TO_KILO 0.453592
#define F_TO_CENTI 30.48
#define I_TO_CENTI 2.54

// Crew structure storing aspects
// Name, height, and weight
struct crew
{
    char name[MAX];
    int height;
    float weight;
    struct crew *next;
};

// Function prototypes
int Conv_To_Centi(int, int, int);
float Conv_To_Kilo(float);

int main()
{
    // Initializing structure
    struct crew *h_ptr = NULL, *t_ptr = NULL, *c_ptr = NULL, *temp_ptr;
    
    // Declaring variales to use for
    // File, name, and iterations
    FILE *fp;
    char name[MAX];
    int v, feet, inches, centi;
    float weight;
    
    // Opens the file
    fp = fopen(FILE_I, "r");
    if (fp == NULL)
        return -1;
    
    // Reads the file and stores values into variables, coverts, creates new
    // Nodes in the linked list, prints the new list, and deletes the list
    while (1)
    {
        // Scans the file into variables
        v = fscanf(fp, "%[^0-9]%d'%d'' %flb\n", name, &feet, &inches, &weight);
        if (v == EOF)
            break;
        
        // Converts height and weight to metric
        weight = Conv_To_Kilo(weight);
        centi = Conv_To_Centi(feet, inches, centi);
        
        // Allocates new node into the linked list
        c_ptr = (struct crew *)malloc(sizeof(struct crew));
        if (c_ptr == NULL)
            exit(1);
        
        // Stores the variables into the linked list
        c_ptr->next = NULL;
        strcpy(c_ptr->name, name);
        c_ptr->height = centi;
        c_ptr->weight = weight;
        
        // Rearranges the pointers for the list
        if (h_ptr == NULL)
            h_ptr = c_ptr;
        else
            t_ptr->next = c_ptr;
        t_ptr = c_ptr;
    }
    // Close the file
    fclose(fp);
    
    // Traverses the list and prints it
    c_ptr = h_ptr;
    while (c_ptr != NULL)
    {
        printf("%s%d centi\t%.2fkg\n", c_ptr->name, c_ptr->height, c_ptr->weight);
        c_ptr = c_ptr->next;
    }
    
    // Traverses the list and deletes the nodes
    c_ptr = h_ptr;
    while (c_ptr != NULL)
    {
        temp_ptr = c_ptr;
        c_ptr = c_ptr->next;
        free((void *)temp_ptr);
    }
    return 0;
}

// Function to convert imperial weight to metric
float Conv_To_Kilo(float weight)
{
    weight = weight * TO_KILO;
    return weight;
}

// Function to convert imperial height to metric
int Conv_To_Centi(int feet, int inches, int centi)
{
    centi = feet * F_TO_CENTI;
    centi = centi + (inches * I_TO_CENTI);
    return centi;
}
