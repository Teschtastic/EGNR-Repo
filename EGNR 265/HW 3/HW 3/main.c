/*--------------------------------------------------------------------------*\
|* name: Sean Tesch                                                         *|
|* class: EGNR265                                                           *|
|* program: HW 3                                                            *|
|* date: 9/19/18                                                            *|
|* purpose:                                                                 *|
|*                                                                          *|
|* compiled on: XCode                                                       *|
\*--------------------------------------------------------------------------*/

#include <stdio.h>

/* ~ Prototype the Get_Number function ~ */
unsigned int Get_Number(int);

int main()
{
    /* ~ Declaring the unsigned ints ~ */
    unsigned int w1, w2;
    
    /* ~ Calling the function to get the int values ~ */
    w1 = Get_Number(1);
    w2 = Get_Number(2);
    
    /* ~ Printing the AND operation in Decimal and Hex formats ~ */
    printf("\n%u & %u = %u\n", w1, w2, w1 & w2);
    printf("%X & %X = %X\n", w1, w2, w1 & w2);
    
    /* ~ Printing the OR operation in Decimal and Hex formats ~ */
    printf("\n%u | %u = %u\n", w1, w2, w1| w2);
    printf("%X | %X = %X\n", w1, w2, w1| w2);
    
    /* ~ Printing the XOR operation in Decimal and Hex formats ~ */
    printf("\n%u ^ %u = %u\n", w1, w2, w1 ^ w2);
    printf("%X ^ %X = %X\n", w1, w2, w1 ^ w2);
    
    /* ~ Printing the compliment of the first number in Dec and Hex formats ~ */
    printf("\n~%u = %u\n", w1, ~w1);
    printf("~%X = %X\n", w1, ~w1);
    
    /* ~ Printing the right bitshift operation in Decimal and Hex formats ~ */
    printf("\n%u >> %u = %u\n", w1, w2, w1 >> w2);
    printf("%X >> %X = %X\n", w1, w2, w1 >> w2);
    
    /* ~ Printing the left bitshift operation in Decimal and Hex formats ~ */
    printf("\n%u << %u = %u\n", w1, w2, w1 << w2);
    printf("%X << %X = %X\n", w1, w2, w1 << w2);
    
    return 0;
}

/* ~ Defining the Get_Number function ~ */
unsigned int Get_Number(int count)
{
    /* ~ Declaring the variable to store the number ~ */
    unsigned int num;
    
    /* ~ Cueing the user for a number and storing it into num then returns it ~ */
    printf("Enter number %d: ", count);
    scanf("%u", &num);
    return num;
}
