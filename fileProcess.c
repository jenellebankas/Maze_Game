#include "defines.h"
#include "functionIO.h"

/**
* @brief opening the maze file 
*
* @param filename from command arguments taken in from main()
* @param funcMazeInfo declared in main() and memory allocated in the function
* @param funcMazePiece declared in main() and used for memory allocation for maze struct 
* @returns 0 when file opens and data, dimensions are valid and returns error value depending on what causes the error 
*/


int openFile(char filename[], MazeInfo *funcMazeInfo, MazePiece *funcMazePiece) {


    // Error checking for the contents of the file, this program is adapted from an example provided on: https://stackoverflow.com/questions/13566082/how-to-check-if-a-file-has-content-or-not-using-c
    
    long size;
    int allocateCheck;
    int tokenCheck;

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("File does not exist\n");
        return EXIT_FILE_ERROR;
    } 
    
    fseek(file, 0, SEEK_END);
    size = ftell(file);

    
    if (size == 0) {
        printf("File is empty\n");
        fclose(file);
        return EXIT_FILE_ERROR;
    } else {
        printf("File loaded successfully\n");
        printf("\n");
        fseek(file, 0, SEEK_SET);
    }
    

    // Calls checkDimensions() function before proceding to ensure that time is not wasted

    int rowLength = checkRowDimensions(file);
    if (rowLength == EXIT_MAZE_ERROR) {
        return EXIT_MAZE_ERROR;
    }

    int colLength = checkColDimensions(file, rowLength);
    if (colLength == EXIT_MAZE_ERROR) {
        fclose(file);
        return EXIT_MAZE_ERROR;
    }

    funcMazeInfo->rowDimension = rowLength;
    funcMazeInfo->colDimension = colLength;

    allocateCheck = allocateMaze(funcMazeInfo, funcMazePiece);
    
    if (allocateCheck == EXIT_MAZE_ERROR) {
        fclose(file);
        return EXIT_MAZE_ERROR;
    }
    
    tokenCheck = tokeniseMaze(file, funcMazeInfo);


    if (tokenCheck != 0) {
        fclose(file);
        return EXIT_MAZE_ERROR;
    }
    
    fclose(file);
    return EXIT_SUCCESS;

}

/**
* @brief dynamically allocating memory for the mazeInfo struct, more specifically the maze map 
*
* @param funcMazeInfo declared in main() and memory allocated in the function
* @param funcMazePiece declared in main() and used for memory allocation for maze struct 
* @returns 0 when file opens and data, dimensions are valid and returns 3 if memory cannot be allocated 
*/


// This program is adapted from an example provided on: https://github.com/Scsabr/comp1921-struct-pointers/blob/main/code.c 

int allocateMaze(MazeInfo *funcMazeInfo, MazePiece *funcMazePiece) {

    funcMazeInfo->mazeMap = malloc(funcMazeInfo->rowDimension * sizeof(MazePiece));
    for (int i = 0; i < funcMazeInfo->rowDimension; i++) {
        funcMazeInfo->mazeMap[i] = malloc(funcMazeInfo->colDimension * sizeof(MazePiece));
    }

    if (!funcMazeInfo->mazeMap) {
        printf("Error: malloc failed\n");
        return EXIT_OTHER_ERROR;
    }

    return 0;
}

/**
* @brief process lines in file to calculate how many lines of the maze and check if within specified bounds 
*
* @param file declared within the openFile() function 
* @return row dimensions or 3 if error occurs with maze dimensions not being correct 
*/

int checkRowDimensions(FILE *file) {

    // Determine buffer size and check all lines same length 
    // This program is adapted from an example provided on: https://stackoverflow.com/questions/2137156/finding-line-size-of-each-row-in-a-text-file#:~:text=If%20you%20already%20know%20that,strlen()%20on%20each%20substring.

    int buffer = 1000;
    char line[buffer];
    int counter = 0;

    while (fgets(line, buffer, file)) {
        counter++;
    } 
    
    if (counter < MIN_DIM || counter > MAX_DIM) {
        fclose(file);
        printf("Maze dimensions not valid\n");
        return EXIT_MAZE_ERROR;
    }

    return counter;  
}


/**
* @brief process characters within the maze file checking that they are valid and that each row is the same length 
*
* @param file from the user 
* @return number of columns or 3 if error occurs with characters in the maze or bounds 
*/


int checkColDimensions(FILE *file, int rows) {

    fseek(file, 0, SEEK_SET);

    // Idea taken from: https://stackoverflow.com/questions/2137156/finding-line-size-of-each-row-in-a-text-file#:~:text=If%20you%20already%20know%20that,strlen()%20on%20each%20substring.
    
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

            if (c == EOF) {
                i--;
                break;
            }

            int check = checkChar(c);
            if (check != 0) {
                printf("Data in file is not valid\n");
                return EXIT_MAZE_ERROR;
            }
        }

        if (i != expectedLineLength) {
            printf("Maze dimensions not valid\n");
            return EXIT_MAZE_ERROR;
        }   
    }
    

    if (expectedLineLength < MIN_DIM || expectedLineLength > MAX_DIM) {
        printf("Maze dimensions not valid\n");
        return EXIT_MAZE_ERROR;
    }

    return expectedLineLength;
}


/**
* @brief input values for rows and columns and changes MAZEINFO instance of struct and adds to MAZEPIECE 2D array 
*
* @param file is used to be iterated over and characters put into the struct funcMazeInfo 
* @param funcMazeInfo struct used to put characters into 
*
* @returns 3 if an error occurs with number of starts and ends  or 0 if one does not 
*/
 

// Fgetc() taken from: https://stackoverflow.com/questions/4179671/read-in-text-file-1-character-at-a-time-using-c use this in this function

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
                    hasStart += 1;

                } else if (c == 'E') {
                    funcMazeInfo->endPosition.x = i;
                    funcMazeInfo->endPosition.y = j;
                    hasEnd += 1;
                    
                } else if (c == '#') {
                    funcMazeInfo->mazeMap[i][j].isWall = 1;
                }
            }
        }
    }
    
    if (hasStart == 0 || hasEnd == 0) {
        printf("Data in file is not valid\n");
        return EXIT_MAZE_ERROR;
    }

    if (hasStart > 1 || hasEnd > 1) {
        printf("Data in file is not valid\n");
        return EXIT_MAZE_ERROR;
    }
    
    return 0;

}