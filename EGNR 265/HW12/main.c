/*--------------------------------------------------------------------------*\
|* name: Sean Tesch                                                         *|
|* class: EGNR265                                                           *|
|* program: HW 12                                                           *|
|* date: 11/28/18                                                           *|
|* purpose:  Opens a file, saves into a linked list, uses bubble sort to    *|
|*           sort the poeple in the file as well as searching for people.   *|
|* compiled on: XCode                                                       *|
\*--------------------------------------------------------------------------*/

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX 50

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
void Open_File(FILE **);
struct crew *Sort_List(struct crew *, struct crew *);
void Search_List(struct crew *);
void Print_List(struct crew *);
void Delete_List(struct crew *);

int main()
{
    // Initializing structure
    struct crew *h_ptr = NULL, *t_ptr = NULL, *c_ptr = NULL, *temp_ptr;
    
    // Declaring variales to use for
    // File, name, and stats for imperial and metric
    FILE *fp;
    int v, feet, inches, weight_i;
    float weight_m, height;
    char name[MAX], s_name[MAX];
    
    // Opens the file
    Open_File(&fp);
    
    // Reads the file and stores values into variables, coverts, creates new
    // Nodes in the linked list, prints the new list
    while (1)
    {
        // Scans the file into variables
        v = fscanf(fp, "%[^0-9]%d'%d'' %dlb\n", name, &feet, &inches, &weight_i);
        if (v == EOF)
            break;
        
        // Converts height and weight from imperial to metric
        weight_m = weight_i * 0.453592;
        height = feet * 30.48;
        height = height + (inches * 2.54);
        
        // Allocates new node into the linked list
        c_ptr = (struct crew *)malloc(sizeof(struct crew));
        if (c_ptr == NULL)
            exit(1);
        
        // Stores the variables into the linked list
        c_ptr->next = NULL;
        strcpy(c_ptr->name, name);
        c_ptr->height = height;
        c_ptr->weight = weight_m;
        
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
    Print_List(h_ptr);
    // Searches for a crewmate from the user
    Search_List(h_ptr);
    
    h_ptr = Sort_List(h_ptr, c_ptr);
    Print_List(h_ptr);
    // Traverses the list and deletes the nodes
    Delete_List(h_ptr);
    
    return 0;
}

// Uses double indirection to open a file defined by the user
void Open_File(FILE **file_ptr_ptr)
{
    char name[MAX];
    // Ask user to enter a file name
    printf("Enter name of file to open: ");
    scanf("%s", name);
    // Attempt to open that file
    *file_ptr_ptr = fopen(name, "r");
    // If the file doesn't exist, print error and exit right away.
    if (*file_ptr_ptr == NULL)
    {
        printf("ERROR:\nInvalid file\nExiting now\n");
        exit(-1);
    }
}

struct crew *Sort_List(struct crew *h_ptr, struct crew *ptr)
{
    struct crew *t_ptr;
    
    if (h_ptr == NULL)
        return (ptr);
    
    t_ptr = h_ptr;
    
    if (strcmp(ptr->name, t_ptr->name) < 0)
    {
        ptr->next = t_ptr;
        return (ptr);
    }
    
    while (t_ptr->next != NULL)
    {
        if (strcmp(t_ptr->next->name, ptr->name) > 0)
        {
            t_ptr = t_ptr->next;
            continue;
        }
        
        ptr->next = t_ptr->next;
        t_ptr->next = ptr;
        return (h_ptr);
    }
    
    t_ptr->next = ptr;
    return (h_ptr);
        
}

// Prompts user for something to search for then traverses the list
// to find any matches and prints the matches and their data
void Search_List(struct crew *h_ptr)
{
    struct crew *c_ptr, *temp_ptr;
    char s_name[MAX];
    
    // Prompts user
    printf("Enter a crewmate name (or part of one): ");
    // Flushes the keyboard buffer
    fflush(stdin);
    // Gets the string from the user
    gets(s_name);
    printf("\n");
    
    // Sets the current pointer to the head pointer
    c_ptr = h_ptr;
    while (c_ptr != NULL)
    {
        // If the currents name matches with the user string
        if (strncmp(c_ptr->name, s_name, strlen(s_name)) == 0)
            // print the data associated with the name
            printf("%s%d centi\t%.2fkg\n", c_ptr->name, c_ptr->height, c_ptr->weight);
        // Go to the next node in the list
        c_ptr = c_ptr->next;
    }
}

// Traverses through the linked list node by node and prints
// Out each crew member and their stats
void Print_List(struct crew *h_ptr)
{
    // Delcare variables
    struct crew *c_ptr;
    // Sets the current pointer to the head
    c_ptr = h_ptr;
    // While not at the end
    while (c_ptr != NULL)
    {
        // Print the name and stats
        printf("%s%d centi\t%.2fkg\n", c_ptr->name, c_ptr->height, c_ptr->weight);
        // Set the current to the next node
        c_ptr = c_ptr->next;
    }
}

// Traverses through the linked list node by node and deletes
// each node until the end ofthe list
void Delete_List(struct crew *h_ptr)
{
    // Delcare variables
    struct crew *c_ptr, *temp_ptr;
    // Sets the current pointer to the head
    c_ptr = h_ptr;
    // While not at the end
    while (c_ptr != NULL)
    {
        // Uses a temp pointer to store the contents of c_ptr
        temp_ptr = c_ptr;
        // Sets c_ptr to the next node
        c_ptr = c_ptr->next;
        // Delete the memory used by temp
        free((void *)temp_ptr);
    }
}
