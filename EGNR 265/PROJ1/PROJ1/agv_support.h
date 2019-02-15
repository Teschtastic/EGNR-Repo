/*  agv_support.h
 *     DO NOT modify this file.  Only modify your source .c code
 */
//#define TERM_PC
//#define TERM_MAC
//#define TERM_LINUX
//#define TERM_UNKNOWN

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifdef TERM_PC
#include <windows.h>   // or other WinApi header   (for color)
#include <conio.h>     // getch()
#endif

#include <time.h>      // for time (Delay())

// define screen (console) size and file information
#define SCREENX 80
#define SCREENY 30
#define YSIZE_MULT 5


// other provided constants
#define DEG2RAD       0.0174533     // multiplier to convert degrees to radians
#define RAD2DEG      57.2957795     // multiplier to convert radians to degrees
#define CLOSE_ENOUGH  1.0e-10       // close enough to zero to be zero


#define MAX_AGV_WIDTH        50.0   // maximum width of the AVG in inches
#define MIN_AGV_WIDTH        30.0   // minimum width of the AVG in inches
#define MAX_AGV_LENGTH      100.0   // maximum length of the AVG in inches
#define MIN_AGV_LENGTH       50.0   // minimum length of the AVG in inches
#define MAX_AGV_VEL          60.0   // maximum velocity of the AGV in inches/second
#define MIN_TURN_RADIUS      24.0   // minimum turning radius for AGV in inches
#define STRAIGHT_HALL_LEN    20.0   // length of straight hallway in feet

/* structure definition */
struct Point    // creating a structure to contain (x,y) values
{
  double x;
  double y;
};

struct Line   // creating structure to contain 2 points - a line segment
{
  struct Point p1;
  struct Point p2;
};

/* provided functions (prototypes) */
void Clear_Screen(void);      // clear the terminal/console screen
void Wait_For_Enter(void);    // prompt and wait for user (to press enter)
void Delay(int duration);     // delay 30th of a second for each duration
int Movetoxy(int x, int y );  // move cursor to position X,Y on console screen
void Set_Color(int color);    // change color of cursor
void Set_Screen_Size(int, int);  // set the console screen size (x,y)
void Set_Screen_Title(char *); // set a title on the console screen




/*--------------------------------------------------------------*/
/* The following functions are provided.  Do not modify them!!  */
/*--------------------------------------------------------------*/

//***************************************************************
// CLEAR_SCREEN()
//  clear console window
//  Accepts nothing
//  Returns nothing
void Clear_Screen(void)
{
#ifdef TERM_PC
  system("cls");
#endif // TERM_PC

#ifdef TERM_MAC
    system("clear");
#endif // TERM_MAC
    
#ifdef TERM_LINUX
  clrscr();
#endif // TERM_LINUX

#ifdef TERM_UNKNOWN
  printf("\033[2J");   // clear screen (ncurses)
  printf("\033[1;1H"); // move cursor to 1,1
#endif // TERM_LINUX
}  // Clear_Screen()


//***************************************************************
// WAIT_FOR_ENTER()
//  prompts and then wait for user to press <enter> key
//  Accepts nothing
//  Returns nothing
void Wait_For_Enter(void)
{
  fflush(stdin);        // clear out input buffer
#ifdef TERM_PC
  system("pause");
#endif // TERM_PC

#ifdef TERM_MAC
    do
        printf("Press Enter to Continue");
    while( getchar() != '\n' );
#endif
    
#ifdef TERM_LINUX
  printf("Press <enter> to continue . . . ");
  getchar();
#endif // TERM_LINUX
} // Wait_For_Enter()


//***************************************************************
// DELAY()
//  wait for specified amount of time (# of 1/30th of a second)
//  Accepts integer of number of 1/30th of a second to delay
//  Returns nothing
//     REQUIRES: <time.h>
void Delay(int duration)
{
   long int endclock;

   endclock = clock()+(duration*CLOCKS_PER_SEC/30);
   while (clock() < endclock);        // wait for 1/30th of a second
} // delay()


//***************************************************************
// MOVETOXY()
//  Move cursor to X,Y coordinate on console window
//  Accepts X,Y coordinate to move the cursor to
//  Returns TRUE if it successfully moved the cursor, FALSE otherwise
int Movetoxy(int x, int y )
{
  int value = 0;

#ifdef TERM_PC
  COORD xy;

  xy.X = x;
  xy.Y = y;
  value = SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), xy );
  if (!value)
    printf("movetoxy failed :(, seems like coords are too big\n");
#endif // TERM_PC

#ifdef TERM_LINUX
  // no test if successful (always returns false), uses ucurses
  printf("\033[%d;%dH",x,y); // move cursor to row x, column y
#endif // TERM_LINUX

  return value;
} // movetoxy()


//***************************************************************
// SET_COLOR()
//  change color for cursor to display next character
//  Accepts integer of selected color (text, background, etc.)
//  Returns nothing
//     REQUIRES: <windows.h> (for PCs)
void Set_Color(int color)
{
#ifdef TERM_PC
  SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), color);
#endif // TERM_PC

#ifdef TERM_LINUX
  // not yet implemented - WIP
#endif // TERM_LINUX
} // set_color()


//***************************************************************
// SET_SCREEN_TITLE()
//  sets a string to use a window title
//  Accepts string to characters for title
//    Call once at the beginning of code
//     REQUIRES: <windows.h>
void Set_Screen_Title(char *title)
{
#ifdef TERM_PC
  SetConsoleTitle(title);
#endif // TERM_PC
} // Set_Screen_Title()


//***************************************************************
// SET_SCREEN_SIZE()
//  sets the size of the console window and does not allow for scrolling
//  Accepts X,Y size of desired console window
//    Call once at the beginning of code
//     REQUIRES: <windows.h>, <conio.h>
void Set_Screen_Size(int x, int y)
{
#ifdef TERM_PC
  COORD xy;
  SMALL_RECT r;
  HANDLE  hConsole;

  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  r.Left = 0;
  r.Top = 0;
  r.Right = x-1;
  r.Bottom = y-1;
  SetConsoleWindowInfo( hConsole, TRUE, &r);

  xy.X = x;
  xy.Y = y*YSIZE_MULT;
  SetConsoleScreenBufferSize( hConsole, xy);
#endif // TERM_PC

} // Set_Screen_Size()

/*  agv_support.h
 *     DO NOT modify this file.  Only modify your source .c code
 */



