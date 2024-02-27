#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "defines.h"

// forward definitions

int openFile(char filename[]);
int checkDimensions(char filename[]);
int tokeniseMaze(char filename[]);
void displayOptions();
int movement(char userInput);
int moveUser();
void displayMaze();
int checkPieceType(char symbol);
int checkEnd();
int checkMoveValidity();


#endif