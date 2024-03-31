#include "defines.h"
#include "functionIO.h"

/**
* @brief opening the maze file 
*
* @param filename from command arguments taken in from main()
*/

// opens the file for manipulation
// calls tokeniseMaze() function and checkDimensions()


int openFile(char filename[], MazeInfo *funcMazeInfo) {
    
    // open the file specified by users argument and need to check if this is initialised correctly 
    // error checking for the filename and if it exists 
    // error checking for the contents of the file, taken from: https://stackoverflow.com/questions/13566082/how-to-check-if-a-file-has-content-or-not-using-c
    
    long size;
    int buffer = 1000;
    char line[buffer];

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("File does not exist");
        fclose(file);
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
    }
    
    while (fgets(line, buffer, file)) {
        printf("%s", line);
    }

    // calls checkDimensions() function before proceding to ensure that time is not wasted

    int rowLength = checkRowDimensions(file);
    int colLength = checkColDimensions(file);

    if (rowLength == 3 || colLength == 3) {
        return 3;
    }

    funcMazeInfo->rowDimension = rowLength;
    funcMazeInfo->colDimension = colLength;

    allocateMaze(funcMazeInfo);
    
    // while loop for each line which can be processed by tokeniseMaze() which can be called here 
    //tokeniseMaze();

    //char line[rowLength];
    //char currentMazeChar;

    // counts individual characters in the row
    // has a count to count number of rows for array of struct definition
    // index through the line 
    // while the char is not \n

    
    fclose(file);
    return 0;

}

// taken from: https://github.com/Scsabr/comp1921-struct-pointers/blob/main/code.c 

int allocateMaze(MazeInfo *funcMazeInfo) {

    funcMazeInfo->mazeMap = malloc(funcMazeInfo->rowDimension * sizeof(MazeInfo));
    for (int i = 0; i < funcMazeInfo->rowDimension; i++) {
        funcMazeInfo->mazeMap[i] = malloc(funcMazeInfo->colDimension * sizeof(MazeInfo));
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
        printf("Maze row dimensions not valid\n");
        return 3;
    } else {
        return counter;
    } 
}


/**
* @brief process characters within the maze file and sort into the given array
*
* @param file from the user 
* @return 0 or 1 if error occurs when opening/tokenising file and prints error message 
*/


int checkColDimensions(FILE *file) {

    // determine buffer size and check all lines same length 
    // idea taken from: https://stackoverflow.com/questions/2137156/finding-line-size-of-each-row-in-a-text-file#:~:text=If%20you%20already%20know%20that,strlen()%20on%20each%20substring.
    
    int expectedLineLength = 0; 
    int i = 0;
    char d;
    char c;

    while ((d = fgetc(file)) != EOF && d != '\n') {
        expectedLineLength++;
    }
    
    while (c != EOF) { 
        if ((c = fgetc(file)) != EOF && c != '\n') {
            i++;
        } else { 
            if (i != expectedLineLength) {
                printf("Maze dimensions not valid\n");
                return 3;
            }
            i = 0;
        }
    }

    if (expectedLineLength < 5 || expectedLineLength > 100) {
        printf("Maze column dimensions not valid\n");
        return 3;
    } else {
        return expectedLineLength;
    }
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

int tokeniseMaze(const char *line, char *mazeToken, MazeInfo *funcMazeInfo) {

    char *inputCopy = strdup(line);
    
    // Tokenize the copied string
    // Need to tokenise based off of each element for each line 
    
    //char *token = strtok(inputCopy);
    //if (token != NULL) {        
    //    strcpy(mazeToken, token);
    //}
    
    // Free the duplicated string
    free(inputCopy);

    return 0;

}