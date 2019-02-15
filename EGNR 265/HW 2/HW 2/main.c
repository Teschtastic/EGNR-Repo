/*--------------------------------------------------------------------------*\
 * name: Sean Tesch                                                         *
 * class: EGNR265                                                           *
 * program: HW 2                                                            *
 * date: 9/10/18                                                            *
 * purpose: Create a program to give the price of eggs for variances of     *
 *          singles and dozens of eggs                                      *
 * compiled on: XCode                                                       *
\*--------------------------------------------------------------------------*/

#include <stdio.h>

/* ~ Defining the constant price of the eggs ~ */
#define SINGLE 0.09
#define DOZEN 1.00

/* ~ Prototyping the function ~ */
double Eggs(int);

int main()
{
    /* ~ Declaring int, asking for amount of eggs ~ */
    int numEggs = 0;
    printf("How many eggs would you like to buy?\n");
    scanf("%d", &numEggs);
    
    /* ~ Printing the price of the eggs and calling the function ~ */
    printf("The price of all your eggs is: $%.2f\n", Eggs(numEggs));
    
    return 0;
}

/* ~ Defining the function ~ */
double Eggs(int amount)
{
    /* ~ Setting the amount of dozens and singles ~ */
    int dozens = amount / 12;
    int extras = amount % 12;
    
    /* ~ Returning the price of the combined eggs ~ */
    return (dozens * DOZEN) + (extras * SINGLE);
}
