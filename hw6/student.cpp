// student.cpp for heap of students
// Copyright 2016 K. Mensing
#include <string>
#include <sstream>
#include "student.h"
#include "address.h"
#include "date.h"

Student::Student(std::string line) { // constructor that takes a string
	std::stringstream ss(line); // creates a stringstream with the input line
	Student::studentAddress = new Address(); // creates a new address object
	Student::birthDay = new Date(); // creates a new date object for birthday
	Student::gradDay = new Date(); // creates a new date object for gradDay

	std::string tempAdd1, tempAdd2, tempCity, tempState, tempZIP, tempDOBDay, tempDOBMonth, tempDOBYear, tempGradDay, tempGradMonth, tempGradYear, tempGPA, tempCredHours; // initializes a bunch of placeholder strings

	getline(ss, Student::lastName, ','); // gets the lastname portion
	getline(ss, Student::firstName, ','); // gets the firstname portion
	getline(ss, tempAdd1, ','); // gets the first address line portion of the strin
	getline(ss, tempAdd2, ','); // gets th second address line porton
	getline(ss, tempCity, ','); // gets the city portion
	getline(ss, tempState, ','); // gets the state portion
	getline(ss, tempZIP, ','); // gets the zip portion
	getline(ss, tempDOBDay, '/'); // gets Birth Day
	getline(ss, tempDOBMonth, '/'); // gets birth month
	getline(ss, tempDOBYear, ','); // gets birth year
	getline(ss, tempGradDay, '/'); // gets grad day
	getline(ss, tempGradMonth, '/'); // gets grad month
	getline(ss, tempGradYear, ','); // gets grad year
	getline(ss, tempGPA, ','); // gets GPA
	getline(ss, tempCredHours); // gets credit hours

	Student::studentAddress -> setAddLine1(tempAdd1); // sets address line 1
	Student::studentAddress -> setAddLine2(tempAdd2); // sets address line 2
	Student::studentAddress -> setCity(tempCity); // sets city
	Student::studentAddress -> setState(tempState); // sets state
	Student::studentAddress -> setZipCode(tempZIP); // sets zip

	Student::gradDay -> setDay(tempGradDay); // sets grad day
	Student::gradDay -> setYear(tempGradYear); // sets grad year
	Student::gradDay -> setMonth(tempGradMonth); // sets grad month

	Student::birthDay -> setDay(tempDOBDay); // sets birth day
	Student::birthDay -> setMonth(tempDOBMonth); // sets birth month
	Student::birthDay -> setYear(tempDOBYear); // sets birth year

	Student::setGPA(tempGPA); // sets gpa

	Student::setCreditHours(tempCredHours); // sets credit hour
}

Student::Student() { // default constructor with nil values
	Student::firstName = "";
	Student::lastName = "";
	Student::birthDay = new Date();
	Student::gradDay = new Date();
	Student::studentAddress = new Address();
        Student::gradePointAvg = "0";
        Student::completeCreditHours = "0";
}

Student::~Student() { // destructor for student
	delete studentAddress; // deletes address from heap
	delete birthDay; // deletes birthday from heap
	delete gradDay; // deletes gradday from hap
	// std::cout << "Student Destructor Called" << std::endl;
}


void Student::setFirstName(std::string firstn) { // setter for first name
	Student::firstName = firstn;
}

std::string Student::getFirstName() { // getter for firstname
	return Student::firstName;
}

void Student::setLastName(std::string lastn) { // setter for lastname
	Student::lastName = lastn;
}

std::string Student::getLastName() { // getter for lastname
	return Student::lastName;
}

Address Student::getStudentAddress() { // getter for address
	return *Student::studentAddress;
}

void Student::setStudentAddress(Address * add) { // setter for address
	Student::studentAddress = add;
}

Date Student::getBirthDay() { // getter for birthday
	return *Student::birthDay;
}

void Student::setBirthDay(Date * bd) { // setter for birthday
	Student::birthDay = bd;
}

Date Student::getGradDay() { // getter for gradday
	return *Student::gradDay;
}

void Student::setGradDay(Date * gd) { // setter for gradday
	Student::gradDay = gd;
}

std::string Student::getGPA() { // getter for gpa
	return Student::gradePointAvg;
}

void Student::setGPA(std::string gpa) { // setter for gpa
	Student::gradePointAvg = gpa;
}

std::string Student::getCreditHours() { // getter for credit hours
	return Student::completeCreditHours;
}

void Student::setCreditHours(std::string ch) { // setter for credit hours
	Student::completeCreditHours = ch;
}

std::ostream& operator << (std::ostream& os, const Student& s) { // allows the use of the << symbols to stream the object's data (friend)
	os << s.lastName << ", " << s.firstName << " " << *s.studentAddress << " " << *s.birthDay << " " << *s.gradDay << " " << s.gradePointAvg << " " << s.completeCreditHours;
	return os;
}

void Student::set(std::string line) { // setter for the entire object, just takes a string. nearly everything here is the same as the constructor, just without heap allocations (that was messing me up the whole time here)
	std::stringstream ss(line);
	std::string tempAdd1, tempAdd2, tempCity, tempState, tempZIP, tempDOBDay, tempDOBMonth, tempDOBYear, tempGradDay, tempGradMonth, tempGradYear, tempGPA, tempCredHours;

	getline(ss, Student::lastName, ',');
	getline(ss, Student::firstName, ',');
	getline(ss, tempAdd1, ',');
	getline(ss, tempAdd2, ',');
	getline(ss, tempCity, ',');
	getline(ss, tempState, ',');
	getline(ss, tempZIP, ',');
	getline(ss, tempDOBDay, '/');
	getline(ss, tempDOBMonth, '/');
	getline(ss, tempDOBYear, ',');
	getline(ss, tempGradDay, '/');
	getline(ss, tempGradMonth, '/');
	getline(ss, tempGradYear, ',');
	getline(ss, tempGPA, ',');
	getline(ss, tempCredHours);

	Student::studentAddress -> setAddLine1(tempAdd1);
	Student::studentAddress -> setAddLine2(tempAdd2);
	Student::studentAddress -> setCity(tempCity);
	Student::studentAddress -> setState(tempState);
	Student::studentAddress -> setZipCode(tempZIP);
	Student::gradDay -> setDay(tempGradDay);
	Student::gradDay -> setYear(tempGradYear);
	Student::gradDay -> setMonth(tempGradMonth);

	Student::birthDay -> setDay(tempDOBDay);
	Student::birthDay -> setMonth(tempDOBMonth);
	Student::birthDay -> setYear(tempDOBYear);

	Student::setGPA(tempGPA);

	Student::setCreditHours(tempCredHours);
}

void Student::printFull() { // prints the entire record
	Student::printNames();
	std::cout << " ";
	studentAddress->printAddress();
	birthDay->printDate();
	std::cout << " ";
	gradDay->printDate();
	std::cout << gradePointAvg << ", " << completeCreditHours;
}

void Student::printNames() { // print method that just prints first and last names
	std::cout << firstName << " " << lastName;
}
