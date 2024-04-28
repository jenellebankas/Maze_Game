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

// Called in the while loop which is controlled by variable produced from checkEnd() function

int displayOptions(Coord *currentPos, MazeInfo *funcMazeInfo) {

    char initialInput[100];
    char userChoice;

    printf("\nPlease enter your next move: ");
    scanf("%s", initialInput);

    printf("\n");

    // Error checking to see if no values entered or if incorrect values entered 

    if (initialInput[1] != '\0') {
        printf("Must use W/w, A/a, S/s, D/d or M/m, try again.\n");
        return EXIT_ARG_ERROR;
    } else if(strlen(initialInput) != 1) {
        printf("Must be valid character, try again.\n");
        return EXIT_ARG_ERROR;
    } else {
        strcpy(&userChoice, initialInput);
    }
     
    movement(toupper(userChoice), currentPos, funcMazeInfo);
    
    return EXIT_SUCCESS;

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


int movement(char userInput, Coord *currentPos, MazeInfo *funcMazeInfo) {

    int checkValue = 0;

    // Ensures that user input can be processed in one format 
    switch (userInput) {
        
        case 'W':

            checkValue = checkMoveValidity(toupper(userInput), currentPos, funcMazeInfo);

            if (checkValue == 1) {
                printf("Move not allowed, try again:\n");
                displayOptions(currentPos, funcMazeInfo);
                
            } else {
                currentPos->x--;
                printf("Piece moved successfully\n");
                return EXIT_SUCCESS;
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
                return EXIT_SUCCESS;
                
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
                return EXIT_SUCCESS;
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
                return EXIT_SUCCESS;
            }

            break;

        case 'M':

            displayMaze(currentPos, funcMazeInfo);
            return EXIT_SUCCESS;
            break;

        default:
            printf("Must use W/w, A/a, S/s, D/d or M/m, try again.\n");
            return EXIT_ARG_ERROR;
    } 

    return EXIT_SUCCESS;
}



/**
* @brief displays the maze when user input is M/m
*
* @param currentPos user current position to be used for displaying the 'X'
* @param funcMazeInfo used to print out rest of the maze at the time of usage 
*/

void displayMaze(Coord *currentPos, MazeInfo *funcMazeInfo) {


    printf("\n");
    for (int i = 0; i < funcMazeInfo->rowDimension; i++) {
        for (int j = 0; j < funcMazeInfo->colDimension; j++) {
            if (currentPos->x == i && currentPos->y == j) {
                printf("X");
            } else {
                printf("%c", funcMazeInfo->mazeMap[i][j].symbol);
            }
        }

        // End each row with a newline.
        printf("\n");
    }
    
}


/**
* @brief checks if valid char within the maze file
*
* @param input from tokeniseMaze() function
* @return 0 or 1 if the characters from the maze file are not valid
*/

int checkChar(char input) {

    // Use switch case to check if value is valid 

    switch (input) {

        case '#':
            return EXIT_SUCCESS;
            break;

        case ' ':
            return EXIT_SUCCESS;
            break;

        case 'E':
            return EXIT_SUCCESS;
            break;

        case 'S':
            return EXIT_SUCCESS;
            break;

        default:
            return EXIT_MAZE_ERROR;
    }
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


int checkMoveValidity(char userInput, Coord *currentPos, MazeInfo *funcMazeInfo) {
    
    // Uses switch statement accesses array at attempted position and uses checkPieceType() to determine if move is allowed 

    // Need a temporary value for checking movement and only need single value as only one value can change at a time 
    int tempPosx = 0;
    int tempPosy = 0;


    switch (toupper(userInput)) {
        

        // See if that piece is a wall in the 2D struct 
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

            return EXIT_ARG_ERROR;

    } 
}


/**
* @brief checks if the end piece has been reached
*
* @param currentPos to check if player's position is same as end 
* @param funcMazeInfo for checking against player's current position 
* 
* @return 0 or 1 if the player is moving to the end piece 
*/


int checkEnd(Coord *currentPos, MazeInfo *funcMazeInfo) {

    // Using user's current position compare with x and y values for end position
    if ((currentPos->x == funcMazeInfo->endPosition.x) && (currentPos->y == funcMazeInfo->endPosition.y)) {
        return 1;
    } else {
        return 0;
    }
}

/**
* @brief displays success message 
*/


void displayEnd() {

    printf("\nCongratulations, you have reached the end of the maze!\n\n  _     _  _______  ___      ___        ______   _______  __    _  _______  __ \n | | _ | ||       ||   |    |   |      |      | |       ||  |  | ||       ||  |\n | || || ||    ___||   |    |   |      |  _    ||   _   ||   |_| ||    ___||  |\n |       ||   |___ |   |    |   |      | | |   ||  | |  ||       ||   |___ |  |\n |       ||    ___||   |___ |   |___   | |_|   ||  |_|  ||  _    ||    ___||__|\n |   _   ||   |___ |       ||       |  |       ||       || | |   ||   |___  __ \n |__| |__||_______||_______||_______|  |______| |_______||_|  |__||_______||__|\n\n" );
    
}

/**
* @brief frees all dynamically allocated memory for mazeInfo struct and other variables 
* 
* @param funcMazeInfo struct needed to be freed 
*
* @return 0 if completed and error value if not 
*/

// This program is adapted from an example provided on: https://github.com/Scsabr/comp1921-struct-pointers/blob/main/code.c 

int freeMaze(MazeInfo *funcMazeInfo) {

    // Checking that it is not NULL already 
    if (funcMazeInfo == NULL) {
        return EXIT_OTHER_ERROR;
    }

    if (funcMazeInfo->mazeMap != NULL) {
        for (int i = 0; i < funcMazeInfo->rowDimension; i++) {
            free(funcMazeInfo->mazeMap[i]);
            // Set each pointer to NULL after freeing
            funcMazeInfo->mazeMap[i] = NULL;
        }

        // Free array of row pointers
        free(funcMazeInfo->mazeMap);
        funcMazeInfo->mazeMap = NULL;
    }

    free(funcMazeInfo);
    return EXIT_SUCCESS;

}
