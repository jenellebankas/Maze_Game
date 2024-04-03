#include "defines.h"
#include "functionIO.h"

/**
* @brief opening the maze file 
*
* @param filename from command arguments taken in from main()
*/

// opens the file for manipulation
// calls tokeniseMaze() function and checkDimensions()


int openFile(char filename[], MazeInfo *funcMazeInfo, MazePiece *funcMazePiece) {
    
    // open the file specified by users argument and need to check if this is initialised correctly 
    // error checking for the filename and if it exists 
    // error checking for the contents of the file, taken from: https://stackoverflow.com/questions/13566082/how-to-check-if-a-file-has-content-or-not-using-c
    
    long size;
    int check;

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("File does not exist\n");
        return 2;
    } 
    
    fseek(file, 0, SEEK_END);
    size = ftell(file);

    
    if (size == 0) {
        printf("File is empty\n");
        fclose(file);
        return 2;
    } else {
        printf("File loaded successfully\n");
        printf("\n");
        fseek(file, 0, SEEK_SET);
    }
    

    // calls checkDimensions() function before proceding to ensure that time is not wasted

    int rowLength = checkRowDimensions(file);
    if (rowLength < 5) {
        printf("Maze dimensions not valid\n");
        return 3;
    }

    int colLength = checkColDimensions(file, rowLength);
    if (colLength < 5) {
        printf("Maze dimensions not valid\n");
        return 3;
    }

    funcMazeInfo->rowDimension = rowLength;
    funcMazeInfo->colDimension = colLength;

    check = allocateMaze(funcMazeInfo, funcMazePiece);
    
    if (check != 0) {
        fclose(file);
        return check;
    }
    
    check = tokeniseMaze(file, funcMazeInfo);


    if (check != 0) {
        fclose(file);
        return check;
    }
    
    fclose(file);
    return 0;

}

// taken from: https://github.com/Scsabr/comp1921-struct-pointers/blob/main/code.c 

int allocateMaze(MazeInfo *funcMazeInfo, MazePiece *funcMazePiece) {

    funcMazeInfo->mazeMap = malloc(funcMazeInfo->rowDimension * sizeof(MazePiece));
    for (int i = 0; i < funcMazeInfo->rowDimension; i++) {
        funcMazeInfo->mazeMap[i] = malloc(funcMazeInfo->colDimension * sizeof(MazePiece));
    }

    if (!funcMazeInfo->mazeMap) {
        printf("Error: malloc failed\n");
        return 3;
    }

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


int checkRowDimensions(FILE *file) {

    // determine buffer size and check all lines same length 
    // idea taken from: https://stackoverflow.com/questions/2137156/finding-line-size-of-each-row-in-a-text-file#:~:text=If%20you%20already%20know%20that,strlen()%20on%20each%20substring.

    int buffer = 1000;
    char line[buffer];
    int counter = 0;

    while (fgets(line, buffer, file)) {
        counter++;
    } 
    
    if (counter < 5 || counter > 100) {
        fclose(file);
        return 3;
    }

    return counter;  
}


/**
* @brief process characters within the maze file and sort into the given array
*
* @param file from the user 
* @return 0 or 1 if error occurs when opening/tokenising file and prints error message 
*/


int checkColDimensions(FILE *file, int rows) {

    fseek(file, 0, SEEK_SET);


    // determine buffer size and check all lines same length 
    // idea taken from: https://stackoverflow.com/questions/2137156/finding-line-size-of-each-row-in-a-text-file#:~:text=If%20you%20already%20know%20that,strlen()%20on%20each%20substring.
    
    int expectedLineLength = 0; 
    int i = 0;
    char d;
    char c;

    while ((d = fgetc(file)) != '\n') {
        expectedLineLength++;
    }

    fseek(file, 0, SEEK_SET);

    
    for (int j = 0; j < rows; j++) {
        i = 0; 

        while ((c = fgetc(file)) != '\n') {
            i++; 

            int check = checkChar(c);
            if (check != 0) {
                printf("Data in file is not valid\n");
                return 1;
            }
        }

        if (i != expectedLineLength) {
            return 3;
        } 
        
    }
    

    if (expectedLineLength < 5 || expectedLineLength > 100) {
        return 3;
    }

    return expectedLineLength;
}


/**
* @brief input values for rows and columns and changes MAZEINFO instance of struct and adds to MAZEPIECE 2D array 
* @param line is used to be iterated over and characters tokenised 
*/


// counts the number of start and end pieces and produces error if there are too many or none 

// fgetc() taken from: https://stackoverflow.com/questions/4179671/read-in-text-file-1-character-at-a-time-using-c use this in this function

int tokeniseMaze(FILE *file, MazeInfo *funcMazeInfo) {

    fseek(file, 0, SEEK_SET);

    char c;
    int hasStart = 0;
    int hasEnd = 0;
    
    
    for (int i = 0; i < funcMazeInfo->rowDimension; i++) {
        for (int j = 0; j < funcMazeInfo->colDimension + 1; j++) {

            c = fgetc(file);

            if (c == '\n') {
                continue;
            } else {
                strcpy(&funcMazeInfo->mazeMap[i][j].symbol, &c);  
                funcMazeInfo->mazeMap[i][j].isWall = 0;

                if (c == 'S') {
                    funcMazeInfo->startPosition.x = i;
                    funcMazeInfo->startPosition.y = j;
                    
                    hasStart = 1;
                } else if (c == 'E') {
                    funcMazeInfo->endPosition.x = i;
                    funcMazeInfo->endPosition.y = j;
                    hasEnd = 1;
                } else if (c == '#') {
                    funcMazeInfo->mazeMap[i][j].isWall = 1;
                }
            }
        }
    }
    

    if (hasStart == 0 || hasEnd == 0) {
        printf("Data in file is not valid\n");
        return 3;
    }

    if (hasStart > 1 || hasEnd > 1) {
        printf("Data in file is not valid\n");
        return 3;
    }
    
    return 0;

}