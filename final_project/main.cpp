// main.cpp
// Copyright 2016 K. Mensing
// the main function of my matrix program
#include "matrix.h" // includes the matrix class
#include "useful.h" // includes all the little helper functions
int main() {
	bool keepGoing = true; // this helps us with the workflow and exiting
	while (keepGoing) { // is true while we want to continue
		int choice = mainMenu(); // a number that indicates the user's choice
		if ((1 <= choice) && (choice <= 8)) { // validates the user's input
			bool t = decide(choice); // calls the decision function with the given choice
			keepGoing = t; // assigns keepGoing to the return of decide
		} else { // this makes use exit when we want to
		    keepGoing = false; 
		    std::cout << "Exiting..." << std::endl; // prints a nice message
		}
	}
	return 0; // as is tradition
}
