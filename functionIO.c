#include "functionIO.h"
#include "defines.h"

/**
* @brief opening the maze file 
*
* @param filename from command arguments taken in from main()
* @return 0 or 1 if error occurs when opening/tokenising file and prints error message 
*/

// opens the file for manipulation
// callse tokeniseMaze() function and checkDimensions()

int openFile(char filename[]) {
    
    // open the file specified by users argument and need to check if this is initialised correctly 
    // error checking for the filename and the number of arguments 
    FILE *file = fopen(filename, "r");

    fclose(file);

    // temp return until function programmed
    return 0;

}


/**
* @brief process characters within the maze file and sort into the given array
*
* @param filename from the user 
* @return 0 or 1 if error occurs when opening/tokenising file and prints error message 
*/

// error checking for the uniform row length 
// error checking for uniform column length 


int checkDimensions(char filename[]) {

    // variables declared here to keep track of expected row and column length based off of first line needed

    // open the file to allow dimensions to be checked 
    FILE *file = fopen(filename, "r");


    // counts individual characters in the row
    // has a count
    // index through the line 
    // while the char is not \n
    

    // error checking done before this declaration 
    // if no error assignment of MAZEINFO.rowDimension and MAZEINFO.colDimension
    // dynamically allocate memory for the size of the 2D array 

    
    fclose(file);
    // placeholder return until function is fully programmed 
    return 0;
    

}

/**
* @brief input values for rows and columns and changes MAZEINFO instance of struct and adds to MAZEPIECE 2D array 
* @param line is used to be iterated over and characters tokenised 
*/



// error checking for the different types of char entered and if they are valid 

// counts the number of start and end pieces and produces error if there are too many or none 
// need to store user position same as where S is present 
// user's position must be equated to where the S 

// gain row and column dimension (column returned from tokenise record call) to be used later, to be input into struct 
// fgetc() taken from: https://stackoverflow.com/questions/4179671/read-in-text-file-1-character-at-a-time-using-c use this in this function

void tokeniseMaze(const char *line) {

}

/**
* @brief present prompt for move for the user  
* @return the users char of choice 
*/

// called in the while loop which is controlled by variable produced from checkEnd() function
// obtains user input by using scanf 
// need to declare variable of type char to hold this 
// checks if user input is a valid character


char displayOptions() {

    printf("Please enter your next move: ");
    
    // will be changed when solution programmed, will return user choice 
    return 'a';
}

/**
* @brief 
*
* @param userInput
* @return 0 or 1 if error 
*/


// function for movements 
// process the string and use switch cases
// each switch case will call the moveUser() function 

int movement(char userInput) {

    // ensures that user input can be processed in one format 
    switch (toupper(userInput)) {
        
        case 'W':

            moveUser();
            break;

        case 'A':

            moveUser();
            break;

        case 'S':

            moveUser();
            break;

        case 'D':

            moveUser();
            break;

        case 'M':

            displayMaze();
            break;

        default:
            printf("Must use W/w, A/a, S/s, D/d or M/m");
    } 

    return 0;
}


/**
* @brief 
*
* @return 0 if move is possible or 1 if error occurs and prints error message 
*/

// function to update position of user and replace prior position with ' '
// adds or subtracts from user piece rowPosition and colPosition
// dependent on input from the user
// gives "Piece moved succesfully"
// calls the checkMoveValidity and return "Move not allowed, try again:" if move not allowed


int moveUser() { 

    return 0;
}


/**
* @brief displays the maze when user input is M/m
*/


// will need to access maze array to print it out 
// prints maze with user's 'X'

void displayMaze() {

}


/**
* @brief checks if valid char within the maze file
*
* @return 0 or 1 
*/



int checkChar(char input) {
    return 0;
}

/**
* @brief 
*
* @param command line 
* @param 
* @return 0 or 1 if error occurs 
*/

// function that returns piece type 
// for checking if move is valid or not 
// returns 0 or 1 depending on what piece variable is checked
// called when user attempts a move to find out type of piece in square intending to move to 
// parameter is MAZEPIECE.symbol from the position within the 2D array 

int checkPieceType(char symbol) {

    return 0;
}


/**
* @brief checks if the end piece has been reached
*
* @return 0 or 1 
*/

// compares users x and y values against values stored in MAZEINFO for end 
// returns a boolean 
// implemented as a while loop in the game play 
// should be called each time player moves 

int checkEnd() {
    return 0;
}


/**
* @brief 
*
* @return 0 or 1 
*/

// checks if move can be made 
// uses switch statement accesses array at attempted position and uses checkPieceType() to determine if move is allowed 


int checkMoveValidity(char userInput) {
    return 0;
}