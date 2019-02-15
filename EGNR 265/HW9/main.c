/*--------------------------------------------------------------------------*\
|* name: Sean Tesch                                                         *|
|* class: EGNR265                                                           *|
|* program: HW 9                                                            *|
|* date: 10/31/18                                                           *|
|* purpose:  Opens, writes and closes a file with data written to it, then  *|
|*              then reads the data back to the user                        *|
|* compiled on: XCode                                                       *|
\*--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes for writing to and reading form the file
void File_Write(char[50], char[25], int *, int, FILE *);
void File_Read(char[50], char[25], int *, int, FILE *);

int main()
{
    // Declaring and defining the variables
    char filename[50], name[25], name1[25];
    FILE *f_ptr;
    int pow, num;
    pow = 0, num = 1;
    
    // Calling the functions to write and read
    File_Write(filename, name, &pow, num, f_ptr);
    File_Read(filename, name1, &pow, num, f_ptr);
    
    return 0;
}

// Function used to write to the file the information the user inputs
void File_Write(char filename[50], char name[25], int *pow, int num, FILE *f_ptr)
{
    // Used to store the value of the power
    int temp;
    
    // Asks user for their name and stores it in a variable
    fflush(stdin);
    printf("\nEnter your full name: ");
    gets(name);
    
    // Askes user for a file name and stores it
    fflush(stdin);
    printf("Enter a file name: ");
    gets(filename);
    
    // Asks user for iteration number and stores it
    printf("Enter number of iterations: ");
    scanf("%d", pow);
    
    // Sets the temp to the power the user defines
    temp = *pow;
    
    // Opens the file in write mode and if it's valid, continue
    f_ptr = fopen(filename, "w");
    if (f_ptr != NULL)
    {
        // Prints their name to the file
        fprintf(f_ptr, "Name: %s\n", name);
        for (int i = 1; i <= temp; i++)
        {
            // Prints a formatted power of two list
            // based on the iterations the user defined
            // by using bitshifting instead of multiplying
            fprintf(f_ptr, "%4d ", num << (i-1));
            if (i % 4 == 0)
                fprintf(f_ptr, "\n");
        }
    }
    printf("\n");
    // Closes the file when done
    fclose(f_ptr);
}

// Function used to read from the file and outputs it to the screen for the user
void File_Read(char filename[50], char name1[25], int *pow, int num, FILE *f_ptr)
{
    // Temp variable again
    int temp;
    
    // Opens the file in read mode and if it's valid, continue
    f_ptr = fopen(filename, "r");
    if (f_ptr != NULL)
    {
        // Gets the firt line from the file and stores it
        fgets(name1, 25, f_ptr);
        printf("%s", name1);
        
        // Sets the temp as the power again
        temp = *pow;
        
        for (int i = 1; i <= temp; i++)
        {
            // Reads the numbers from the file and prints them in
            // the same formatting as it was written
            fscanf(f_ptr, "%4d ", &num);
            printf("%4d ", num);
            if (i % 4 == 0)
                printf("\n");
        }
        printf("\n\n");
        
    }
    // Closes the file when done
    fclose(f_ptr);
}
