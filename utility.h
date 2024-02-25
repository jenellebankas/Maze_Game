#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <stdio.h>

// forward definitions

int openFile(int argc, char* argv[]);
int tokeniseMaze(char* line);
int movement(char userInput);
int moveUser(char movementChar);
int checkDimensions();
void displayMaze();
char checkPieceType();


#endif