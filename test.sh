#!/bin/bash

# format taken from:  https://github.com/jenellebankas/lab2-finished, repository by Amy Brereton


echo -e "~~ File Tests ~~\n"

echo -n "Incorrect filename entered -"
# Incorrect filename 

./maze wrongMaze.txt > tmp
if grep -q "File does not exist" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing incorrect initialisation of executable -"
# Missing input of filename

./maze > tmp
if grep -q "Usage: ./maze <filename>" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Too many arguments entered -"
# Incorrect filename 

./maze x x x > tmp
if grep -q "File does not exist" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi


echo -e "\n~~ Data Tests ~~\n"

echo -n "Testing maze dimensions are 5 > and < 100 -"
# Checking if maze height greater than 5 and less than 100 

timeout 0.2s ./maze invalidMazes/incorrectDimensions.txt > tmp
if grep -q "Maze dimensions not valid" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Validity of maze dimensions (row) -"
# Checking if each row same length 

timeout 0.2s ./maze invalidMazes/incorrectDimensions.txt > tmp
if grep -q "Maze dimensions not valid" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Validity of maze dimensions (column) -"
# Checking if each column same length 

timeout 0.2s ./maze invalidMazes/incorrectDimensions.txt > tmp
if grep -q "Data in file is not valid" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Validity of symbols in maze file - "
# Checking for valid symbols in the maze

timeout 0.2s ./maze invalidMazes/incorrectData.txt > tmp
if grep -q "Data in file is not valid" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Checking if a start and end are present -"
# Checking if each column same length 

timeout 0.2s ./maze invalidMazes/noStartEnd.txt > tmp
if grep -q "Data in file is not valid" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Maze file contains data -"
# Checking if file is not empty 

timeout 0.2s ./maze invalidMazes/emptyMaze.txt > tmp
if grep -q "File is empty" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi


echo -e "\n~~ User Input Tests ~~\n"


echo -n "Testing valid key entered for movement - "
# Invalid key value entered for movement 

echo "x" | ./maze successMazes/successMaze1.txt > tmp
if grep -q "Must be valid character" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi



echo -n "Testing no arguments for movement - "
# No value entered for movement 

if grep -q "Must use W/w, A/a, S/s, D/d or M/m" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi


echo -e "\n~~ Logic Tests ~~\n"


echo -n "Invalid movement into wall - "
# Attempting to walk through a wall 

if grep -q "Move not allowed, try again:" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Invalid movement out of the map - "
# Attempting to walk off the edge of the map 

if grep -q "Move not allowed, try again:" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi


echo -e "\n~~ Successful Test ~~\n"

echo -n "Testing file loads succesfully - "

if grep -q "File loaded successfully" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi


echo -n "Testing cases of user input (upper case) - "

if grep -q "Piece moved successfully" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing cases of user input (lower case) - "

if grep -q "Piece moved successfully" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing successful run (Maze 1) - "

timeout 0.2s ./maze successMazes/successMaze1.txt < successMoves/successMaze1Moves.in > tmp
if grep -q "Congratulations, you have reached the end of the maze!" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing successful run (Maze 2) - "

timeout 0.2s ./maze successMazes/successMaze2.txt < successMoves/successMaze2Moves.in > tmp
if grep -q "Congratulations, you have reached the end of the maze!" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing successful run (Maze 3) - "

timeout 0.2s ./maze successMazes/successMaze3.txt < successMoves/successMaze3Moves.in > tmp
if grep -q "Congratulations, you have reached the end of the maze!" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing successful run (Maze 4) - "

timeout 0.2s ./maze successMazes/successMaze4.txt < successMoves/successMaze4Moves.in > tmp
if grep -q "Congratulations, you have reached the end of the maze!" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

# Removal of the tmp file at the end of test completion 
rm -f tmp