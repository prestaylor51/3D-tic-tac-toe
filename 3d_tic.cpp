/***********************************************************************
* Program:
*    Lesson 08, Tic-Tac-Toe
* Summary: 
*    This program reads, displays, and writes a Tic-Tac-Toe board
* Authors:
*    Tyler Christensen, Taft Christensen, Zach Hulse, David Harris,
*    ,and Preston Taylor
************************************************************************/

#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

#define BOARD_SIZE 3 // NEW
#define PLAYER_X 'X' // NEW
#define PLAYER_O 'O' // NEW
#define BLANK '.'    // NEW

bool read(         char board[][BOARD_SIZE][BOARD_SIZE], const char* fileName);// MOD
bool write(  const char board[][BOARD_SIZE][BOARD_SIZE], const char* fileName);// MOD
void display(const char board[][BOARD_SIZE][BOARD_SIZE]);// MOD
bool didWin( const char board[][BOARD_SIZE][BOARD_SIZE], char turn);// MOD

/**********************************************************************
 * Keeps the data and calles the read/display/write functions
 ***********************************************************************/
int main()
{
   char board[BOARD_SIZE][BOARD_SIZE][BOARD_SIZE];// MOD

   // read the board
   char fileName[256];
   cout << "Enter source filename: ";
   cin  >> fileName;
   if (!read(board, fileName))
   {
      cout << "ERROR: Unable to open file \"" << fileName << "\"\n";
      return 1;
   }

   // display the board
   display(board);

   // write the board to a file
   cout << "Enter destination filename: ";
   cin  >> fileName;
   if (!write(board, fileName))
   {
      cout << "ERROR: Unable to open file \"" << fileName << "\"\n";
      return 1;
   }

   return 0;
}

/**************************************************************
 * READ
 * Read the board from the specified filename
 *************************************************************/
bool read(char board[][BOARD_SIZE][BOARD_SIZE], const char* fileName)// MOD
{
   assert(*fileName);

   // open the file
   ifstream fin(fileName);
   if (fin.fail())
      return false;

   // read 9 symbols, hopefully they are . X O
   for (int l = 0; l < BOARD_SIZE; l++) // NEW
      for (int r = 0; r < BOARD_SIZE; r++) // MOD
            for (int c = 0; c < BOARD_SIZE; c++) // MOD
            {
            fin >> board[l][r][c]; // MOD
            assert(!fin.fail());
            assert(board[l][r][c] == PLAYER_X || // MOD
                  board[l][r][c] == PLAYER_O ||// MOD
                  board[l][r][c] == BLANK);// MOD
            }

   // close the file
   fin.close();
   return true;
}

/**********************************************************
 * WRITE
 * Write to fileName the board data
 *********************************************************/
bool write(const char board[][BOARD_SIZE][BOARD_SIZE], const char* fileName)// MOD
{
   assert(fileName[0] != '\0');

   // open the file
   ofstream fout(fileName);
   if (fout.fail())
      return false;

   // write my 9 symbols
   for (int l = 0; l < BOARD_SIZE; l++) // NEW
      for (int r = 0; r < BOARD_SIZE; r++) // MOD
            for (int c = 0; c < BOARD_SIZE; c++)  // MOD
                  fout << board[r][c][l] << (c == 2 ? '\n' : ' ');// MOD

   // close it!
   fout.close();
   cout << "File written\n";
   return true;
}

/*******************************************************
 * DISPLAY
 * Display the contents the the screen
 *****************************************************/
void display(const char board[][BOARD_SIZE][BOARD_SIZE])// MOD
{
   // loop through each row
   for (int l = 0; l < BOARD_SIZE; l++) // NEW
   {
      for (int r = 0; r < BOARD_SIZE; r++)
      {
            // only the first row is not preceeded with the --+-- magic
            if (r != 0)
            cout << "---+---+---\n";

            // now, on each row, do the column stuff
            for (int c = 0; c < BOARD_SIZE; c++) // MOD
            {
            // display a space for the dot
            if (board[r][c][l] == BLANK) // MOD
                  cout << "   ";
            else
                  cout << " " << board[r][c][l] << " "; // MOD

            // end with a | or a newline
            cout << (c == 2 ? '\n' : '|');
            }
      }
      cout << endl; // NEW
   }

   // display who won
   if (didWin(board, PLAYER_X)) //MOD
      cout << PLAYER_X << " won!\n"; // MOD
   if (didWin(board, PLAYER_O)) // MOD
      cout << PLAYER_O << " won!\n"; // MOD
   
   return;
}

/********************************************
 * DID WIN
 * Did a given player (determined by the "turn"
 * variable) win the game?
 *******************************************/
bool didWin(const char board[][BOARD_SIZE][BOARD_SIZE], char turn)// MOD
{
   // vertical

   // horizontal

   // diagonal

   // 3d vertical

   // 3d horizontal

   // 3d diagonal
   return false;
}
