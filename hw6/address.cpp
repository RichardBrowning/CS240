// address.cpp for heap of students project
// Copyright 2016 K.Mensing
#include "address.h" // includes the header file
#include <iostream> // includes iostream for the stream operations

Address::Address() { // default constructor that initializes everything to nothing
	Address::addLine1 = "";
	Address::addLine2 = "";
	Address::City = "";
	Address::State = "";
	Address::zipCode = "00000";
}

Address::Address(std::string add1, std::string add2, std::string city, std::string state, std::string zip) { // constructor that lets us create the object with nondefault values
	Address::addLine1 = add1;
	Address::addLine2 = add2;
	Address::City = city;
	Address::State = state;
	Address::zipCode = zip;
}

Address::~Address() {} // default destructor since address doesn't create anyting on the heap

std::string Address::getAddLine1() { // getter for 1st address line
	return Address::addLine1;
}

void Address::setAddLine1(std::string input) { // setter for 1st address line
	Address::addLine1 = input;
}

std::string Address::getAddLine2() { // getter for 2nd address line
	return Address::addLine2;
}

void Address::setAddLine2(std::string input) { // setter for 2nd address line
	Address::addLine2 = input;
}

std::string Address::getCity() { // getter for City
	return Address::City;
}

void Address::setCity(std::string city) { // setter for city
	Address::City = city;
}

std::string Address::getState() { // getter for state
	return Address::State;
}

void Address::setState(std::string state) { // setter for state
	Address::State = state;
}

std::string Address::getZipCode() { // getter for zip code
	return Address::zipCode;
}

void Address::setZipCode(std::string zip) { // setter for zip code
	Address::zipCode = zip;
}

std::ostream& operator << (std::ostream& os, const Address& a) { // output stream for the object that outputs all the student information. Friend of ostream
	os << a.addLine1 << " " << a.addLine2 << " " << a.City << ", " << a.State << " " << a.zipCode;
	return os;
}

void Address::printAddress() { // prints out the address
	std::cout << addLine1 << " " << addLine2 << ", " << City << ", " << State << zipCode;
}
