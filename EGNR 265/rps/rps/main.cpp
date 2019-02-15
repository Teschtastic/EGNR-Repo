/**********************************************************/
/*                                                        */
/*   CSCI 121: Principles of Computer Programming         */
/*   Spring Semester 2015                                 */
/*                                                        */
/*   Assignment #4: Rock Paper Scissors                   */
/*                                                        */
/*   Programmed by: Sean Tesch                            */
/*                                                        */
/*   Due: Tuesday, January 27, 2015                       */
/*                                                        */
/**********************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>


using namespace std;

int main ()
{
    
    int num;
    char guess, reply;
    srand(time(0));
    
    do
    {
        num = rand() % 3;
        
        cout << "Choose paper (P), rock (R), or scissors (S) : ";
        cin >> ws;
        cin.get(guess);
        guess = toupper(guess);
        
        if (num == 0)
            cout << "The computer chose paper. " << endl;
        if (num == 1)
            cout << "The computer chose rock. " << endl;
        if (num == 2)
            cout << "The computer chose scissors. " << endl;
        
        if ((guess == 'P' && num == 1) || (guess == 'R' && num == 2) || (guess == 'S' && num == 0))
            cout << "You win! " << endl;
        if ((guess == 'P' && num == 0) || (guess == 'R' && num == 1) || (guess == 'S' && num == 2))
            cout << "There was a tie. " << endl;
        if ((guess == 'P' && num == 2) || (guess == 'R' && num == 0) || (guess == 'S' && num == 1))
            cout << "You lose. " << endl;
        
        cout << "Try again? (Y/N) ";
        cin >> ws;
        cin.get(reply);
    } while (toupper(reply) == 'Y');
    
    return 0;
}
