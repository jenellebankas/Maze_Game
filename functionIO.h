 /**
 * @file functionIO.h
 * @author Jenelle Bankas 
 * @brief Code for the maze game for COMP1921 Assignment 2
 */


#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H


#include "defines.h"

// forward definitions

void openFile(char filename[], MazeInfo *mazeInfo);
int checkRowDimensions(FILE *file);
int checkColDimensions(FILE *file);
int tokeniseMaze(const char *line, char *mazeToken);
int displayOptions(Coord *currentPos, MazeInfo *funcMazeInfo);
int movement(char userInput, Coord *currentPos, MazeInfo *funcMazeInfo);
void displayMaze(Coord *currentPos, MazeInfo *funcMazeInfo);
int checkEnd(Coord *currentPos, MazeInfo *funcMazeInfo);
int checkMoveValidity(char userInput, Coord *currentPos, MazeInfo *funcMazeInfo);
void displayEnd(Coord *currentPos, MazeInfo *funcMazeInfo);
int freeMaze(MazeInfo *funcMazeInfo);
int allocateMaze(MazeInfo *funcMazeInfo);




#endif