// Copyright 2016 K.Mensing
// implementation for date object in heap of students project
#include "date.h" // include header file
#include <string> // include string object
#include <iostream> // include iostream

Date::Date() { // default constructor that sets everything to nothing
	Date::month = "0";
	Date::day = "0";
	Date::year = "0";
}

Date::Date(std::string month, std::string day, std::string year) { // Date Constructor that allows assignment of variables initially
	Date::month = month;
	Date::day = day;
	Date::year = year;
}

Date::~Date() {} // default destructor because date doesn't allocate anything on the heap


std::string Date::getMonth() { // month getter
	return Date::month;
}

void Date::setMonth(std::string monthnum) { // month setter
	Date::month = monthnum;
}

std::string Date::getDay() { // day getter
	return Date::day;
}

void Date::setDay(std::string daynum) { // day setter
	Date::day = daynum;
}

std::string Date::getYear() { // year getter
	return Date::year;
}

void Date::setYear(std::string yearnum) { // year setter
	Date::year = yearnum;
}

std::ostream& operator << (std::ostream& os, const Date& d) { // creates function for << operator that streams out the dae content
	os << d.month << "/" << d.day << "/" << d.year;
	return os;
}

void Date::printDate() { // prints date contents
	std::cout << month << "/" << day << "/" << year;
}

// originally I was going to get fancy with input validation but I spend a ton of time on tracking down memory leaks that I never found

/*void Date::checkMonthBounds() {
	if (Date::month > 12) {
		throw "Date value exceeds bounds";
	} else if (Date::month <= 0) {
		throw "Date value beneath bounds";
	}
}

void Date::checkDayBounds() {
	switch (Date::month) {
		case 2 :
			if ((Date::day > 28) && (Date::isLeapYear(Date::year) == 0))  {
				throw "Day value exceeds bounds for February";
				break;
			}
			if ((Date::day > 29) && (Date::isLeapYear(Date::year) == 1)) {
				throw "Day value exceeds bounds for Leap Year February";
				break;
			}
		case 9 :
			if (Date::day > 30) {
				throw "Day value exceeds bounds for September";
				break;
			}
		case 6 :
			if (Date::day > 30) {
				throw "Day value exceeds bounds for June";
				break;
			}
		case 4 :
			if (Date::day > 30) {
				throw "Day value exceeds bounds for April";
				break;
			}
		case 11 :
			if (Date::day > 30) {
				throw "Day value exceeds bounds for November";
				break;
			}
		default:
			if (Date::day > 31) {
				throw "Day value exceeds bounds for month length";
				break;
			}
	}
}

int Date::isLeapYear(int year) {
	if (((year % 100) == 0) && ((year % 400) == 0)) {
		return 1;
	} else if ((year % 4) == 0) {
		return 1;
	} else {
		return 0;
	}
} */

