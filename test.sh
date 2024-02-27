#!/bin/bash

# format taken from:  https://github.com/jenellebankas/lab2-finished, repository by Amy Brereton
# colours taken from: https://stackoverflow.com/questions/5947742/how-to-change-the-output-color-of-echo-in-linux 


RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'
PURPLE='\033[0;35m'

echo -e "\n${PURPLE}~~ File Tests ~~${NC}\n"

echo -n "Incorrect filename entered - "
# Incorrect filename 

timeout 0.2s ./maze wrongMaze.txt > tmp
if grep -q "File does not exist" tmp;
then
    echo -e "${GREEN}PASS${NC}"
else
    echo -e "${RED}FAIL${NC}"
fi

echo -n "Testing incorrect initialisation of executable - "
# Missing input of filename

timeout 0.2s ./maze > tmp
if grep -q "Usage: ./maze <filename>" tmp;
then
    echo -e "${GREEN}PASS${NC}"
else
    echo -e "${RED}FAIL${NC}"
fi

echo -n "Too many arguments entered - "

timeout 0.2s ./maze x x x > tmp
if grep -q "Too many arguments" tmp;
then
    echo -e "${GREEN}PASS${NC}"
else
    echo -e "${RED}FAIL${NC}"
fi


echo -e "\n${PURPLE}~~ Data Tests ~~${NC}\n"

echo -n "Testing maze dimensions are < 100 - "
# Checking if maze rows and columns are less than 100 

timeout 0.2s ./maze invalidMazes/incorrectDimensionRange100.txt > tmp
if grep -q "Maze dimensions not valid" tmp;
then
    echo -e "${GREEN}PASS${NC}"
else
    echo -e "${RED}FAIL${NC}"
fi

echo -n "Testing maze dimensions are 5 > - "
# Checking if maze rows and columns are greater than 5

timeout 0.2s ./maze invalidMazes/incorrectDimensionRange5.txt > tmp
if grep -q "Maze dimensions not valid" tmp;
then
    echo -e "${GREEN}PASS${NC}"
else
    echo -e "${RED}FAIL${NC}"
fi

# Checking if each row is the same length to form a rectangle 
echo -n "Validity of maze dimensions, test 1 - "


timeout 0.2s ./maze invalidMazes/incorrectDimensions1.txt > tmp
if grep -q "Maze dimensions not valid" tmp;
then
    echo -e "${GREEN}PASS${NC}"
else
    echo -e "${RED}FAIL${NC}"
fi

echo -n "Validity of maze dimensions, test 2 - "

timeout 0.2s ./maze invalidMazes/incorrectDimensions2.txt > tmp
if grep -q "Data in file is not valid" tmp;
then
    echo -e "${GREEN}PASS${NC}"
else
    echo -e "${RED}FAIL${NC}"
fi

echo -n "Validity of symbols in maze file - "
# Checking for valid symbols in the maze

timeout 0.2s ./maze invalidMazes/incorrectData.txt > tmp
if grep -q "Data in file is not valid" tmp;
then
    echo -e "${GREEN}PASS${NC}"
else
    echo -e "${RED}FAIL${NC}"
fi

echo -n "Checking if no start present - "
# Checking if each column same length 
# need to check if line is the same

timeout 0.2s ./maze invalidMazes/noStart.txt > tmp
if grep -q "Data in file is not valid" tmp;
then
    echo -e "${GREEN}PASS${NC}"
else
    echo -e "${RED}FAIL${NC}"
fi

echo -n "Checking if no end present - "
# Checking if each column same length 
# need to check if line is the same

timeout 0.2s ./maze invalidMazes/noEnd.txt > tmp
if grep -q "Data in file is not valid" tmp;
then
    echo -e "${GREEN}PASS${NC}"
else
    echo -e "${RED}FAIL${NC}"
fi

echo -n "Maze file contains data - "
# Checking if file is not empty 

timeout 0.2s ./maze invalidMazes/emptyMaze.txt > tmp
if grep -q "File is empty" tmp;
then
    echo -e "${GREEN}PASS${NC}"
else
    echo -e "${RED}FAIL${NC}"
fi


echo -e "\n${PURPLE}~~ User Input Tests ~~${NC}\n"


echo -n "Testing valid key entered for movement - "
# Invalid key value entered for movement 

echo "x" | timeout 0.2s ./maze successMazes/movementMaze.txt > tmp
if grep -q "Must be valid character" tmp;
then
    echo -e "${GREEN}PASS${NC}"
else
    echo -e "${RED}FAIL${NC}"
fi


echo -n "Testing no arguments for movement - "
# No value entered for movement 

timeout 0.2s ./maze successMaze/movementMaze.txt > tmp
if grep -q "Must use W/w, A/a, S/s, D/d or M/m" tmp;
then
    echo -e "${GREEN}PASS${NC}"
else
    echo -e "${RED}FAIL${NC}"
fi


echo -e "\n${PURPLE}~~ Logic Tests ~~${NC}\n"


echo -n "Invalid movement into wall - "
# Attempting to walk through a wall 


echo "d" | timeout 0.2s ./maze successMaze/noMoveHitWall.txt > tmp
if grep -q "Move not allowed, try again:" tmp;
then
    # checking if the movement is not carried out if correct message produced 
    timeout 0.2s echo "m" > tmp
    if grep -q "X #####" tmp;
    then 
    echo -e "${GREEN}PASS${NC}"
else
    echo -e "${RED}FAIL${NC}"
    fi
else
    echo -e "${RED}FAIL${NC}"
fi

echo -n "Cheking if 'X' shown correctly when on start piece - "

# Test to show X if on start piece 
echo "m" | timeout 0.2s ./maze successMaze/movementMaze.txt > tmp
if grep -q "X #####" tmp;
then
    echo -e "${GREEN}PASS${NC}"
else
    echo -e "${RED}FAIL${NC}"
fi

echo -n "Invalid movement out of the map - "
# Attempting to walk off the edge of the map 

echo "a" | timeout 0.2s ./maze successMaze/movementOutMaze.txt > tmp
if grep -q "Move not allowed, try again:" tmp;
then
    # confirming that this move has not occurred
    echo "m" | timeout 0.2s ./maze successMaze/movementOutMaze.txt > tmp
    if grep -q "X #####" tmp;
    then 
        echo -e "${GREEN}PASS${NC}"
    else
        echo -e "${RED}FAIL${NC}"
    fi
else
    echo -e "${RED}FAIL${NC}"
fi


echo -e "\n${PURPLE}~~ Successful Tests ~~${NC}\n"

echo -n "Testing file loads succesfully - "

timeout 0.2s ./maze successMazes/successMaze1 > tmp
if grep -q "File loaded successfully" tmp;
then
        echo -e "${GREEN}PASS${NC}"
    else
        echo -e "${RED}FAIL${NC}"
fi


# checking if correct move has been carried out through the nested if statements 
# for movement cases 

echo -n "Testing cases of user input (W/w) - "

echo "w" | timeout 0.2s ./maze successMaze/movementMaze.txt > tmp
if grep -q "Piece moved successfully" tmp;
then
    timeout 0.2s echo "m" > tmp
    if grep -q "###X###" tmp;
    then 
        echo -e "${GREEN}PASS${NC}"
    else
        echo -e "${RED}FAIL${NC}"
    fi
else
    echo -e "${RED}FAIL${NC}"
fi

echo -n "Testing cases of user input (A/a) - "

echo "a" | timeout 0.2s ./maze successMaze/movementMaze.txt > tmp
if grep -q "Piece moved successfully" tmp;
then
    timeout 0.2s echo "m" > tmp
    if grep -q "##X ##" tmp;
    then 
        echo -e "${GREEN}PASS${NC}"
    else
        echo -e "${RED}FAIL${NC}"
    fi
else
    echo -e "${RED}FAIL${NC}"
fi

echo -n "Testing cases of user input (S/s) - "

echo "s" | timeout 0.2s ./maze successMaze/movementMaze.txt > tmp
if grep -q "Piece moved successfully" tmp;
then
    timeout 0.2s echo "m" > tmp
    if grep -q "###X## " tmp;
    then 
        echo -e "${GREEN}PASS${NC}"
    else
        echo -e "${RED}FAIL${NC}"
    fi
else
    echo -e "${RED}FAIL${NC}"
fi

echo -n "Testing cases of user input (D/d) - "

echo "d" | ./maze successMaze/movementMaze.txt > tmp
if grep -q "Piece moved successfully" tmp;
then
    timeout 0.2s echo "m" > tmp
    if grep -q "###  X##" tmp;
    then 
        echo -e "${GREEN}PASS${NC}"
    else
        echo -e "${RED}FAIL${NC}"
    fi
else
    echo -e "${RED}FAIL${NC}"
fi

echo -n "Testing cases of user input (M/m) - "

echo "m" | timeout 0.2s ./maze successMazes/successMaze1.txt > tmp
if grep -q "#X  #" tmp;
then
    echo -e "${GREEN}PASS${NC}"
else
    echo -e "${RED}FAIL${NC}"
fi

# succesful runs of different maze formats 

echo -n "Testing successful run (Maze 1) - "

timeout 0.2s ./maze successMazes/successMaze1.txt < successMoves/successMaze1Moves.in > tmp
if grep -q "Congratulations, you have reached the end of the maze!\n
 _     _  _______  ___      ___        ______   _______  __    _  _______  __  
| | _ | ||       ||   |    |   |      |      | |       ||  |  | ||       ||  | 
| || || ||    ___||   |    |   |      |  _    ||   _   ||   |_| ||    ___||  | 
|       ||   |___ |   |    |   |      | | |   ||  | |  ||       ||   |___ |  | 
|       ||    ___||   |___ |   |___   | |_|   ||  |_|  ||  _    ||    ___||__| 
|   _   ||   |___ |       ||       |  |       ||       || | |   ||   |___  __  
|__| |__||_______||_______||_______|  |______| |_______||_|  |__||_______||__|" tmp;
then
    echo -e "${GREEN}PASS${NC}"
else
    echo -e "${RED}FAIL${NC}"
fi

echo -n "Testing successful run (Maze 2) - "

timeout 0.2s ./maze successMazes/successMaze2.txt < successMoves/successMaze2Moves.in > tmp
if grep -q "Congratulations, you have reached the end of the maze!\n 
 _     _  _______  ___      ___        ______   _______  __    _  _______  __  
| | _ | ||       ||   |    |   |      |      | |       ||  |  | ||       ||  | 
| || || ||    ___||   |    |   |      |  _    ||   _   ||   |_| ||    ___||  | 
|       ||   |___ |   |    |   |      | | |   ||  | |  ||       ||   |___ |  | 
|       ||    ___||   |___ |   |___   | |_|   ||  |_|  ||  _    ||    ___||__| 
|   _   ||   |___ |       ||       |  |       ||       || | |   ||   |___  __  
|__| |__||_______||_______||_______|  |______| |_______||_|  |__||_______||__|" tmp;
then
    echo -e "${GREEN}PASS${NC}"
else
    echo -e "${RED}FAIL${NC}"
fi

echo -n "Testing successful run (Maze 3) - "

timeout 0.2s ./maze successMazes/successMaze3.txt < successMoves/successMaze3Moves.in > tmp
if grep -q "Congratulations, you have reached the end of the maze!\n
 _     _  _______  ___      ___        ______   _______  __    _  _______  __  
| | _ | ||       ||   |    |   |      |      | |       ||  |  | ||       ||  | 
| || || ||    ___||   |    |   |      |  _    ||   _   ||   |_| ||    ___||  | 
|       ||   |___ |   |    |   |      | | |   ||  | |  ||       ||   |___ |  | 
|       ||    ___||   |___ |   |___   | |_|   ||  |_|  ||  _    ||    ___||__| 
|   _   ||   |___ |       ||       |  |       ||       || | |   ||   |___  __  
|__| |__||_______||_______||_______|  |______| |_______||_|  |__||_______||__|
" tmp;
then
    echo -e "${GREEN}PASS${NC}"
else
    echo -e "${RED}FAIL${NC}"
fi

echo -n "Testing successful run (Maze 4) - "

timeout 0.2s ./maze successMazes/successMaze4.txt < successMoves/successMaze4Moves.in > tmp
if grep -q "Congratulations, you have reached the end of the maze!\n
 _     _  _______  ___      ___        ______   _______  __    _  _______  __  
| | _ | ||       ||   |    |   |      |      | |       ||  |  | ||       ||  | 
| || || ||    ___||   |    |   |      |  _    ||   _   ||   |_| ||    ___||  | 
|       ||   |___ |   |    |   |      | | |   ||  | |  ||       ||   |___ |  | 
|       ||    ___||   |___ |   |___   | |_|   ||  |_|  ||  _    ||    ___||__| 
|   _   ||   |___ |       ||       |  |       ||       || | |   ||   |___  __  
|__| |__||_______||_______||_______|  |______| |_______||_|  |__||_______||__|" tmp;
then
    echo -e "${GREEN}PASS${NC}"
else
    echo -e "${RED}FAIL${NC}"
fi

# Removal of the tmp file at the end of test completion 
rm -f tmp