 /**
 * @file functionIO.h
 * @author Jenelle Bankas 
 * @brief Code for the maze game for COMP1921 Assignment 2
 */


#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

// defines for max and min permitted dimensions
#define MAX_DIM 100
#define MIN_DIM 5

// defines for the required autograder exit codes
#define EXIT_SUCCESS 0
#define EXIT_ARG_ERROR 1
#define EXIT_FILE_ERROR 2
#define EXIT_MAZE_ERROR 3

#include "defines.h"

// forward definitions

void openFile(char filename[]);
int checkDimensions(char filename[]);
void tokeniseMaze(const char *line, char *mazeToken);
void displayOptions();
int movement(char userInput);
void displayMaze();
int checkEnd();
int checkMoveValidity(char userInput);
void displayEnd();


#endif