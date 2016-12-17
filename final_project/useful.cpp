// useful.cpp
// Copyright 2016 K. Mensing
#include "useful.h" // the header file for this cpp file
#include "matrix.h" // the header file for the matrix class

void printVector(std::vector<float> v) { // prints the contents of a vector of floats on the screen, seperated by commas
	std::vector<float>::iterator it; // creates an iterator over a vector of floats

	for(it = v.begin(); it != v.end(); ++it) { //iterates through each element
		std::cout << *it << ","; // outputs each element seperated by a comma
	}
	std::cout << std::endl; // creates a newline at the end
}

int mainMenu() { // the function that outputs the main menu options
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "1. Solve a square Linear System" << std::endl;
	std::cout << "2. Invert a Matrix" << std::endl;
	std::cout << "3. Find the Determinant of an n x n matrix" << std::endl;
	std::cout << "4. Find the dot products of 2 vectors in R3" << std::endl;
	std::cout << "5. Matrix Multiplication" << std::endl;
	std::cout << "6. Scalar Matrix Multiplication" << std::endl;
	std::cout << "7. Cross Product of two vectors in R3" << std::endl;
	std::cout << "8. Exit" << std::endl;

	int userSelection = 0;
	try 
	{
		std::cin >> userSelection; // tries to capture the user input
	}
	catch (...)
	{
		std::cout << "Exception occurred"  << std::endl; // in case things get retarded, throws an exception
	}
	return userSelection; // returns what the user inputted
}

std::string promptFilename() { // prompts the user for the filename they want to load in
	std::cout << "What is the filename for the matrix you want to load?" << std::endl; // outputs this text and a newline
	std::string fn; // initializes the filename string
	std::cin >> fn; // captures the user input
	return fn; // returns a string that has the filename
}

std::string promptFilenameOut() { // prompts the user for teh filename they want to output to
	std::cout << "What is the filename that you want to save the resultant to?" << std::endl; // outputs the text and a newline
	std::string fn; // initializes the filename string
	std::cin >> fn; // captures the user inpu
	return fn; // returns a filename string
}

void split(const std::string &s, char delim, std::vector<std::string> &elems) { // splits a string into a vector of strings at the provided delimiter
	std::stringstream ss; // initializes the stringstream
	ss.str(s); // loads the string s into the stringstream
	std::string item; // placeholder for each subpart of the line
	while (std::getline(ss, item, delim)) { // while there's still content seperated by the delimiter
		elems.push_back(item); // adds the content to the end of the vector of elements
	}
}

std::vector<std::vector<float> > getCSV() { // the CSV file parser
	std::string fileName = promptFilename(); // prompts the user for the filename they want to load from
	std::ifstream input_file(fileName.c_str()); // initializes the input stream
	if ( !input_file ) { // checks to see if the input file opened successfully
            std::cout << "An error occurred opening the input file" << std::endl; // returns error if necessary
        }
	std::string currentLine; // initializes the currentline placeholder
	std::vector<std::vector<float> > convertedFile; // initializes a vector of float ectors to load the content into
	std::vector<std::string> elems; // initializes a vector of string vectors as an intermediate container
	std::vector<float> floatholder; // a float number placeholder
    	while (getline(input_file, currentLine)) { // while there's input, the loop keeps goin
		split(currentLine, ',', elems); // aplits the line up by commas
		std::vector<std::string>::iterator it; // creates a vector of vector strings iterator
		for (it = elems.begin(); it != elems.end(); ++it) { // standard for loop over vector
			float holder = std::stof (*it); // converts string to float
			floatholder.push_back(holder); // pushes pack the placeholder into the floatholder vector
		}
		elems.clear(); // clears the vector of elements
		convertedFile.push_back(floatholder); // pushes back the floatholder vector into the converted file vOv
		floatholder.clear(); // clears the floatholder vector
        }
	input_file.close(); // cleanly closes the input file
	return convertedFile; // returns the vOv of floats
}
void solveHelper(){ // the helper file that actually gets stuff done upon user input
	std::vector<std::vector<float> > A = getCSV(); // gets the A matrix content
	std::vector<std::vector<float> > B = getCSV(); // gets the B marix Content
	Matrix mA(A); // initializes the matrix A
	Matrix mB(B); // initializes the matrix B
	Matrix solution = mA.solution(mB); // solves the system
	std::string fn = promptFilenameOut(); // prompts the user for the filename they want for the output
	solution.printToFile(fn); // prints the solution to the file
	std::cout << "Resulting Solution matrix is:" << std::endl; // prints a helpful string on the screen
	solution.print(); // prints the solution matrix
	std::cout << std::endl; // prints a newline
}

void invertHelper() { // bootstraps the inversion process between the UI and the object
	std::vector<std::vector<float> > A = getCSV(); // gets the contents of the matrix we want to invert
	Matrix mA(A); // initializes the matrix with the contents of A
	Matrix inverted = mA.inverse(); // actually calculates the inverse
	std::string fn = promptFilenameOut(); // prompts the user for a filename they wan to print to
	inverted.printToFile(fn); // prints the matrix to a file
	std::cout << "Resulting Inverted matrix is:" << std::endl; // nice descriptor
	inverted.print(); // prints the resulting matrix to the screen
	std::cout << std::endl; // prints newline
}

void determinantHelper(){ // bootstraps the determinant process between the UI and the object
	std::vector<std::vector<float> > A = getCSV(); // gets the contents of the file
	Matrix mA(A); // constructs a matrix with the contents of the file
	float det = mA.determinant(); // actually calculates teh determinant
	std::cout << "The determinant of the matrix is: " << det << std::endl; // prints out what the determinant is
}

void dotProductHelper(){ // bootstraps the dot product process between teh UI and the object
	Matrix mA; // initializes matrix A
	std::vector<std::vector<float> > A = getCSV(); // gets the contents of the first vector file
	std::vector<std::vector<float> > B = getCSV(); // gets the contents of the second vector file
	std::vector<float> i1 = A[0]; // gets the first (and only) element of the A matrix
	std::vector<float> i2 = B[0]; // gets the first (and only) element of the B matrix
	float product = mA.dotProduct(i1, i2); // calculates teh dot product of the two vectors
	std::cout << "The dot product of the matrix is: " << product << std::endl; // prints the dot product
}

void crossProductHelper(){ // bootstraps the cross product process between the UI and the object
	Matrix mA; // initializes a matrix
	std::vector<std::vector<float> > A = getCSV(); // gets contents of the first vector file
	std::vector<std::vector<float> > B = getCSV(); // gets the contents of the second vector file
	std::vector<float> product = mA.crossProduct(A[0], B[0]); // actually calculates the cross product
	Matrix mSol; // initializes a solution matrix
	mSol.rows.push_back(product); // pushes teh solution vector into the solution matrix
	std::string fn = promptFilenameOut(); // prompts user for a filename
	mSol.printToFile(fn); // prints solution matrix to the file
	std::cout << "Resulting Cross Product is: " << std::endl; // nice descriptor
	mSol.print(); // prints the solution
}

void multiplicationHelper(){ // bootstraps the multiplication process between the UI and the object
	std::vector<std::vector<float> > A = getCSV(); // gets the "A" matrix content
	std::vector<std::vector<float> > B = getCSV(); // gets the "B" matrix content
	Matrix mA(A); // constructs the A matrix object
	Matrix mB(B); // constructs the B matrix object
	Matrix solution = mA.multiply(mB); // constructs the solution matrix
	std::string fn = promptFilenameOut(); // prompts the user for an output filename
	solution.printToFile(fn); // prints the solution matrix to the user's desired filename
	std::cout << "Resulting multiplied matrix is:" << std::endl; // nice descriptor
	solution.print(); // prints out the resultant matrix
	std::cout << std::endl; // prints a newline
}

void scalarMultiplicationHelper(){ // bootstraps the multiplication process between the UI and the Matrix object
	std::cout << "What is the scalar you want to multiply the matrix by? " << std::endl; // prompts user
	std::string scalar; // initializes the string that will hold the scalar
	std::cin >> scalar; // collects the user's input
	float sc = std::stof(scalar); // converts user's input to a float so we can use it
	std::string fn = promptFilenameOut(); // prompts and gets the filename
	std::vector<std::vector<float> > A = getCSV(); // gets the input matrix
	Matrix mA(A); // initializes the matrix object with the contents from A
	Matrix solution = mA.scalarMultiply(sc); // does the scalar multiplication
	solution.printToFile(fn); // prints to the user's desired file
	std::cout << "Resulting scalar multiplied matrix is:" << std::endl; // nice descriptor
	solution.print(); // prints out the solution
	std::cout << std::endl; // prints a newline
}

bool decide(int choose) { // teh function that takes the user's inputted number and routes traffic; returns false upon exit or incorrect input
	bool d = true; // use this so that we can exit cleanly
	switch(choose) { // switch statement based on the user input
		case 1 : std::cout << "Solve a square linear system..." << std::endl;  // Solves a square linear system
			 solveHelper(); // calls the solver helper function
			 break;
		case 2 : std::cout << "Invert a square matrix..." << std::endl; // inverts a square matrix
			 invertHelper(); // calls the helper function
			 break;
		case 3 : std::cout << "Find the determinant of a square matrix..." << std::endl; // finds the determinant of a square matrix
			 determinantHelper(); // calls the helper function
			 break;
		case 4 : std::cout << "Find the dot product of two vectors..." << std::endl; // finds the dot product of to vectors in R3
			 dotProductHelper(); // class the helper function
			 break;
		case 5 : std::cout << "Matrix multiplication..." << std::endl; // multiplies 2 matching matrices
			 multiplicationHelper(); // calls the helper function
			 break;
		case 6 : std::cout << "Scalar multiplication..." << std::endl; // multiplies a matrix by a scalar
			 scalarMultiplicationHelper(); // calls the helper function
			 break;
		case 7: std::cout << "Cross Product..." << std::endl; // returns the cross product of 2 vectors in R3
			crossProductHelper(); // calls the helper function
			break;
		case 8: std::cout << "Exiting... " << std::endl; // exits
			d = false; // sets the output to false so that we can signal an exit
			break;
		default : std::cout << "Exiting... "<< std::endl; // exits upon unknown input
			d = false; // sets the output to false so we can signal an exit
			break;
	}	  
	return d;
}


