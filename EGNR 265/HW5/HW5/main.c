/*--------------------------------------------------------------------------*\
|* name: Sean Tesch                                                         *|
|* class: EGNR265                                                           *|
|* program: HW 4                                                            *|
|* date: 10/3/18                                                            *|
|* purpose: Demonstrate the same outputs using three different loops        *|
|*                                                                          *|
|* compiled on: XCode                                                       *|
\*--------------------------------------------------------------------------*/

#include <stdio.h>

/* ~ Prototyping functions ~ */
int Check_Values(int, int, int);
void While_Out(int, int, int);
void For_Out(int, int, int);
void Do_Out(int, int, int);

int main()
{
    /* ~ Declaring local variables ~ */
    int start_val = 0, step_val = 0, col_val = 0;
    
    /* ~ Asks for staring value until a valid number is given ~ */
    do
    {
        fflush(stdin);
        printf("Enter a starting value [0 to 500]: ");
        scanf("%d", &start_val);
    } while(Check_Values(0, 500, start_val));
    
    /* ~ Asks for step value until a valid number is given ~ */
    do
    {
        fflush(stdin);
        printf("Enter a step size [-5 to 5]: ");
        scanf("%d", &step_val);
    } while(Check_Values(-5, 5, step_val));
    
    /* ~ Asks for the columns until a valid number is given ~ */
    do
    {
        fflush(stdin);
        printf("Enter number of columns [1 to 10]: ");
        scanf("%d", &col_val);
    } while(Check_Values(1, 10, col_val));
    
    /* ~ Calling the loop functions ~ */
    While_Out(start_val, step_val, col_val);
    For_Out(start_val, step_val, col_val);
    Do_Out(start_val, step_val, col_val);
    
    printf("\n");
    
    return 0;
}

/* ~ Function that returns "true" or "false" based on
     the low and high values passed ~ */
int Check_Values(int low, int high, int val)
{
    if ((val >= low) && (val <= high))
    {
        return 0;
    }
    else
    {
        printf("Number was not in range... Enter new number\n");
        return 1;
    }
}

/* ~ Prints out the table using a while loop ~ */
void While_Out(int start, int step, int col)
{
    int count = 0, index = 0;
    
    printf("\nWHILE loop:");
    
    while (count != 15)
    {
        /* ~ If the step is positive ~ */
        if (step > 0)
        {
            /* ~ Prints new line and tabs and the number for
            formatting if the index is equalled to column amount~ */
            if (index % col == 0)
                printf("\n\t\t\t\t%3d ", start);
            /* ~ Prints the number only if the index is anything but
            the column number~ */
            else
                printf("%3d ", start);
            /* ~ Adds the step amount to the number ~ */
            start = start + step;
        }
        /* ~ If the step is negative ~ */
        else if (step < 0)
        {
            /* ~ Same as above ~ */
            if (index % col == 0)
                printf("\n\t\t\t\t%3d ", start);
            else
                printf("%3d ", start);
            start = start + step;
        }
        else if (step == 0)
        {
            if (index % col == 0)
                printf("\n\t\t\t\t%3d ", start);
            else
                printf("%3d ", start);
        }
        index++;
        count++;
    }
}

/* ~ Prints the same table for the FOR loop ~ */
void For_Out(int start, int step, int col)
{
    int count = 0, index = 0;
 
    printf("\nFOR loop:");
 
    for (count = 0; count < 15; count++)
    {
        if (step > 0)
        {
            if (index % col == 0)
                printf("\n\t\t\t\t%3d ", start);
            else
                printf("%3d ", start);
            start = start + step;
        }
        else if (step < 0)
        {
            if (index % col == 0)
                printf("\n\t\t\t\t%3d ", start);
            else
                printf("%3d ", start);
            start = start + step;
        }
        else if (step == 0)
        {
            if (index % col == 0)
                printf("\n\t\t\t\t%3d ", start);
            else
                printf("%3d ", start);
        }
        index++;
    }
}

void Do_Out(int start, int step, int col)
{
    int count = 0, index = 0;
    
    printf("\nDO-WHILE loop:");
    
    do
    {
        if (step > 0)
        {
            if (index % col == 0)
            {
                printf("\n\t\t\t\t%3d ", start);
            }
            else
                printf("%3d ", start);
            start = start + step;
        }
        else if (step < 0)
        {
            if (index % col == 0)
                printf("\n\t\t\t\t%3d ", start);
            else
                printf("%3d ", start);
            start = start + step;
        }
        else if (step == 0)
        {
            if (index % col == 0)
            {
                printf("\n\t\t\t\t%3d ", start);
            }
            else
                printf("%3d ", start);
        }
        index++;
        count++;
    } while (count != 15);
}
