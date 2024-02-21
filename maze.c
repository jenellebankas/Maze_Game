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
    int isStart
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

}maze;

// need to make an array of structs for the maze itself 

char maze_piece mazeArray[maze.rowDimension][maze.colDimension];

int main() {


}

// function for opening the file 
// also gain row dimension variable to be used later, to be input into struct 

void openFile(int argc, *char argv[]) {

}

// function to process characters within the maze file and sort into the given array
// also gain column dimension variable to be used later, to be input into struct

void tokeniseMaze(char *line) {

}

// function for movements 
// process the string and use switch cases

int movement(char userInput) {

}

// function to update position of user 

int moveUser() { 

}

// function to check maze dimensions
// boolean returning 0 or 1 
// use openfile

int checkDimensions() {

}

// function that return piece type 
// for checking if move is valid or not 
char checkPieceType() {

}

// function to display the maze 
// does not need to take in any parameters 
// will need to access maze array to print it out 

void displayMaze() {

}

