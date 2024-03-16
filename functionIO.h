#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

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