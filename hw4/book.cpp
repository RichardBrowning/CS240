// book.cpp
// Copyright 2017 K. Mensing
// this has all the method implementation for the Book object
#include <string>
#include "book.h"

Book::Book() { // the default Book constructor
	Book::title = "Book Title"; // creates default placeholder for the title of the book
	Book::author = "Book Author"; // creates default placeholder for the author of the book
	Book::pageNum = 0; // initializes the page number to 0
}

Book::Book(std::string title, int pageNum) { // the overloaded Book constructor that allows for non-default initial values
	Book::title = title; // sets the title to the inputted value
	Book::pageNum = pageNum; // sets the page number to the inputted value
	Book::author = "Book Author"; // still sets the author to the default author value
}

std::string Book::getTitle() { // Book title getter
	return(Book::title); // returns the book title
}

int Book::getPageNum() { // Book number getter
	return(Book::pageNum); // returns the page number of the book
}
