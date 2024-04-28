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


// Defines for max and min permitted dimensions
#define MAX_DIM 100
#define MIN_DIM 5

// Defines for the required autograder exit codes
#define EXIT_SUCCESS 0
#define EXIT_ARG_ERROR 1
#define EXIT_FILE_ERROR 2
#define EXIT_MAZE_ERROR 3
#define EXIT_OTHER_ERROR 100


typedef struct {

    int x;
    int y;

} Coord;


typedef struct {

    char symbol;
    int isWall;

} MazePiece;


// Instance created before openFile procedure done 

typedef struct {

    MazePiece **mazeMap;
    Coord startPosition;
    Coord endPosition;
    int rowDimension;
    int colDimension;

} MazeInfo;

#endif