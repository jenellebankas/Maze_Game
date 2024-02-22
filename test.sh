#!/bin/bash

# Error Messages: 
# Invalid filename: "File does not exist"
# File usage: "Usage: ./maze <filename>"
# No movement character entered: "Must use W/w, A/a, S/s, D/d or M/m"
# Invalid character entered: "Must be valid character"
# Bad data in file: "Data in file is not valid"
# Incorrect maze dimensions: "Maze dimensions not valid"
# Empty file: "File is empty"
# Invalid move attempted: "Move not allowed, try again:"

# Successful run message: "Congratulations, you have reached the end of the maze!"



echo -e "~~ Argument Tests ~~"


echo -e "~~ File Tests ~~"

echo -n "Testing no arguments - "
# Incorrect filename 

if grep -q "File does not exist" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing no arguments - "
# Missing input of filename

if grep -q "Usage: ./maze <filename>" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi


echo -e "~~ Data Tests ~~"

echo -n "Testing no arguments - "
# Checking for appropriate dimensions of the maze

if grep -q "Maze dimensions not valid" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing no arguments - "
# Checking if maze height greater than 5 and less than 100 

if grep -q "Maze dimensions not valid" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing no arguments - "
# Checking if maze width greater than 5 and less than 100

if grep -q "Maze dimensions not valid" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing no arguments - "
# Checking if each row same length 

if grep -q "Maze dimensions not valid" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing no arguments - "
# Checking if each column same length 

if grep -q "Data in file is not valid" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing no arguments - "
# Checking for valid symbols in the maze

if grep -q "Data in file is not valid" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing no arguments - "
# Checking if file is not empty 

if grep -q "File is empty" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi


echo -e "~~ User Input Tests ~~"


echo -n "Testing no arguments - "
# Invalid key value entered for movement 

if grep -q "Must be valid character" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing no arguments - "
# No value entered for movement 

if grep -q "Must use W/w, A/a, S/s, D/d or M/m" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi


echo -e "~~ Logic Tests ~~"


echo -n "Testing no arguments - "
# Attempting to walk through a wall 

if grep -q "Move not allowed, try again:" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing no arguments - "
# Attempting to walk off the edge of the map 

if grep -q "Move not allowed, try again:" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi


echo -e "~~ Successful Run Test ~~"

echo -n "Testing successful run (Maze 1) - "
# Checking success message reached when edge of maze reached 

if grep -q "Congratulations, you have reached the end of the maze!" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing successful run (Maze 2) - "
# Checking success message reached when edge of maze reached 

if grep -q "Congratulations, you have reached the end of the maze!" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing successful run (Maze 3) - "
# Checking success message reached when edge of maze reached 

if grep -q "Congratulations, you have reached the end of the maze!" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

echo -n "Testing successful run (Maze 4) - "
# Checking success message reached when edge of maze reached 

if grep -q "Congratulations, you have reached the end of the maze!" tmp;
then
    echo "PASS"
else
    echo "FAIL"
fi

# Removal of the tmp file at the end of test completion 
rm -f tmp