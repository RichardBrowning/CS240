// student.h for heap of students
// Copyright 2016 K. Mensing
#ifndef STUDENT_H_EXISTS
#define STUDENT_H_EXISTS
#include "address.h"
#include "date.h"
#include <string>

class Student {
	private: // private attributes
		std::string firstName; // first name variable
		std::string lastName; // last name variable
		Address * studentAddress; // address object
		Date * birthDay; // birthday object
		Date * gradDay; // graduation date object
		std::string gradePointAvg; // gpa variable
		std::string completeCreditHours; // completed credit hours object

	public:
		Student(); // default constructor
		Student(std::string); // additional constructor that accepts a line from the datfile
		void set(std::string); // sets all the parts of Student taking a line from the datfile
		~Student(); // destructor
		std::string getFirstName(); // firstname getter
		void setFirstName(std::string); // firstname setter
		std::string getLastName(); // lastname getter
		void setLastName(std::string); // lastname setter
		Address getStudentAddress(); // address getter
		void setStudentAddress(Address*); // address setter
		Date getBirthDay(); // birthday getter
		void setBirthDay(Date*); // birthday setter
		Date getGradDay(); // gradday getter
		void setGradDay(Date*); // gradday setter
		std::string getGPA(); // gpa getter
		void setGPA(std::string); // GPA setter
		std::string getCreditHours(); // credithours getter
		void setCreditHours(std::string); // credit hours setter
		void printFull(); // prints the full object to stdout
		void printNames(); // prints just the name
		friend std::ostream& operator<<(std::ostream& os, const Student& s); // stream object that outputs the entire object
};
#endif // STUDENT_H
