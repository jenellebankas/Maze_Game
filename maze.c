#include "defines.h"
#include "utility.h"

// struct definition to use for pieces within maze
// loop through each piece from file and assign 
// each piece has a symbol, column, row
// boolean implemented as integers to check the type of piece 

typedef struct {

    int rowPosition;
    int colPosition;
    char symbol;
    int isWall;
    int isStart;
    int isEnd;

}maze_piece;


// struct for the maze 
// this struct will hold the data to of the start position, endposition, dimensions of the maze 

typedef struct {

    int startPositionX;
    int startPositionY;
    int endPositionX;
    int endPositionY;
    int rowDimension;
    int colDimension;

}mazeInfo;


// this is where the main gameplay will be processed
// declare the variable to store the maze pieces 

int main() {

    return 0;
}


