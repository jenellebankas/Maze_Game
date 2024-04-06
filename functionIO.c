 /**
 * @file functionIO.c
 * @author Jenelle Bankas 
 * @brief Code for the maze game for COMP1921 Assignment 2
 */

#include "functionIO.h"
#include "defines.h"


/**
* @brief present prompt for move for the user 
*
* @param currentPos player's position at the time of function call 
* @param funcMazeInfo struct used for maze at time of gameplay  
*
* @return error value if input invalid or 0 if argument is valid 
*/

// called in the while loop which is controlled by variable produced from checkEnd() function
// obtains user input by using scanf 
// need to declare variable of type char to hold this 
// checks if user input is a valid character


int displayOptions(Coord *currentPos, MazeInfo *funcMazeInfo) {

    char initialInput[100];
    char userChoice;

    printf("\nPlease enter your next move: ");
    scanf("%s", initialInput);

    printf("\n");

    // error checking to see if no values entered or if incorrect values entered 

    if (initialInput[1] != '\0') {
        printf("Must use W/w, A/a, S/s, D/d or M/m, try again.\n");
        return EXIT_ARG_ERROR;
    } else if(strlen(initialInput) != 1) {
        printf("Must be valid character, try again.\n");
        return EXIT_ARG_ERROR;
    } else {
        strcpy(&userChoice, initialInput);
    }
    
        // will be changed when solution programmed, will return user choice 
    movement(toupper(userChoice), currentPos, funcMazeInfo);
    
    return 0;

}

/**
* @brief movements switch that calls the actual checkMovement() function
*
* @param userInput for the char to be processed obtained from displayOptions()
* @param currentPos user's current position within gameplay 
* @param funcMazeInfo struct storing maze values and information at gameplay 
*
* @return 0 once a valid value has been played or argument error if invalid value inputted by user 
*/


// process the string and use switch cases
// each switch case will call the moveUser() function 

int movement(char userInput, Coord *currentPos, MazeInfo *funcMazeInfo) {

    int checkValue = 0;
    // ensures that user input can be processed in one format 
    switch (userInput) {
        
        case 'W':

            checkValue = checkMoveValidity(toupper(userInput), currentPos, funcMazeInfo);

            if (checkValue == 1) {
                printf("Move not allowed, try again:\n");
                displayOptions(currentPos, funcMazeInfo);
                
            } else {
                currentPos->x--;
                printf("Piece moved successfully\n");
                return 0;
            }

            break;

        case 'A':

            checkValue = checkMoveValidity(toupper(userInput), currentPos, funcMazeInfo);

            if (checkValue == 1) {
                printf("Move not allowed, try again:\n");
                displayOptions(currentPos, funcMazeInfo);
        
            } else {
                currentPos->y--;
                printf("Piece moved successfully\n");
                return 0;
                
            }

            break;

        case 'S':

            checkValue = checkMoveValidity(toupper(userInput), currentPos, funcMazeInfo);

            if (checkValue == 1) {
                printf("Move not allowed, try again:\n");
                displayOptions(currentPos, funcMazeInfo);
            } else {
                currentPos->x++;
                printf("Piece moved successfully\n");
                return 0;
            }

            break;

        case 'D':

            checkValue = checkMoveValidity(toupper(userInput), currentPos, funcMazeInfo);

            if (checkValue == 1) {
                printf("Move not allowed, try again:\n");
                displayOptions(currentPos, funcMazeInfo);
            } else {
                currentPos->y++;
                printf("Piece moved successfully\n");
                return 0;
            }

            break;

        case 'M':

            displayMaze(currentPos, funcMazeInfo);
            return 0;
            break;

        default:
            printf("Must use W/w, A/a, S/s, D/d or M/m, try again.\n");
            return EXIT_ARG_ERROR;
    } 

    return 0;
}



/**
* @brief displays the maze when user input is M/m
*
* @param currentPos user current position to be used for displaying the 'X'
* @param funcMazeInfo used to print out rest of the maze at the time of usage 
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
            if (currentPos->x == i && currentPos->y == j) {
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
* @param input from tokeniseMaze() function
* @return 0 or 1 if the characters from the maze file are not valid
*/

// call this in the tokeniseMaze() function as each char is tokenised using a switch as a quick check 

int checkChar(char input) {

    // use switch case to check if value is valid 

    switch (input) {

        case '#':
            return 0;
            break;

        case ' ':
            return 0;
            break;

        case 'E':
            return 0;
            break;

        case 'S':
            return 0;
            break;

        default:
            return 1;
    }
    
    return 0;
}

/**
* @brief checks if move can be made
*  
* @param userInput is their chosen move
* @param currentPos to compare with intended move
* @param funcMazeInfo used to check if place intended to move to is a wall
* 
* @return 0 or 1 if the move can be carried out will produce an error if the move is not 
*/

// uses switch statement accesses array at attempted position and uses checkPieceType() to determine if move is allowed 
// calculates postion within array piece will move to then checks if piece is a wall through MAZEPIECE.iswall variable in struct 

int checkMoveValidity(char userInput, Coord *currentPos, MazeInfo *funcMazeInfo) {
    
    // need to also check if value out of bounds 

    
    // need a temporary value for checking movement and only need single value as only one value can change at a time 
    int tempPosx = 0;
    int tempPosy = 0;

    // ensures that user input can be processed in one format 
    switch (toupper(userInput)) {
        
        // -1 to y value 
        // see if that piece is a wall in the 2D struct 
        case 'W':

            tempPosx = currentPos->x - 1;
            tempPosy = currentPos->y;

            if (tempPosx < 0) {
                return 1;
            }

            if (funcMazeInfo->mazeMap[tempPosx][tempPosy].isWall) {
                return 1;
            } else {
                return 0;
            }
        
            break;

        case 'A':

            // -1 to x value
            // see if that piece is a wall in the 2D struct 

            tempPosx = currentPos->x;
            tempPosy = currentPos->y - 1;

            if (tempPosy < 0) {
                return 1;
            }

            if (funcMazeInfo->mazeMap[tempPosx][tempPosy].isWall) {
                return 1;
            } else {
                return 0;
            }

            break;

        case 'S':

            // +1 to y value
            // see if that piece is a wall in the 2D struct 

            
            tempPosx = currentPos->x + 1;
            tempPosy = currentPos->y;

            if (tempPosx > funcMazeInfo->rowDimension - 1) {
                return 1;
            }

            if (funcMazeInfo->mazeMap[tempPosx][tempPosy].isWall) {
                return 1;
            } else {
                return 0;
            }

            break;

        case 'D':

            // +1 to x value
            // see if that piece is a wall in the 2D struct 

            tempPosx = currentPos->x;
            tempPosy = currentPos->y + 1;

            if (tempPosy > funcMazeInfo->colDimension - 1) {
                return 1;
            }

            if (funcMazeInfo->mazeMap[tempPosx][tempPosy].isWall) {
                return 1;
            } else {
                return 0;
            }

            break;

        default:

            // might need to change to ensure that a potential error message is produced 
            return 2;

    } 

    return 0;
}


/**
* @brief checks if the end piece has been reached
*
* @param currentPos to check if player's position is same as end 
* @param funcMazeInfo for checking against player's current position 
* 
* @return 0 or 1 if the player is moving to the end piece 
*/

// compares users x and y values against values stored in MAZEINFO for end 
// returns a boolean 
// implemented as a while loop in the game play 
// should be called each time player moves 

int checkEnd(Coord *currentPos, MazeInfo *funcMazeInfo) {

    // using user's current position compare with x and y values for end position
    if ((currentPos->x == funcMazeInfo->endPosition.x) && (currentPos->y == funcMazeInfo->endPosition.y)) {
        return 1;
    } else {
        return 0;
    }
}

/**
* @brief displays success message 
*
*/

// function called when while loop exited to show success message and display maze one last time to user 

void displayEnd() {

    // shows success message 

    printf("\nCongratulations, you have reached the end of the maze!\n\n  _     _  _______  ___      ___        ______   _______  __    _  _______  __ \n | | _ | ||       ||   |    |   |      |      | |       ||  |  | ||       ||  |\n | || || ||    ___||   |    |   |      |  _    ||   _   ||   |_| ||    ___||  |\n |       ||   |___ |   |    |   |      | | |   ||  | |  ||       ||   |___ |  |\n |       ||    ___||   |___ |   |___   | |_|   ||  |_|  ||  _    ||    ___||__|\n |   _   ||   |___ |       ||       |  |       ||       || | |   ||   |___  __ \n |__| |__||_______||_______||_______|  |______| |_______||_|  |__||_______||__|\n" );
    
}

/**
* @brief frees all dynamically allocated memory for mazeInfo struct and other variables 
* 
* @param funcMazeInfo struct needed to be freed 
*
* @return 0 if completed and error value if not 
*/

// taken from: https://github.com/Scsabr/comp1921-struct-pointers/blob/main/code.c 

int freeMaze(MazeInfo *funcMazeInfo) {

    // always check it isn't already null - you will segfault.
    if (funcMazeInfo == NULL) {
        return 100;
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
    return 0;

}
