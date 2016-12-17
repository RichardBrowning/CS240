// address.h
// Copyright 2016 K. Mensing
#ifndef ADDRESS_H_EXISTS
#define ADDRESS_H_EXISTS
#include <string> // includes the string library so we can use it
#include <iostream> // includes iostream to extend ostream for our friend operator
class Address {
	private: // private attributes
		std::string addLine1; // address line 1
		std::string addLine2; // address line 2
		std::string City; // which city
		std::string State; // zipcode
		std::string zipCode; // zipcode
		// void validateAddress(); // originally was going to validate the address, ran out of time

	public:
		Address(); // default address constructor that initializes everything to nil
		Address(std::string, std::string, std::string, std::string, std::string); // alternative constructor that takes strings for everyting
		~Address(); // Destructor, including the date and address objects it creates on the heap
		std::string getAddLine1(); // addline1 getter
		void setAddLine1(std::string); // addline1 setter
		std::string getAddLine2(); // addline2 getter
		void setAddLine2(std::string); // addline2 setter
		std::string getCity(); // city getter
		void setCity(std::string); // city stter
		std::string getState(); // state getter
		void setState(std::string); // state setter
		std::string getZipCode(); // zip getter
		void setZipCode(std::string); // zip setter
		friend std::ostream& operator << (std::ostream& os, const Address& a); // output stream that outputs the address info
		void printAddress(); // prints the whole address out in a formatted fashion
};
#endif
