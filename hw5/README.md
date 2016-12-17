Read the code comments, but here's the assignment from canvas:

The purpose of this lab is to familiarize you with the C++ process of parsing and file input/output through the basics of the fstream library. The getline function will be used to manipulate large pieces of data into progressively smaller chunks. Together with the stringstream function, you can swap back and forth to 'tokenize' a large line of input and control where each piece goes.

Your job is to write a program that takes an expected input file named "input.txt" of exact format:

(int),(int),(int)
(string)
(int),(int),(int)
(string)
(int),(int),(int)
(string)
(int),(int),(int)
(string)
(int),(int),(int)
(string)

Your program should then sum the ints of each line and output the immediately following line's string that many times seperated by commas such that:

1,2,3
ham

becomes:

ham,ham,ham,ham,ham,ham

You may also find the atoi() and .c_str() functions useful.

Your final output format should not be the console. Instead, your program should open a second file and write your output to a file named "output.txt" which should be five lines of comma-seperated words.

Final deliverable is a zip file with your .cpp source files and a makefile with make, make run and make clean commands. 

