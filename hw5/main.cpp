// Copyright 2016 K.Mensing
// CS240
// Parsing and File I/O assignment
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
const int NUMSTRINGS = 3;
const int NUMLINES = 10;

int main() {
    std::ifstream input_file("input.txt"); // initializes the input stream
    std::ofstream output_file("output.txt"); // initializes the output stream
    if ( !input_file ) { // checks to see if the input file opened successfully
        std::cout << "An error occurred opening the input file" << std::endl; // returns error if necessary
    }

    if ( !output_file ) { // check to see if the output file opened successfully
        std::cout << "An error occurred opening the output file" << std::endl;
    }
    std::string currentLine;
    while (getline(input_file, currentLine)) { // while there's input, the loop keeps goin
	    std::istringstream istream(currentLine); // initializes the input stream
	    int integers[3]; // gives a place to store the numbers
	    char delimiter; // placeholder for the delimiter (e.g. the comma)
	    istream >> integers[0]; // pipes the stream into the array
	    for ( int i = 1; i < 3; ++i ) { // loops through until we have 3 numbers in the array (increments first!)
		    istream >> delimiter >> integers[i]; // throws away the commas to keep the integers in the array
	    }
	    std::string lineText; // a place to keep the text lines
	    getline(input_file, lineText); // gets the text line
	    int sum = 0; // initializes the sum variable each time to zero
	    for ( int j = 1; j < 3; j++ ) { // loops through the array to sum it
		    sum += integers[j]; // sums the array such that we have the final number
	    }
	    std::ostringstream ostream; // initializes the output stream
	    ostream << lineText; // pipes the linetext to the output stream in order to get ready to write it to the file
	    for ( int k = 0; k < sum; k++ ) { // strings the text together the appropriate amount of times
		    ostream << "," << lineText; // does what I said on the previous line
	    }
	    output_file << ostream.str() << std::endl; // ouputs to the file, creates a newline
    }
    input_file.close(); // cleanly closes the input file
    output_file.close(); // cleanly closes teh output file
    return 0; // returns 0 upon success (as is tradition)
}
