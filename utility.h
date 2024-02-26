#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "defines.h"

// forward definitions

int openFile(int argc, char* argv[]);
int tokeniseMaze(char* line);
int movement(char userInput);
int moveUser();
int checkDimensions();
void displayMaze();
char checkPieceType();


#endif