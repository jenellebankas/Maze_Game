#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "defines.h"

// forward definitions

void openFile(int argc, char* argv[]);
int tokeniseMaze(char* line);
void displayOptions();
int movement(char userInput);
int moveUser();
void displayMaze();
int checkPieceType(char symbol);
int checkEnd();
int checkMoveValidity();


#endif