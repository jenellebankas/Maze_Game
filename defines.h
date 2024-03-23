 /**
 * @file defines.c
 * @author Jenelle Bankas 
 * @brief Code for the maze game for COMP1921 Assignment 2
 */


#ifndef DEFINES_FILE
#define DEFINES_FILE

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


// defines for max and min permitted dimensions
#define MAX_DIM 100
#define MIN_DIM 5

// defines for the required autograder exit codes
#define EXIT_SUCCESS 0
#define EXIT_ARG_ERROR 1
#define EXIT_FILE_ERROR 2
#define EXIT_MAZE_ERROR 3
#define EXIT_OTHER_ERROR

typedef struct {

    int x;
    int y;

} Coord;

// struct definition to use for pieces within maze
// loop through each piece from file and assign 
// each piece has a symbol, column, row
// boolean implemented as integers to check the type of piece so symbols don't have to be compared 
// will be defined as a 2D array later on in program see tokeniseMaze()
// user's position will also be defined as a piece but initialised separately 

typedef struct {

    Coord rowColPosition;
    char symbol;
    int isWall;

} MazePiece;


// struct for the maze 
// this struct will hold the data to of the start positions, end positions and dimensions of the maze 
// instance created before openFile procedure done and values set to 0 and then changed in tokeniseMaze function


typedef struct {

    MazePiece **mazeMap;
    Coord startPosition;
    Coord endPosition;
    int rowDimension;
    int colDimension;

} MazeInfo;

#endif