// book.h
// Copyright 2016 K. Mensing
#ifndef BOOK_H_EXISTS
#define BOOK_H_EXISTS

#include <string> // includes the string library so we can use it
class Book {
 private: // private attributes
	 std::string title; // title string
	 std::string author; // author string
	 int pageNum; // page number
 public: // public attributes
	 Book(); // default constructor
	 explicit Book(std::string title, int pageNum); // overload constructor that allows for initialization of alternative titles and page numbs
	 std::string getTitle(); // getter function for the title
	 int getPageNum(); // getter function for the page number
};

#endif
