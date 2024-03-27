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
    // error checking for the contents of the file, idea taken from: https://stackoverflow.com/questions/13566082/how-to-check-if-a-file-has-content-or-not-using-c
    
    int size;
    //int expectedLineLength = 0; 

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("File does not exist");
        exit(2);
        return 2;

    } else {
        fseek(file, 0, SEEK_END);
        size = ftell(file);
    }

    if (0 == size) {
        printf("File is empty\n");
        exit(2);
        return 2;
    }

    // something wrong with checkDimensions() functions, don't know yet tho???
    // calls checkDimensions() function before proceding to ensure that time is not wasted
    int rowLength = checkRowDimensions(file);
    int colLength = checkColDimensions(file);


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
    
    int buffer = 100;
    char line[buffer];

    // need to define line variable for the reading of the file 
    // use the expectedLineLength variable here as it will exit before if there is an issue
    // also need a variable to temporarily store the character being processed 
    int length = strlen(fgets(line, buffer, file)) - 1;
    
    // to read each line
    while (fgets(line, buffer, file)) {   
        // sorting the data in the file
        //tokeniseMaze(line, currentMazeChar);
        if ((strlen(line) - 1) != length) {
            printf("Data in file is not valid\n");
            return 3;
    }
    
    if (length < 5 || length > 100) {

        printf("Maze dimensions not valid");
        return 2;
    }

    }

    return length;

    // error checking done before this declaration 
    // if no error assignment of MAZEINFO.rowDimension and MAZEINFO.colDimension
    // dynamically allocate memory for the size of the 2D array 

    
    // placeholder return until function is fully programmed 
    return 0;
}


/**
* @brief process characters within the maze file and sort into the given array
*
* @param file from the user 
* @return 0 or 1 if error occurs when opening/tokenising file and prints error message 
*/

// error checking for the uniform row length 
// error checking for uniform column length 


int checkColDimensions(FILE *file) {


    // determine buffer size and check all lines same length 
    // idea taken from: https://stackoverflow.com/questions/2137156/finding-line-size-of-each-row-in-a-text-file#:~:text=If%20you%20already%20know%20that,strlen()%20on%20each%20substring.

    int expectedLineLength = 0; 
    int i = 0;
    char mazeCharacter;


    while (mazeCharacter != EOF)
        if ((mazeCharacter = fgetc(file)) != EOF && mazeCharacter != '\n') {
            i++; 
            expectedLineLength = i;
        } else if (i != expectedLineLength){ 
            printf("Data in file is not valid\n");
            return EXIT_MAZE_ERROR;
        }
    
    if (expectedLineLength < 5 || expectedLineLength > 100) {
        return EXIT_MAZE_ERROR;
    }
    
    
        // copy the info into the array
        // have a counter for the counting of lines 
        //counter++;
    // need to define line variable for the reading of the file 
    // use the expectedLineLength variable here as it will exit before if there is an issue
    // also need a variable to temporarily store the character being processed 


    // counts individual characters in the row
    // has a count to count number of rows for array of struct definition
    // index through the line 
    // while the char is not \n


    // error checking done before this declaration 
    // if no error assignment of MAZEINFO.rowDimension and MAZEINFO.colDimension
    // dynamically allocate memory for the size of the 2D array 

    
    // placeholder return until function is fully programmed 
    return expectedLineLength;
    
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

int tokeniseMaze(const char *line, char *mazeToken) {

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