 /**
 * @file maze.c
 * @author Jenelle Bankas 
 * @brief Code for the maze game for COMP1921 Assignment 2
 */


#include "defines.h"
#include "functionIO.h"


int main(int argc, char* argv[]) {

    // uncomment coordinate variable once done 

    MazeInfo *mazeInfo = malloc(sizeof(MazeInfo));
    MazePiece *mazePiece = malloc(sizeof(MazePiece));
    Coord *playerCoord = malloc(sizeof(Coord));
    

    // error checking for command line arguments done first
    // error checking for an empty file done before entering the loop so in the openFile() function

    // need to check number of arguments entered 
    if (argc > 2) {
        printf("Too many arguments\n");
        exit(1);
        return 3;
    } else if (argc < 2){
        printf("Usage: ./maze <filename>\n");
        exit(1);
        return 3;
    } else {
        // basic game explaination printed before the while loop starts 
        printf("\nNavigate through the maze by:\n\nW/w - Up\nA/a - Right\nS/s - Down\nD/d - Left\nIf you want to see your current position within the maze please enter M/m.\nA congratulatory message once you complete the maze, please note that your maze may not always be solvable!\n\n");
    }


    // program not making to this line so something wrong above??
    //stuck in infinite loop?

    int fileOpens = openFile(argv[1], mazeInfo, mazePiece);


    if (fileOpens != 0) {
        return fileOpens;
        exit(1);
    }

    
    playerCoord->x = mazeInfo->startPosition.x;
    printf("%d\n", mazeInfo->startPosition.x);
    playerCoord->y = mazeInfo->startPosition.y;
    printf("%d\n", mazeInfo->startPosition.y);

    // the user will be prompted for an input this will be done within a while loop controlled by the checkEnd() function
    // the user then plays the game until they reach the end 
    // user option is read in from displayOptions()
    // this option is processed as seen in functionIO.c 

    // once while loop is exited, displayEnd() is called to show the user a success message 


    while (!checkEnd(playerCoord, mazeInfo)) {

        displayOptions(playerCoord, mazeInfo);
        
    }

    displayEnd(playerCoord, mazeInfo);

    // free memory 
    // return correct value 

    freeMaze(mazeInfo);
    exit(EXIT_SUCCESS);
    return 0;
    
}



