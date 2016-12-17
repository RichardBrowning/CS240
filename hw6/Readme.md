Overview
The purpose of this lab is to give you a deeper understanding of memory management by forcing you to utilize the standard C++ heap structure as much as possible.

Build a normalized student record system. Create a class to represent student data. You will also create classes to handle other specific types of data including dates and addresses. Your system will include all the necessary header files, cpp files, and a main program to incorporate the larger system.

Details
Imagine a university wants to keep track of the following data about each student:

First name
Last name
address line 1
address line 2
city
state
zip code
date of birth month
date of birth day
date of birth year
anticipated completion month
anticipated completion day
anticipated completion year
gpa
credit hours completed
It is obvious that we will need a student class to contain all this data. However, the principles of data design indicate that the address should be its own class, as should the date. Your program should then have at least three classes: address, date, and student. Student will have two instances of date and one of address among its data members.

Process
Build all the classes you will need for this project. Each class should have a separate header file. This file contains only the class definition. Ensure your headers use the #ifndef structure described in lecture, and include whatever other headers they need.

Build a cpp file for each class which contains the code implementation of the class. This code file will include the class header file and any other headers and libraries needed.

Build a main program that imports all the needed classes and tests them. You'll then modify this program.

Create a makefile to control the compilation process. The instructor will test the program by running the make utility, so be sure your makefile works. If you use a visual editor like code::blocks, you'll still need to create and test a makefile for your project. Note IDE's have tools to build make files automatically, but they are often terrible. Make your own. It's a great idea to include clean and run builds in your makefile.

Use git to manage your versions. There is no way you can prove you used git, but learn how to use it now. It's ideal for a larger project like this with multiple files.

All instances of your classes should be stored separately on the heap.  That is to say, all should make use of the 'new' keyword.  Your program will be tested using the Valgrind tool to ensure you have responsibly deallocated memory when your are done with it.

The complete project
When the classes are done, create a main program which does the following:

Load up student data from a text file. All the needed information for the students should be in a text file, with each student's information on one line. We will provide you with a file with student data. There will be 50 students.
Store student data on the heap Student data will be a large array, so it should be stored on the heap. Ensure you've also removed heap data when necessary.
List all data for all students in a report format Create a method of the Student class to print a report about every student into a separate text file called "fullReport.txt".
Create a simpler list that prints only the last and first name of each student into a separate text file called "shortReport.txt".
Output a list of student names in alphabetical order Print the list in alphabetical order  into a separate text file called "alphaReport.txt".
Note: You may not use any pre-constructed classes from the c++ standard template library (vectors, sets, etc).  You MAY construct your own (if you reallllly wanna go there).  Additionally, any instances of the classes you write need to be stored separately on the heap by utilizing the keyword new.

Here is the format you may use for a line of student data in your text file:

Surname,GivenName,StreetAddress,Address2,City,State,ZipCode,Birthday,Graduation,GPA,Credit Hours Complete<end of line>
Note that the text file provided by your recitation leader might be slightly different. Use the data you're given.


Here is an example of what it may look like:

Fry,Lock,123 Hillside Drive North Brunswick NJ 57237,08,22,1970,05,15,2012,4.00,90

Turning it in
This project will consist of a number of smaller files. Your program should expect an input file titled "students.dat" (which can be found in Files>resources>content>group>fa15 in csci 24000 22360).  Keep in mind the test file has a line of inputs first.  You'll have a .cpp and a .h file for each class, a main.cpp file, a data file, and a makefile with make, make run and make clean commands (you may find make debug and make valgrind useful, though these are not required). Please turn in all files together in .zip format. Be sure all your files are properly documented.
