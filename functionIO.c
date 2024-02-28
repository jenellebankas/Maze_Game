#include "functionIO.h"
#include "defines.h"

/**
* @brief opening the maze file 
*
* @param filename from command arguments taken in from main()
*/

// opens the file for manipulation
// callse tokeniseMaze() function and checkDimensions()

void openFile(char filename[]) {
    
    // open the file specified by users argument and need to check if this is initialised correctly 
    // error checking for the filename and if it exists 
    
    FILE *file = fopen(filename, "r");

    // calls checkDimensions() function before proceding to ensure that time is not wasted

    // while loop for each line which can be processed by tokeniseMaze() which can be called here 
    fclose(file);


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
// might be easier to input user's 'X' into maze array when tokenising and have no S

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
* @brief movements switch that calls the actual moveUser() function
*
* @param userInput for the char to be processed obtained from displayOptions()
* @return 0 or 1 if error and prints message 
*/


// process the string and use switch cases
// each switch case will call the moveUser() function 

int movement(char userInput) {

    // ensures that user input can be processed in one format 
    switch (toupper(userInput)) {
        
        case 'W':

            checkMoveValidity(toupper(userInput));
            break;

        case 'A':

            checkMoveValidity(toupper(userInput));
            break;

        case 'S':

            checkMoveValidity(toupper(userInput));
            break;

        case 'D':

            checkMoveValidity(toupper(userInput));
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
* @brief displays the maze when user input is M/m
*/


// will need to access maze array to print it out 
// prints maze with user's 'X'


void displayMaze() {

}


/**
* @brief checks if valid char within the maze file
*
* @return 0 or 1 if the characters from the maze file are not valid
*/

// call this in the tokeniseMaze() function as each char is tokenised 
int checkChar(char input) {
    return 0;
}

/**
* @brief checks if move can be made  
* @param userInput is their chosen move and will 
* @return 0 or 1 if the move can be carried out will produce an error if the move is not 
*/

// uses switch statement accesses array at attempted position and uses checkPieceType() to determine if move is allowed 
// calculates postion within array piece will move to then checks if piece is a wall through MAZEPIECE.iswall variable in struct 

int checkMoveValidity(char userInput) {
    return 0;
}


/**
* @brief checks if the end piece has been reached
*
* @return 0 or 1 if the player is moving to the end piece 
*/

// compares users x and y values against values stored in MAZEINFO for end 
// returns a boolean 
// implemented as a while loop in the game play 
// should be called each time player moves 

int checkEnd() {

    // using user's current position compare with x and y values for end position
    return 0;
}

/**
* @brief displays success message and displays maze to the user 
*
*/

// function called when while loop exited to show success message and display maze one last time to user 
void displayEnd() {

    // calls displayMaze()
    // shows success message 
    
}
