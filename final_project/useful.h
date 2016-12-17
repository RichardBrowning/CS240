// useful.h
// copyright 2016 K.Mensing
#ifndef USEFUL_H
#define USEFUL_H
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iterator>

// useful.h and useful.cpp are where I'm keeping all the helper functions and non-class functions that I don't want to clog main up with

void printVector(std::vector<float>); // a function that prints a vector of floats
int mainMenu(); // the main menu function that returns what the user selects
std::string promptFilename(); // a function that prompts the user for filenames to load from. Returns the filename as a string
std::string promptFilenameOut(); // a function that prompts the user for filenames to save to. Returns the filename as a string
void split(const std::string&, char, std::vector<std::string>&); // a function that splits a line of text up by a given delimiter
std::vector<std::vector<float> > getCSV(); // the workhorse function. Gets and parses a CSV of floating point numbers to a vOv of floats 
bool decide(int);  // the function that does the work, taking input from mainMenu() and making stuff happen
#endif
