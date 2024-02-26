#include "utility.h"
#include "defines.h"

// function for opening the file 
// also gain row and column dimension variable to be used later, to be input into struct 
// the row dimension should be returned when called 
// while loop implemented with fgets() function and a counter within to count the number of rows 
// error checking for the filename and the number of arguments 

int openFile(int argc, char* argv[]) {

    return 0;
}

// function to process characters within the maze file and sort into the given array
// also gain column dimension variable to be used later, to be input into struct
// this will be returned from the call 
// this will be called in the openFile function
// error checking for the different types of char entered and if they are valid 
// need to store user position same as where S is present 

int tokeniseMaze(char* line) {

    return 0;
}

// function to present options to user and explain the game 
// simple function to show options for the maze 

void displayOptions() {
    
}

// function for movements 
// process the string and use switch cases
// each switch case will call the moveUser() function 


int movement(char userInput) {

    return 0;
}

// function to update position of user 
// adds or subtracts from user piece rowPosition and colPosition
// dependent on input from the user

int moveUser() { 

    return 0;
}

// function to check maze dimensions
// boolean returning 0 or 1 
//????

int checkDimensions() {

    return 0;
}

int checkSymbol() {

    return 0;
}

// function that returns piece type 
// for checking if move is valid or not 

char checkPieceType() {

    return '\0';

}

int checkStartEnd() {
    return 0;
}

int checkMoveValidity() {
    return 0;
}

// function to display the maze 
// does not need to take in any parameters 
// will need to access maze array to print it out 

void displayMaze() {

}

- **`openFile(int argc, char* argv[])`**
    - Used to open the file and also gain the dimensions required by the program 
    - Should return these values which can be used in the struct for mazeInfo
- **`tokeniseMaze(char* line)`**
    - Used to sort each piece info into an 2D array of mazePiece structs defined 
- **`movement(char userInput)`**
    - Processes user input and implements their chosen move
- **`moveUser()`**
    - Carries out the movement by adjustment of user player 'X' x and y values
- **`displayMaze()`**
    - Displays maze current state with the user's 'X' displayed on the board
- **`checkPieceType()`**
    - Returns the type of piece to determine whether a move can be carried out 
    
