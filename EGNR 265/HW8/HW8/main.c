/*--------------------------------------------------------------------------*\
|* name: Sean Tesch                                                         *|
|* class: EGNR265                                                           *|
|* program: HW 8                                                            *|
|* date: 10/26/18                                                           *|
|* purpose: Without using array notation, reverses an initial array, and    *|
|*          stores it into a second and prints the two arrays               *|
|* compiled on: XCode                                                       *|
\*--------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

// Function prototyping
void Display_List(int *, int *, int);
int Array_Dev_Copy(int *, int, int *, int);

int main()
{
    // Variable declaration and definition
    int arr1_len, arr2_len, *arr1, *arr2, *t_ptr, *t2_ptr, count;
    count = 0;
    
    // Prints the intructions
    printf("\nThis program will ask the user for twp arrays and lengths for them.\n");
    printf("It will also ask the user to populate the first array with integers.\n");
    printf("It will then reverse the first array and store it into the second one.\n");
    printf("After that it will display the first array then the reversed one.\n");
    
    // Gets the first array length
    printf("\nEnter array length: ");
    scanf("%d", &arr1_len);
    
    // Allocates size of the first array using a temp pointer
    t_ptr = (int *) malloc(sizeof(int) * arr1_len);
    if (t_ptr == NULL)
        exit(-1);
    
    // Sets the first array to the temp pointer
    arr1 = t_ptr;
    
    // Asks user to fill the array
    printf("\nEnter %d integers into the array:\n", arr1_len);
    while (count < arr1_len)
    {
        scanf("%d", arr1++);
        count++;
    }
    
    // Asks for second array length
    printf("\nEnter length for a second array: ");
    scanf("%d", &arr2_len);
    
    // Allocates size of the second array using a temp pointer
    t2_ptr = (int *) malloc(sizeof(int) * arr2_len);
    if (t2_ptr == NULL)
        exit(-1);
    
    // Set the arrays to their temp pointers
    arr2 = t2_ptr;
    arr1 = t_ptr;
    
    // If the copy array returns one, print the initial
    // and reversed arrays
    if(Array_Dev_Copy(arr1, arr1_len, arr2, arr2_len))
    {
        printf("\nOriginal array:\n");
        Display_List(arr1, t_ptr, arr1_len);
        printf("Reversed array:\n");
        Display_List(arr2, t2_ptr, arr1_len);
        printf("\nSuccessful reversal; exiting now...\n");
    }
    
    // Frees the memory from the temp pointers
    free((void *)t_ptr);
    free((void *)t2_ptr);
    
    return 0;
}

// Used to print the values of the arrays
void Display_List(int *array, int *temp, int length)
{
    array = temp;
    
    // loops through the array
    for (int i = 0; i < length; i++)
    {
        // Prints the values of the array
        // If it's the last element,
        // print a new line instead of a comma
        if (i == length - 1)
            printf("%d \n", *array++);
        else
            printf("%d, ", *(array++));
    }
}

// Function used to store the revers of the first array into the second
int Array_Dev_Copy(int *array1, int num1, int *array2, int num2)
{
    // Checks if the second array length is too small
    if (num2 >= num1)
    {
        // if not, reverse the array and return 1 (true)
        for (int i = num1 - 1,  j = 0; i >= 0; i--, j++)
            *(array2+i) = *(array1+j);
        return 1;
    }
    else
    {
        // If so, tell the user and return 0 (false)
        printf("Second array length is too short; exiting now...\n");
        return 0;
    }
}
