#include <stdio.h>
#include "utility.h"

// struct definition to use for pieces within maze
// loop through each piece from file and assign 
// each piece has a symbol, column, row
// boolean implemented as integers to check the type of piece 

typedef struct {

    int rowPosition;
    int colPosition;
    char symbol;
    int isWall;
    int isStart;
    int isEnd;

}maze_piece;


// struct for the maze 
// this struct will hold the data to of the start position, endposition, dimensions of the maze 

typedef struct {

    int startPositionX;
    int startPositionY;
    int endPositionX;
    int endPositionY;
    int rowDimension;
    int colDimension;

}mazeInfo;


// this is where the main gameplay will be processed
// declare the variable to store the maze pieces 

int main() {

    return 0;
}

// function for opening the file 
// also gain row and column dimension variable to be used later, to be input into struct 
// the row dimension should be returned when called 

int openFile(int argc, char* argv[]) {

    return 0;
}

// function to process characters within the maze file and sort into the given array
// also gain column dimension variable to be used later, to be input into struct
// this will be returned from the call 

int tokeniseMaze(char* line) {

    return 0;
}

// function to present options to user and explain the game 

void displayOptions() {
    
}

// function for movements 
// process the string and use switch cases

int movement(char userInput) {

    return 0;
}

// function to update position of user 
// adds or subtracts from user piece rowPosition and colPosition
// dependent on input from the user 
int moveUser(char movementChar) { 

    return 0;
}

// function to check maze dimensions
// boolean returning 0 or 1 
// use openfile

int checkDimensions() {

    return 0;
}

// function that returns piece type 
// for checking if move is valid or not 

char checkPieceType() {

    return '\0';

}

// function to display the maze 
// does not need to take in any parameters 
// will need to access maze array to print it out 

void displayMaze() {

}

