#include "defines.h"
#include "functionIO.h"

// struct definition to use for pieces within maze
// loop through each piece from file and assign 
// each piece has a symbol, column, row
// boolean implemented as integers to check the type of piece 
// will be defined as a 2D array later on in program .see tokeniseMaze()

typedef struct {

    int rowPosition;
    int colPosition;
    char symbol;
    int isWall;
    int isStart;
    int isEnd;

}MAZEPIECE;


// struct for the maze 
// this struct will hold the data to of the start position, endposition, dimensions of the maze 


typedef struct {

    int startPositionX;
    int startPositionY;
    int endPositionX;
    int endPositionY;
    int userStartX;
    int userStartY;
    int rowDimension;
    int colDimension;

}MAZEINFO;

MAZEINFO maze;


// this is where the main gameplay will be processed
// declare the variable to store the maze pieces 

// how the game works will be described through a simple print statement

// functionality for this can be seen in the functionIO.c file 
// success message will then be shown 


int main(int argc, char* argv[]) {
    
    // error checking for command line arguments done first

    // the array will be declared after the file is opened but before it is tokenised 
    // dimensions will be checked using the checkDimensions() function and this will allow the size of the 2D array to be known 

    //openFile(argv[1]);

    // basic game explaination printed before the while loop starts 


    // the user will be prompted for an input this will be done within a while loop controlled by the checkEnd() function
    // the user then plays the game until they reach the end 
    // user option is read in from displayOptions()
    // this option is processed as seen in functionIO.c 
    



    return 0;
}


