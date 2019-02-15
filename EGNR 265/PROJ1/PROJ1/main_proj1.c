/*--------------------------------------------------------------------------*\
 |* name: Sean Tesch                                                         *|
 |* class: EGNR265                                                           *|
 |* program: PROJ 1                                                          *|
 |* date: 10/18/18                                                           *|
 |* purpose:  *|
 |*                                                                          *|
 |* compiled on: XCode                                                       *|
 \*--------------------------------------------------------------------------*/

//#define TERM_PC
#define TERM_MAC
//#define TERM_LINUX
//#define TERM_UNKNOWN

#include "agv_support.h"

#define DISPLAYX 80
#define DISPLAYY 30

// define other constants, function prototypes, and libraries here
void Print_Coord(struct Line);
void Print_Menu();
void Print_Instructions();

int main(int argc, char* argv[])
{
  // declare all local main variables here
  int selection;
  struct Line wall;

  // define a wall 10 unit along the x-axis using Line structure
  wall.p1.x = 0.0;
  wall.p1.y = 0.0;
  wall.p2.x = 10.0;
  wall.p2.y = 0.0;

  Set_Screen_Size(SCREENX,SCREENY);  // set console size - do NOT modify

// modify next line to have the console title read as you desire
  Set_Screen_Title(" -- Mobile Robot (AGV) Path Checker -- ");

  printf("\n\n  AVG path..\n\n");

    do
    {
        Print_Menu();
        scanf("%d", &selection);
        
        switch (selection)
        {
            case 1:
                Print_Instructions();
                Wait_For_Enter();
                break;
                
            default:
                break;
        }
    } while (selection != 6);

  Set_Color(0x7C);  // set color to RED on light gray
  Print_Coord(wall);
  Set_Color(0x07);  // set color back to default

  Delay(30);  // delay one full second
  Wait_For_Enter();
  Movetoxy(30,20);  // move cursor to position 30,20 on console
  printf("Done\n\n");

  return 42;
} // main()


// Print_Coord() - display the (x,y) to (x,y) end points of a line segment
//    Accepts the coordinate via struct line
//    Does not display units
//    Display at current cursor position and color
void Print_Coord(struct Line segment)
{
  printf("wall endpoints: ");
  printf("(%4.1lf,%4.1lf) to (%4.1lf,%4.1lf)\n",
          segment.p1.x, segment.p1.y,
          segment.p2.x, segment.p2.y);
}

void Print_Menu()
{
    printf("\n1. Instructions\n");
    printf("2. Something\n");
    printf("3. Something else\n");
    printf("4. Butts\n");
    printf("5. Nothing at all\n");
    printf("6. Exit\n");
    
    printf("Make a selection: ");
}

void Print_Instructions()
{
    Clear_Screen();
    printf("\nHere are all the instructions for using this thing.\n");
}

