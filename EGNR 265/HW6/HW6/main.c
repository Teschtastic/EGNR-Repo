/*--------------------------------------------------------------------------*\
|* name: Sean Tesch                                                         *|
|* class: EGNR265                                                           *|
|* program: HW 6                                                            *|
|* date: 10/10/18                                                           *|
|* purpose: Takes the average of up to 30 non-negative integers in an array *|
|*                                                                          *|
|* compiled on: XCode                                                       *|
\*--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

/* ~ Setting max array size constant ~ */
#define MAX 30

/* ~ Prototype average function ~ */
float Comp_Avg(int[], int);

int main()
{
    int int_storage[MAX], base_int = 0, int_count = 0;
    
    /* ~ Loops forever unless broken out of ~ */
    while(1)
    {
        /* ~ Asks user to enter integers and save them into the array ~ */
        printf("Enter a non negative interger (0 to exit): ");
        scanf("%d", &base_int);
        int_storage[int_count] = base_int;
        
        /* ~ If it's a valid int, iterate the count ~ */
        if (base_int > 0)
            int_count++;
        
        /* ~ If it isn't valid, tell the user and continue the loop ~ */
        if (base_int < 0)
            printf("Number not valid, enter a new number\n");
        
        /* ~ Leave the loop if either  he exit int is typed or max ints have been entered~ */
        if (base_int == 0)
            break;
        if (int_count == MAX)
            break;
    }
    
    /* ~ Calls the function and prints the avereage ~ */
    printf("The average of all the numbers is: %.2f\n", Comp_Avg(int_storage, int_count));
    
    exit(0);
}

float Comp_Avg(int array[], int count)
{
    float avg = 0.0;
    
    /* ~ Used to avoid divide by zero error ~ */
    if (count == 0)
        return -1.0;
    
    /* ~ Adds each element of the array into the avg variable ~ */
    for (int i = 0; i < count; i++)
        avg = avg + array[i];
    
    /* ~ Divides total  by the count to get the average ~ */
    avg = avg / count;
    
    return avg;
}
