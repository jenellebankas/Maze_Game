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

    Coord startPosition;
    Coord endPosition;
    int rowDimension;
    int colDimension;

} MazeInfo;

#endif