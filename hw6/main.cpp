// main.cpp for Heap of Students Project
// Copyright 2016 K.Mensing
#include <sstream>
#include <fstream>
#include "student.h"

void swap(std::string * s1, std::string * s2) { // the swap function that changes string locations
	std::string temp = *s1; // placeholder for s1 value
	*s1 = *s2; // swaps s2 to s1
	*s2 = temp; // puts original s1 value into s2
}

int i, j; // counter variables
void sortArray(std::string arr[]) { // does bubblesort, just like homework 1 with strings
	for(i = 0; i < 51; i++) {
		for(j = 0; j < (51- i - 1); j++) {
			if (arr[j] > arr[j+1]) { // in the string library, we can compare strings just like numbers
				swap(&arr[j], &arr[j+1]); // passing pointers to the swap function
			}
		}
	}
}

int main() {
	std::ifstream inFile; // the ifstream that represents the input
	std::string currentLine; // the current line that we're on in the file

        std::ofstream fullReport; // output stream for the full report
        std::ofstream shortReport; // output stream for the short report
        std::ofstream alphaReport; // output stream for the alphabetical report

        fullReport.open("fullReport.txt"); // opens the textfile for fullreport
        shortReport.open("shortReport.txt"); // opens the textfile for short report
        alphaReport.open("alphaReport.txt" ); // opens the textfile for alpha report
	std::stringstream ss; // initializes a stringstream

	Student *studArray = new Student[51]; // array of pointers to each student student object on the heap
	int arrayIndex = 0; // arrayIndex is the counter that we'll iterate

	inFile.open("students.dat"); // opens the provided datafile
	std::string inputline; // initializes a string that will hold one line of the file at a time
	for(arrayIndex = 0; arrayIndex < 51; arrayIndex++) { // 51 lines in the test file, so we need to getthem all
		getline(inFile, inputline); // each line gets streamed into inputline
		studArray[arrayIndex].set(inputline); // creates a student object with each line of the file
	}

	int a, b, c; // initializes the counters for each of 3 operations

	for (a = 0; a < 51; a++) { // loop to generate the full report
		fullReport << studArray[a] << std::endl;
	}
	for (b = 0; b < 51; b++) { // loop to generate short report
		shortReport << studArray[b].getFirstName() << " " << studArray[b].getLastName() << std::endl;
	}
	std::string toBeSorted[51]; // initializes array of strings of first and last name to be sorted
        for (int k = 0; k < 51; k++) { // loop to create the content for the array and to assign each element
		toBeSorted[k] = studArray[k].getFirstName() + " " + studArray[k].getLastName();
	}
	sortArray(toBeSorted); // calls the function to sort the array
	for (c = 0; c < 51; c++) { // outputs the sorted array to the alphareport
		alphaReport << toBeSorted[c] << std::endl;
	}
        fullReport.close(); // closes the fullreport file
        shortReport.close(); // closes the shortreport file
        alphaReport.close(); // closes the alphareport file
	delete[] studArray; // destructor for all the student array object. For some reason valgrind says we're not deleting them all?
	return 0; // returns 0 on success of main as is convention
}
