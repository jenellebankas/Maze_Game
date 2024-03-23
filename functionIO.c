 /**
 * @file functionIO.c
 * @author Jenelle Bankas 
 * @brief Code for the maze game for COMP1921 Assignment 2
 */

#include "functionIO.h"
#include "defines.h"


/**
* @brief present prompt for move for the user  
* @return the users char of choice 
*/

// called in the while loop which is controlled by variable produced from checkEnd() function
// obtains user input by using scanf 
// need to declare variable of type char to hold this 
// checks if user input is a valid character


void displayOptions(Coord *currentPos, MazeInfo *funcMazeInfo) {

    char userChoice;

    printf("Please enter your next move: ");
    int checkChar = scanf("%s", &userChoice);
    

    // error checking to see if no values entered or if incorrect values entered 

    if (toupper(userChoice) != 'W' || 'A' || 'S' || 'D'|| 'M') {
        printf("Must use W/w, A/a, S/s, D/d or M/m, try again:\n");
        
    } else {
        // will be changed when solution programmed, will return user choice 
        movement(toupper(userChoice), currentPos, funcMazeInfo);
    }  

    if (checkChar != 1) {
        printf("Must use W/w, A/a, S/s, D/d or M/m, try again:\n");
        
    } else {
        // will be changed when solution programmed, will return user choice 
        movement(toupper(userChoice), currentPos, funcMazeInfo);
    }  
}

/**
* @brief movements switch that calls the actual moveUser() function
*
* @param userInput for the char to be processed obtained from displayOptions()
* @return 0 or 1 if error and prints message 
*/


// process the string and use switch cases
// each switch case will call the moveUser() function 

int movement(char userInput, Coord *currentPos, MazeInfo *funcMazeInfo) {

    // ensures that user input can be processed in one format 
    switch (userInput) {
        
        case 'W':

            checkMoveValidity(toupper(userInput), currentPos, funcMazeInfo);
            break;

        case 'A':

            checkMoveValidity(toupper(userInput), currentPos, funcMazeInfo);
            break;

        case 'S':

            checkMoveValidity(toupper(userInput), currentPos, funcMazeInfo);
            break;

        case 'D':

            checkMoveValidity(toupper(userInput), currentPos, funcMazeInfo);
            break;

        case 'M':

            displayMaze(currentPos, funcMazeInfo);
            break;

        default:
            printf("Must use W/w, A/a, S/s, D/d or M/m, try again:\n");
    } 

    return 0;
}



/**
* @brief displays the maze when user input is M/m
*/


// will need to access maze array to print it out 
// prints maze with user's 'X'


void displayMaze(Coord *currentPos, MazeInfo *funcMazeInfo) {

    
    // make sure we have a leading newline..
    printf("\n");
    for (int i = 0; i < funcMazeInfo->rowDimension; i++) {
        for (int j = 0; j < funcMazeInfo->colDimension; j++) {
            // decide whether player is on this spot or not
            // change this bit for my for my implementation
            if (currentPos->x == j && currentPos->y == i) {
                printf("X");
            } else {
                printf("%c", funcMazeInfo->mazeMap[i][j].symbol);
            }
        }
        // end each row with a newline.
        printf("\n");
    }
    

}


/**
* @brief checks if valid char within the maze file
*
* @return 0 or 1 if the characters from the maze file are not valid
*/

// call this in the tokeniseMaze() function as each char is tokenised 
int checkChar(char input) {

    //char validMazeCharacters[4] = {'#', 'S', 'E', ' '};

    //if () {

    //}
    
    return 0;
}

/**
* @brief checks if move can be made  
* @param userInput is their chosen move and will 
* @return 0 or 1 if the move can be carried out will produce an error if the move is not 
*/

// uses switch statement accesses array at attempted position and uses checkPieceType() to determine if move is allowed 
// calculates postion within array piece will move to then checks if piece is a wall through MAZEPIECE.iswall variable in struct 

int checkMoveValidity(char userInput, Coord *currentPos, MazeInfo *funcMazeInfo) {

    // ensures that user input can be processed in one format 
    switch (toupper(userInput)) {
        
        case 'W':

            // + 1 to y value 
            // see if that piece is a wall in the 2D struct 

            break;

        case 'A':

            // -1 to x value
            // see if that piece is a wall in the 2D struct 


            break;

        case 'S':

            // -1 to y value
            // see if that piece is a wall in the 2D struct 

            break;

        case 'D':

            // +1 to x value
            // see if that piece is a wall in the 2D struct 

            break;

        default:

            // might need to change to ensure that a potential error message is produced 
            return 0;

    } 

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

int checkEnd(Coord *currentPos, MazeInfo *funcMazeInfo) {

    // using user's current position compare with x and y values for end position
    return 0;
}

/**
* @brief displays success message and displays maze to the user 
*
*/

// function called when while loop exited to show success message and display maze one last time to user 

void displayEnd(Coord *currentPos, MazeInfo *funcMazeInfo) {

    // calls displayMaze()
    // shows success message 

    displayMaze(currentPos, funcMazeInfo);
    printf("Congratulations, you have reached the end of the maze!\n\n _     _  _______  ___      ___        ______   _______  __    _  _______  __ \n | | _ | ||       ||   |    |   |      |      | |       ||  |  | ||       ||  |\n | || || ||    ___||   |    |   |      |  _    ||   _   ||   |_| ||    ___||  |\n |       ||   |___ |   |    |   |      | | |   ||  | |  ||       ||   |___ |  |\n |       ||    ___||   |___ |   |___   | |_|   ||  |_|  ||  _    ||    ___||__|\n |   _   ||   |___ |       ||       |  |       ||       || | |   ||   |___  __ \n |__| |__||_______||_______||_______|  |______| |_______||_|  |__||_______||__|\n" );
    
}

// taken from: https://github.com/Scsabr/comp1921-struct-pointers/blob/main/code.c 

void freeMaze(MazeInfo *funcMazeInfo) {

    // always check it isn't already null - you will segfault.
    if (funcMazeInfo == NULL) {
        return EXIT_OTHER_ERROR;
    }

    if (funcMazeInfo->mazeMap != NULL) {
        for (int i = 0; i < funcMazeInfo->rowDimension; i++) {
            free(funcMazeInfo->mazeMap[i]);
            // we set each pointer to NULL after freeing
            funcMazeInfo->mazeMap[i] = NULL;
        }

        // Free array of row pointers
        free(funcMazeInfo->mazeMap);
        funcMazeInfo->mazeMap = NULL;
    }

    free(funcMazeInfo);

}
