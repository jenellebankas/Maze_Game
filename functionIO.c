#include "functionIO.h"
#include "defines.h"

// function for opening the file 
// also gain row and column dimension variable to be used later, to be input into struct 
// while loop implemented with fgets() function and a counter within to count the number of rows 
// error checking for the filename and the number of arguments 
// calls tokeniseMaze function
// returns error if row or column length not within bounds 

void openFile(int argc, char* argv[]) {
    
    //FILE *file = fopen(argv[1], "r");

}

// function to process characters within the maze file and sort into the given array
// also gain column dimension variable to be used later, to be input into struct
// return columnDimension
// has local variable 
// this will be returned from the call 
// this will be called in the openFile function
// error checking for the different types of char entered and if they are valid 
// counts the number of start and end pieces and produces error if there are too many 
// need to store user position same as where S is present 
// user's position must be equated to where the S 

int tokeniseMaze(char* line) {

    return 0;
}

// function to present prompt for move for the user  
// called in the while loop which is controlled by variable produced from checkEnd() function

void displayOptions() {
    
}

// function for movements 
// process the string and use switch cases
// each switch case will call the moveUser() function 


int movement(char userInput) {

    return 0;
}

// function to update position of user and replace prior position with ' '
// adds or subtracts from user piece rowPosition and colPosition
// dependent on input from the user
// gives "Piece moved succesfully"
// calls the checkMoveValidity and return "Move not allowed, try again:" if move not allowed

int moveUser() { 

    return 0;
}

// function to display the maze 
// does not need to take in any parameters 
// will need to access maze array to print it out 
// prints maze with user's 'X'

void displayMaze() {

}


// function that returns piece type 
// for checking if move is valid or not 
// returns 0 or 1 depending on what piece variable is checked
// called when user attempts a move to find out type of piece in square intending to move to 
// parameter is MAZEPIECE.symbol from the position within the 2D array 

int checkPieceType(char symbol) {

    return 0;
}

// checks if the end piece has been reached
// compares users x and y values against values stored in MAZEINFO
// returns a boolean 
// implemented as a while loop in the game play 

int checkEnd() {
    return 0;
}

// checks if move can be made 
// returns 0 or 1 if can be done 

int checkMoveValidity() {
    return 0;
}