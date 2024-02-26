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

./maze wrongMaze.txt > tmp
if grep -q "File does not exist" tmp;
then
    echo -e "${GREEN}PASS${NC}"
else
    echo -e "${RED}FAIL${NC}"
fi

echo -n "Testing incorrect initialisation of executable - "
# Missing input of filename

./maze > tmp
if grep -q "Usage: ./maze <filename>" tmp;
then
    echo -e "${GREEN}PASS${NC}"
else
    echo -e "${RED}FAIL${NC}"
fi

echo -n "Too many arguments entered - "
# Incorrect filename 

./maze x x x > tmp
if grep -q "File does not exist" tmp;
then
    echo -e "${GREEN}PASS${NC}"
else
    echo -e "${RED}FAIL${NC}"
fi


echo -e "\n${PURPLE}~~ Data Tests ~~${NC}\n"

echo -n "Testing maze dimensions are 5 > and < 100 - "
# Checking if maze height greater than 5 and less than 100 

timeout 0.2s ./maze invalidMazes/incorrectDimensions.txt > tmp
if grep -q "Maze dimensions not valid" tmp;
then
    echo -e "${GREEN}PASS${NC}"
else
    echo -e "${RED}FAIL${NC}"
fi

echo -n "Validity of maze dimensions (row) - "
# Checking if each row same length 

timeout 0.2s ./maze invalidMazes/incorrectDimensions.txt > tmp
if grep -q "Maze dimensions not valid" tmp;
then
    echo -e "${GREEN}PASS${NC}"
else
    echo -e "${RED}FAIL${NC}"
fi

echo -n "Validity of maze dimensions (column) - "
# Checking if each column same length 

timeout 0.2s ./maze invalidMazes/incorrectDimensions.txt > tmp
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

echo -n "Checking if one start and end are present - "
# Checking if each column same length 
# need to check if line is the same

timeout 0.2s ./maze invalidMazes/noStartEnd.txt > tmp
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

echo "x" | ./maze successMazes/successMaze1.txt > tmp
if grep -q "Must be valid character" tmp;
then
    echo -e "${GREEN}PASS${NC}"
else
    echo -e "${RED}FAIL${NC}"
fi


echo -n "Testing no arguments for movement - "
# No value entered for movement 

./maze successMaze/movementMaze.txt > tmp
if grep -q "Must use W/w, A/a, S/s, D/d or M/m" tmp;
then
    echo -e "${GREEN}PASS${NC}"
else
    echo -e "${RED}FAIL${NC}"
fi


echo -e "\n${PURPLE}~~ Logic Tests ~~${NC}\n"


echo -n "Invalid movement into wall - "
# Attempting to walk through a wall 

# nested grep taken from: https://askubuntu.com/questions/1098012/is-it-possible-to-use-grep-command-nested

echo "d" | timeout 0.2s ./maze successMaze/noMoveHitWall.txt > tmp
if grep -q "Move not allowed, try again:" tmp;
then
    echo "m" | timeout 0.2s ./maze successMaze/noMoveHitWall.txt > tmp
    if grep -q "X #####" tmp;
    then 
    echo -e "${GREEN}PASS${NC}"
else
    echo -e "${RED}FAIL${NC}"
    fi
else
    echo -e "${RED}FAIL${NC}"
fi

echo -n "Cheking if X showd correctly and when on start piece - "

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

echo "a" | ./maze successMaze/movementOutMaze.txt > tmp
if grep -q "Move not allowed, try again:" tmp;
then
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


echo -n "Testing cases of user input (W/w) - "

echo "w" | ./maze successMaze/movementMaze.txt > tmp
if grep -q "Piece moved successfully" tmp;
then
    echo "m" | timeout 0.2s ./maze successMaze/movementMaze.txt > tmp
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

echo "a" | ./maze successMaze/movementMaze.txt > tmp
if grep -q "Piece moved successfully" tmp;
then
    echo "m" | timeout 0.2s ./maze successMaze/movementMaze.txt > tmp
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

echo "s" | ./maze successMaze/movementMaze.txt > tmp
if grep -q "Piece moved successfully" tmp;
then
    echo "m" | timeout 0.2s ./maze successMaze/movementMaze.txt > tmp
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
    echo "m" | timeout 0.2s ./maze successMaze/movementMaze.txt > tmp
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

echo "m" | ./maze successMazes/successMaze1.txt > tmp
if grep -q "#X  #" tmp;
then
    echo -e "${GREEN}PASS${NC}"
else
    echo -e "${RED}FAIL${NC}"
fi

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