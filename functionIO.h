 /**
 * @file functionIO.h
 * @author Jenelle Bankas 
 * @brief Code for the maze game for COMP1921 Assignment 2
 */


#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H


#include "defines.h"

// forward definitions

int openFile(char filename[], MazeInfo *mazeInfo, MazePiece *funcMazePiece);
int checkRowDimensions(FILE *file);
int checkColDimensions(FILE *file, int rows);
int checkChar(char input);
int tokeniseMaze(FILE *file, MazeInfo *funcMazeInfo);
int displayOptions(Coord *currentPos, MazeInfo *funcMazeInfo);
int movement(char userInput, Coord *currentPos, MazeInfo *funcMazeInfo);
void displayMaze(Coord *currentPos, MazeInfo *funcMazeInfo);
int checkEnd(Coord *currentPos, MazeInfo *funcMazeInfo);
int checkMoveValidity(char userInput, Coord *currentPos, MazeInfo *funcMazeInfo);
void displayEnd();
int freeMaze(MazeInfo *funcMazeInfo);
int allocateMaze(MazeInfo *funcMazeInfo, MazePiece *funcMazePiece);

#endif