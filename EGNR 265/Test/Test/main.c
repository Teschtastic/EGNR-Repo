/*--------------------------------------------------------------------------*
 * name: Sean Tesch                                                         *
 * class: EGNR265                                                           *
 * program: HW 1 - 9/7/18                                                   *
 * purpose: Ask for four integers and take the product and sum of them      *
 * compiled on: XCode                                                       *
 *--------------------------------------------------------------------------*/

#include <stdio.h>

int main()
{
    /* ~ Initialize the variables I will need ~ */
    int num1, num2, num3, num4;
    int sum, prod;
    
    /* ~ Asking for the four ints ~ */
    printf("Enter four integers\n\n");
    
    /* ~ Getting the user to input the ints ~ */
    printf("Enter the first\t integer: ");
    scanf("%d", &num1);
    
    printf("Enter the second integer: ");
    scanf("%d", &num2);
    
    printf("Enter the third\t integer: ");
    scanf("%d", &num3);
    
    printf("Enter the fourth integer: ");
    scanf("%d", &num4);
    
    /* ~ Taking the sum and prod of the ints ~ */
    sum = num1 + num2 + num3 + num4;
    prod = num1 * num2 * num3 * num4;
    
    /* ~ Print the sum and prod to the screen ~ */
    printf("\nThe sum of the four integers is: %d\n", sum);
    printf("The product of the four integers is: %d\n", prod);
    
    return 0;
}
