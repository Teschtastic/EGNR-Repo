/*  stat_support.h
 *     DO NOT modify this file.  Only modify your source .c code
 */
//#define TERM_PC
//#define TERM_MAC
//#define TERM_LINUX
//#define TERM_UNKNOWN
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>      // for time()
#include <ctype.h>
#include <string.h>

#ifdef TERM_PC
#include <windows.h>   // or other WinApi header   (for color)
#include <conio.h>     // getch()
#endif

// define screen (console) viewing size for graph
#define SCREENX 80
#define SCREENY 35
#define YSIZE_MULT 5  // screen row window is this much deeper

/* useful constants */
#define MAX_STR_LEN    ( 50 )  // maximum string length of comment
#define MAX_NAME_LEN   ( 24 )  // max string length for player name

#define GEN_ERROR      (-10 )  // general error code
#define OPEN_READ_ERR  (-11 )  // could not open file error
#define OPEN_WRITE_ERR (-12 )  // could not open file error
#define FILE_READ_ERR  (-15 )  // failed on attempting to read a record

// types of run:
#define G_HOME         ( 01 )  // home game, non-conference
#define G_AWAY         ( 02 )  // away game, non-conference
#define G_HOME_CONF    ( 03 )  // home game, conference
#define G_AWAY_CONF    ( 04 )  // away game, conference
#define G_NEUTRAL      ( 05 )  // game at neutral site

/* useful macros */
#define MIN(x,y)      (((x) < (y)) ? (x) : (y))
#define MAX(x,y)      (((x) > (y)) ? (x) : (y))

/* structure declarations */
struct Date_St
{
  int d;           // day/month/year
  int m;
  int y;
};

struct Sstat
{
  struct Date_St date;         // date of run
  int type;                    // type of game
  char player[MAX_NAME_LEN];   // name of player
  int ft;             // free throws made
  int fta;            // free throws attempted
  int fg2;            // field goals (2 points) made
  int fg2a;           // field goals (2 points) attempted
  int fg3;            // 3 points goals made
  int fg3a;           // 3 points goals attempted
  char *comment;               // comment on conditions of player in game
  struct Sstat *next_ptr;      // pointer to next Sstat - linked list
};

/* provided functions (prototypes) */
void Get_Current_Day(int *year, int *month, int *day); // get current date
    // function accepts addresses of day, month, year as to modify each
int Day_Of_Week(int y, int m, int d); // get day of week
void Print_Month(int month);  // display month name
void Print_Dayofweek(int day);  // display day name
void Clear_Screen(void);      // clear the terminal/console screen
void Wait_For_Enter(void);    // prompt and wait for user (to press enter)
void Delay30(int duration);     // delay 30th of a second for each duration
int Movetoxy(int x, int y );  // move cursor to position X,Y on console screen
void Set_Color(int color);    // change color of cursor
void Set_Screen_Size(int, int);  // set the console screen size (x,y)
void Set_Screen_Title(char *); // set a title on the console screen

/*--------------------------------------------------------------*/
/* The following functions are provided.  Do not modify them!!  */
/*--------------------------------------------------------------*/

//***************************************************************
// GET_CURRENT_DAY()
//  Obtain current year, month, day from clock on computer
//  Accepts pointers to integers of year, month, and day (to modify)
//     NO NOT Modify
void Get_Current_Day(int *year, int *month, int *day)
{
  time_t t;
  struct tm *timeinfo;

  time(&t);
  timeinfo = localtime(&t);   // get local time in structure
  *day = timeinfo->tm_mday;   // extract day from structure
  *month = timeinfo->tm_mon+1;  // extract month (1-12)
  *year = timeinfo->tm_year+1900; // extract correct year
} // Get_Current_Day()

//***************************************************************
// DAY_OF_WEEK()
//  Given year, month, day, determine what day of the week it is
// y = year (e.g., 1988)
// m = month (1-12)
// d = day of month (1-31)
//    returns 0 = Sunday, 1 = Monday, etc.
//  Reference: Sakamoto's Algorithm (wikipedia - online)
int Day_Of_Week(int y, int m, int d)
{
  static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
  y -= m < 3;
  return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
} // Day_Of_Week()

//***************************************************************
// Print_Month()
//  Given month [1-12] value, print month name
void Print_Month(int month)
{
  static char *month_str[12] = {"January", "February","March",
                                "April", "May", "June",
                                "July", "August", "September",
                                "October", "November", "December"};

  printf("%s", month_str[month-1]);
} // Print_Month()


//***************************************************************
// Print_DAYOFWEEK()
//  Given day [1-7], print day name
void Print_Dayofweek(int day)
{
  static char *day_str[12] = {"Sunday", "Monday","Tuesday",
                              "Wednesday", "Thursday",
                              "Friday", "Saturday"};

  printf("%s", day_str[day-1]);
} // Print_Dayofweek()


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
void Delay30(int duration)
{
   long int endclock;

   endclock = clock()+(duration*CLOCKS_PER_SEC/30);
   while (clock() < endclock);        // wait for 1/30th of a second
} // Delay30()


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

/*  stat_support.h
 *     DO NOT modify this file.  Only modify your source .c code
 */



