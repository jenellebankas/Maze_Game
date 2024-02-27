# **MAZE_GAME: COMP1721 PROGRAMMING PROJECT**

## Variables

- **mazePiece**
    - Contains basic information required by each piece 
    - Also has boolean arguments implemented by int to distinguish what type of piece 
    - Also stores position of the piece in terms of column and row 
- **mazeInfo**
    -  Contains basic information for the maze itself 
    -  Allows for easy access for dimensions and where the start and end piece are 


## Functions

- **`void openFile(int argc, char* argv[])`**
    - Used to open the file and also gain the dimensions required by the program 
    - Should return these values which can be used in the struct for mazeInfo
- **`int tokeniseMaze(char* line)`**
    - Used to sort each piece info into an 2D array of mazePiece structs defined 
- **`void displayOptions()`**
    - Used to prompt user for their input
- **`int movement(char userInput)`**
    - Processes user input and implements their chosen move
- **`int moveUser()`**
    - Carries out the movement by adjustment of user player 'X' x and y values
- **`void displayMaze()`**
    - Displays maze current state with the user's 'X' displayed on the board
- **`int checkPieceType(char symbol)`**
    - Returns the type of piece to determine whether a move can be carried out 
- **`int checkEnd()`**
    - Returns boolean implemented through int type 
- **`int checkMoveValidity()`**
    - Return boolean implemented through int type and checks if move can be done
    

# Testing
*Overview of chosen tests*

| **Tests** | **Description** |
| ----- | ----------- |
|**Argument Tests**| Incorrect filename entered|
|| Testing incorrect initialisation of executable|
|| Too many arguments entered|
|**Data Tests**| Testing maze dimensions are < 100|
|| Testing maze dimensions are 5 >|
|| Validity of maze dimensions (row)|
|| Validity of maze dimensions (column)|
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
- File usage: "Usage: ./maze <filename>"
- No movement character entered: "Must use W/w, A/a, S/s, D/d or M/m"
- Invalid character entered: "Must be valid character"
- Bad data in file: "Data in file is not valid"
- Incorrect maze dimensions: "Maze dimensions not valid"
- Empty file: "File is empty"
- Succesful move: "Piece moved successfully"
- File loaded succesfully: "File loaded successfully"
- Invalid move attempted: "Move not allowed, try again:" 

-  Successful run message: "Congratulations, you have reached the end of the maze!" (there will also be an ASCII art after this)


