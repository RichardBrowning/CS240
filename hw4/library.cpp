// Copyright 2016 K. Mensing
// library.cpp
#include <string>
#include <iostream>
#include "library.h"

Library::Library() { // Library constructor
	Library::bookNum = 0; // sets the default book number to 0
}

int Library::getBookNum() { // getter for the book number
	return(Library::bookNum); // returns the book number
}

void Library::printTitles() { // sort of the getter for the titles
	std::cout << "Titles" << std::endl; // placeholder for the for loop that would eventually be implemented
}
