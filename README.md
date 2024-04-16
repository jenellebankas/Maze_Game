# **MAZE_GAME: COMP1721 PROGRAMMING PROJECT**

## Variables

- **mazePiece**
    - Contains basic information required by each piece 
    - Also has boolean arguments implemented by int to distinguish what type of piece 
    - Also stores position of the piece in terms of column and row 
- **mazeInfo**
    - Contains basic information for the maze itself 
    - Allows for easy access for dimensions and where the start and end piece are 
    - The maze dimensions are stored as a few functions must access this informaition and it is therefore easier to keep it in the struct 

## Functions
    
- **`int openFile(char filename[], MazeInfo *mazeInfo, MazePiece *funcMazePiece)`**
    - Used to open the file and also gain the dimensions required by the program 
    - Values for row and column length will be updated from the call of tokeniseMaze

- **`int checkRowDimensions(FILE *file)`**
    - Checks row dimensions of the file and if they are within allowed range

- **`int checkColDimensions(FILE *file, int rows)`**
    - Checks row dimensions of the file and if they are within allowed range
    - Also checks if the maze is rectangular 

- **`int checkChar(char input)`**
    - Using switch statement to check if each char in the maze is valid

- **`int tokeniseMaze(FILE *file, MazeInfo *funcMazeInfo)`**
    - Used to sort each piece info into an 2D array of mazePiece structs defined 

- **`int displayOptions(Coord *currentPos, MazeInfo *funcMazeInfo)`**
    - Used to prompt user for their input

- **`int movement(char userInput, Coord *currentPos, MazeInfo *funcMazeInfo)`**
    - Computes the movement for the maze after validating and calling checkMoveValidity()

- **`void displayMaze(Coord *currentPos, MazeInfo *funcMazeInfo)`**
    - Displays maze current state with the user's 'X' displayed on the board

- **`int checkEnd(Coord *currentPos, MazeInfo *funcMazeInfo)`**
    - Returns boolean implemented through int type 

- **`int checkMoveValidity(char userInput, Coord *currentPos, MazeInfo *funcMazeInfo)`**
    - Return boolean implemented through int type and checks if move can be done

- **`void displayEnd()`**
    - Shows success message and maze to user once while loop exited in main 

- **`int freeMaze(MazeInfo *funcMazeInfo)`**
    - Frees memory allocated to the maze once the maze has been completed

- **`int allocateMaze(MazeInfo *funcMazeInfo, MazePiece *funcMazePiece)`**
    - Dynamically allocates memory to maze 

# Testing
*Overview of chosen tests*

| **Tests** | **Description** |
| ----- | ----------- |
|**Argument Tests**| Incorrect filename entered|
|| Testing incorrect initialisation of executable|
|| Too many arguments entered|
|**Data Tests**| Testing maze dimensions are < 100|
|| Testing maze dimensions are 5 >|
|| Validity of maze dimensions, test 1|
|| Validity of maze dimensions, test 2|
|| Validity of symbols in maze file|
|| Checking if start present|
|| Checking if end present|
|| Maze file contains data|
|**User Input**| Testing valid key entered for movement|
|| Testing no arguments for movement|
|**Logic Tests**| Invalid movement into wall|
|| Invalid movement out of the map|
|| Checking X shown when on S and when user clicks M/m|
|**Successful Tests**| Testing file loads succesfully|
|| Testing cases of user input (W/w)|
|| Testing cases of user input (A/a)|
|| Testing cases of user input (S/s)|
|| Testing cases of user input (D/d)|
|| Testing cases of user input (M/m)|
|| Testing successful run (Maze 1)|
|| Testing successful run (Maze 2)|
|| Testing successful run (Maze 3)|
|| Testing successful run (Maze 4)|


## *Error Messages*

- Invalid filename: "File does not exist"
- Too many arguments: "Too many Arguments"
- File usage: "Usage: ./maze '<"filename">"
- No movement character entered: "Must use W/w, A/a, S/s, D/d or M/m"
- Invalid character entered: "Must be valid character, try again:"
- Bad data in file: "Data in file is not valid"
- Incorrect maze dimensions: "Maze dimensions not valid"
- Empty file: "File is empty"
- Succesful move: "Piece moved successfully"
- File loaded succesfully: "File loaded successfully"
- Invalid move attempted: "Move not allowed, try again:" 

-  Successful run message: "Congratulations, you have reached the end of the maze!" (there will also be an ASCII art after this)


