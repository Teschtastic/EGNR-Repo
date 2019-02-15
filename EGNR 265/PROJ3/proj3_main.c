/*--------------------------------------------------------------------------*\
|* name: Sean Tesch                                                         *|
|* class: EGNR265                                                           *|
|* program: HW 12                                                           *|
|* date: 12/06/18                                                           *|
|* purpose:  Stuff n things   *|
|* compiled on: XCode                                                       *|
\*--------------------------------------------------------------------------*/

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stat_support.h"

// Struct used for storing the time data
struct time
{
    int day;
    int month;
    int year;
    struct time *next;
};

void Open_File(FILE **);

int main()
{
    FILE *fp;
    int v, i;
    int day, month, year;
    int type, ft, fta, fg, fga, fg3, fg3a;
    char player[50], *comment;
    
    struct Sstat *p_h_ptr, *p_c_ptr, *p_t_ptr;
    struct time *t_h_ptr, *t_c_ptr, *t_t_ptr;
    
    Open_File(&fp);
    
    i = 0;
    while (1)
    {
        // Gets the data from the file an stores into local variables
        v = fscanf(fp, "%d,%d,%d:%d,%[^0-9],%d%d%d%d%d%d%[^0-9]\n", &day, &month, &year, &type, player, &ft, &fta, &fg, &fga, &fg3, &fg3a, comment);
        if (v == EOF)
            break;
        // Allocates memory for the time linked list
        t_c_ptr = (struct time *)malloc(sizeof(struct time));
        if (t_c_ptr == NULL)
            exit(1);
        
        // Stores the time variables into a linked list
        t_c_ptr->next = NULL;
        t_c_ptr->day = day;
        t_c_ptr->month = month;
        t_c_ptr->year = year;
        
        // Rearranges the pointers for the time list
        if (t_h_ptr == NULL)
            t_h_ptr = t_c_ptr;
        else
            t_t_ptr->next = t_c_ptr;
        t_t_ptr = t_c_ptr;
        
        // Allocates memory for the player linked list
        p_c_ptr = (struct Sstat *)malloc(sizeof(struct Sstat));
        if (p_c_ptr == NULL)
            exit(1);
        
        // Stores the player variables into a linked list
        p_c_ptr->next_ptr = NULL;
        p_c_ptr->type = type;
        strcpy(p_c_ptr->player, player);
        p_c_ptr->ft = ft;
        p_c_ptr->fta = fta;
        p_c_ptr->fg2 = fg;
        p_c_ptr->fg2a = fga;
        p_c_ptr->fg3 = fg3;
        p_c_ptr->fg3a = fg3a;
        p_c_ptr->comment = comment;
        
        // Rearranges the pointers for the player list
        if (p_h_ptr == NULL)
            p_h_ptr = p_c_ptr;
        else
            p_t_ptr->next_ptr = p_c_ptr;
        p_t_ptr = p_c_ptr;
        
        printf ("%d\n", i);
        i++;
        
    }
    
    fclose(fp);
    
	return 0;
}

// Uses double indirection to open a file defined by the user
void Open_File(FILE **file_ptr_ptr)
{
    char name[50];
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
