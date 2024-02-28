#include "defines.h"
#include "functionIO.h"

// struct definition to use for pieces within maze
// loop through each piece from file and assign 
// each piece has a symbol, column, row
// boolean implemented as integers to check the type of piece so symbols don't have to be compared 
// will be defined as a 2D array later on in program see tokeniseMaze()
// user's position will also be defined as a piece but initialised separately 

typedef struct {

    int rowPosition;
    int colPosition;
    char symbol;
    int isWall;

}MAZEPIECE;


// struct for the maze 
// this struct will hold the data to of the start positions, end positions and dimensions of the maze 
// instance created before openFile procedure done and values set to 0 and then changed in tokeniseMaze function


typedef struct {

    int startPositionX;
    int startPositionY;
    int endPositionX;
    int endPositionY;
    int rowDimension;
    int colDimension;

}MAZEINFO;



int main(int argc, char* argv[]) {


    // how the game works will be described through a simple print statement
    
    // error checking for command line arguments done first
    // error checking for an empty file done before entering the loop so in the openFile() function

    // the array will be declared after the file is opened but before it is tokenised 
    // dimensions will be checked using the checkDimensions() function and this will allow the size of the 2D array to be known 

    //openFile(argv[1]);

    // basic game explaination printed before the while loop starts 


    // the user will be prompted for an input this will be done within a while loop controlled by the checkEnd() function
    // the user then plays the game until they reach the end 
    // user option is read in from displayOptions()
    // this option is processed as seen in functionIO.c 

    // once while loop is exited, displayEnd() is called to show the user a success message 
    

    return 0;
}


