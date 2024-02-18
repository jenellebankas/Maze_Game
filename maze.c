#include <stdio.h>
#include "utility.h"

// struct definition to use for pieces within maze
// loop through each piece from file and assign 
// each piece has a symbol, column, row

typedef struct {

    int row_position;
    int col_position;
    char symbol;

}maze_piece;


// struct for the maze 
typedef struct {

    int startPosition;
    int endPosition;
    int row_dimension;
    int col_dimension;
    maze_piece maze_array[];

}maze;

// forward definitions

void openFile(int argc, *char argv[]);
int movement(char userInput);

int main() {


}

// function for opening the file 

void openFile(int argc, *char argv[]) {

}

// function for movements 
// process the string and use switch case??

int movement(char userInput) {

}

// function to check maze dimensions
// boolean returning 0 or 1 
// use openfile

int checkDimensions() {

}

// function to display the maze 

void displayMaze() {

}

// function to 