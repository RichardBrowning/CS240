// library.h
// Copyright 2016 K. Mensing
#ifndef LIBRARY_H_EXISTS
#define LIBRARY_H_EXISTS

#include "book.h" // includes the book object

class Library {
	private: // private attributes
		Book b[5]; // initalized at 5, because why not?
		int bookNum; // book number
	public: // public attributes
		Library(); // constructor
		int getBookNum(); // getter for the book number
		void printTitles(); // getter and print object for the titles
};

#endif
