// date.h
// Copyright 2016 K.Mensing
#ifndef DATE_H_EXISTS
#define DATE_H_EXISTS
#include <iostream>
#include <string>
class Date {
	private: // private attributes
		std::string month; // month variable
		std::string day; // day variable
		std::string year; // year variable
	public:
		Date(); // default constructor
		Date(std::string, std::string, std::string); // constructor that take strings for each field
		~Date(); // Destructor
		std::string getMonth(); // month getter
		void setMonth(std::string); // month setter
		std::string getDay(); // day getter
		void setDay(std::string); // day setter
		std::string getYear(); // year getter
		void setYear(std::string); // year setter
		friend std::ostream& operator << (std::ostream& os, const Date& d); // output stream for the date (friend)
		void printDate(); // prints out the entire date
};
#endif
