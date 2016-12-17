// matrix.cpp
// Copyright 2016 K. Mensing
#include "matrix.h"

// the implementation of the matrix class

void printV(std::vector<float> v) { // prints the contents of a vector of floats on the screen, seperated by commas
	std::vector<float>::iterator it; // a regular old vector iterator

	for(it = v.begin(); it != v.end(); ++it) { //iterates through each element
		std::cout << *it << ","; // outputs each element of the vector to the screen seperated by a comma
	}
	std::cout << std::endl; // outputs a newline
}

Matrix::Matrix() { }// default constructor

Matrix::Matrix(std::vector<std::vector<float> > input) { // takes a vector of vectors of floats and assigns them to the rows
	Matrix::rows = input;
}

Matrix::~Matrix() {} // Default destructor (all we need)

std::vector<float> Matrix::Row(int i) { // returns a row vector at the given index
	return this->rows[i];
}

std::vector<float> Matrix::Column(int i) { // returns a column vector at this given index
	std::vector<float> column; // initializes the column vector
	std::vector<std::vector<float> >::iterator it; // initializes a vector iterator
	for(it = this->rows.begin(); it != this->rows.end(); ++it) { // iterates through the matrix
		std::vector<float> ph = *it; // pushes back a single element from the row
		column.push_back(ph[i]); // pushes back the element of ph
	}
	return column; // returns the column vector at the end
}


void Matrix::printToFile(std::string fileName) { // prints to the given file
	std::ofstream output; // the output stream
	output.open(fileName.c_str()); // opens the file with the inputted name
	std::vector<std::vector<float> >::iterator it; // creates a vOv of floats iterator
	std::vector<float>::iterator it2; // creates a vector of floats iterator
	for(it = this->rows.begin(); it != this->rows.end(); ++it) { // iterates through each row
	    std::vector<float> ph = *it; // evaluates the first iterator, to return the appropriate row
	    for(it2 = ph.begin(); it2 != ph.end(); ++it2) { // iterates through each element of the row
	        output << *it2 << ','; // outputs each element of the row seperated by commas
	    }
	    output << std::endl; // seperates each row with a newline
	}
	output.close(); // closes cleanly
}

std::vector<float> Matrix::vectorMultiply(float m, std::vector<float> in) { // multiplies a vector by a constant float
	std::vector<float> multiplied; // creates the resultant vector
	std::vector<float>::iterator it; // creates an iterator
	for(it = in.begin(); it != in.end(); ++it) { // iterates through the vector from begining to end
		multiplied.push_back(m * (*it)); // pushes back the result of multiplying each element by the inputted float
	}
	return multiplied; // returns the resulting vector
}

void Matrix::setRows(std::vector<std::vector<float> > q) { // setter for rows
	this->rows = q;
}

int Matrix::numRows() { // returns number of rows in the matrix
	return (this->rows.size());
}

int Matrix::numCols() { // returns number of columns in the first row
	return (this->rows[0].size());
}

bool Matrix::rowsMatch() { // this function determines whether the dimension of the rows match each other (as they should)
	std::vector<int> sizes; // this vector is going to contain all the sizes of the rows
	std::vector<std::vector<float> >::iterator it; // initializes the iterator that we're going to use to loop thru.
	bool equal = true; // default value
	for(it = this->rows.begin(); it != this->rows.end(); ++it) { // this for loop iterates through the rows and puts their size into a vector
		sizes.push_back(((*it).size()));
	}
	for(unsigned int i = 0; i < (sizes.size() - 1); ++i){ // this for loop iterates throw the vector of sizes, and if any two are not equal, makes this function false
		if (sizes[i] != sizes[i + 1]) {
			equal = false; // returns false if each element doesn't match the next one
		}
	}
	return equal;
}

void Matrix::rowSwap(int a, int b) { // swaps rows with indices a and b (useful for row reduction)
	std::swap(this->rows[a], this->rows[b]); // uses STL algorithm to swap quicklyy
}

Matrix Matrix::scalarMultiply(float n) { // this just implements scalar multiplication. If I have time I'm going to set this up using threading
	std::vector<std::vector<float> >::iterator it; // initializes the iterator for the rows
	std::vector<std::vector<float> > multiplied; // initializes the resultant vector of vectors
	for(it = this->rows.begin(); it != this->rows.end(); ++it) { // iterates through each row
		std::vector<float> ph = *it; // creates a holder for the row
		multiplied.push_back(Matrix::vectorMultiply(n, ph)); // applies vectorMultiply to each row
	}
	Matrix mult = multiplied; // initializes the returned matrix
	return mult; // returns the resulting matrix
}

bool Matrix::rowIsZeroes(int n) { // determines if a row with index n is completely zeroes
	bool isZeroes = true; // default return
	std::vector<float>::iterator it; // creates iterator
	for(it = this->rows[n].begin(); it != this->rows[n].end(); ++it) { //iterates through the supplied row
		if (*it != 0){ // if iterated value is not zero, return false
			isZeroes = false;
		}
	}
	return isZeroes;
}

float Matrix::dotProduct(std::vector<float> a, std::vector<float> b){ // implements dot product of 2 vectors of matching dimensions
	float product;
	if (a.size() != b.size()){ // vectors have to have matching dimensions
		throw "Mismatched vector dimension"; // throws exception
	} else {
		for(unsigned int i = 0; i < a.size(); i++){ // iterates through
			product = product + (a[i] * b[i]);  // sums up the product
		}	
	}
	return product;
}

std::vector<float> Matrix::crossProduct(std::vector<float> a, std::vector<float> b) { // computes the cross product of two vectors in r3
	std::vector<float> product; // initializes the resulting vector
	if ((a.size() != 3) || (b.size() != 3)) { // vectors have to be in R3 for this to work
		throw "Incorrect vector dimension";
	} else {
		product.push_back((a[1] * b[2]) - (a[2] * b[1])); // first element of cross product
		product.push_back(((-1) * (a[0] * b[2])) + (a[2] * b[0])); // second element of cross product
		product.push_back((a[0] * b[1]) - (a[1] * b[0])); // third element of cross product
	}
	return product;
}

Matrix Matrix::multiply(Matrix B) { // given a matrix of matching dimensions, multiplies the existing matrix by the given matrix
	Matrix multiplied; // initializes the resultant
	int A_rows = this->numRows(); // placeholder for the nubmer of rows in A
	int A_cols = this->numCols(); // holds number of columns in A
	int B_rows = B.numRows(); // number of rows in B
	int B_cols = B.numCols(); // number of columns in B
	std::vector<std::vector<float> > init(A_rows, std::vector<float>(B_cols)); // empty vOv of floats
	multiplied.rows = init; // sets multiplied's rows to zeroes

	if (A_cols != B_rows) { // These have to match in order to successfully multiply
		throw "Dimension mismatch";
	} else { 
		for(int i = 1; i <= A_rows; i++) { // iterates thru A's rows
			for(int j = 1; j <= B_cols; j++) { // iterates thru B's columns
				float sum = 0; // sum holder
				for(int k = 1; k <= A_cols; k++) { // iterates thru A's columns
					sum = sum + ((this->rows[i-1])[k-1] * (B.rows[k-1])[j-1]); // multiplies A's rows values by 
												   // B's columns and sums for each position
				}
				(multiplied.rows[i-1])[j-1] = sum; // assigns the appropriate value in the marix
			}
		}

	}
	return multiplied; // returns the matrix
}

Matrix Matrix::min(int row, int column) { // this returns the minor for the element at position a,b
	Matrix minor; // initializes an empty matrix
	int num_rows = this->numRows(); // what it says
	int num_cols = this->numCols(); // what it says

	if ((num_rows <= 1) || (num_rows <=1)) { // has to be nonzero
		throw "Dimension mismatch";
	} else {
		// for each row that's not the row provided:
		// return a new row vector that joins the lhs and rhs of the row, omitting the column that's provided
		for(int x = 0; x < num_rows; x++){ // iterates thru rows
			if(x == row){ // need to skip the row that we're in
				// do nothing, skip it
			} else {
				std::vector<float> v1; // holding vector
				for(int y = 0; y < column; y++) { // iterates thru columns up to the input column
					v1.push_back((this->rows[x])[y]); // pushes back the appropriate value
				}

				for(int z = (column + 1); z < num_cols; z++){ // iterates thru columns after the inputted column
					v1.push_back((this->rows[x])[z]); // pushes back the appropriate value
				}
				minor.rows.push_back(v1); // pushes back each row
			}
		}
	}
	return minor; // returns the resulting matrix
}

bool Matrix::isSquare() { // tests if the matrix is square
	bool sq = false; // default value
	if (this->numRows() == this->numCols()) { // gotta match
		sq = true;
	}
	return sq;
}

void Matrix::print() { // prints the matrix to the terminal seprated by commas and newlines
	std::vector<std::vector<float> >::iterator it2; // creates an iterator for each row
	std::vector<float>::iterator it; // creates an iterator for each element in each row

	for(it2 = this->rows.begin(); it2 != this->rows.end(); ++it2) { // iterates every row
		for(it = (*it2).begin(); it != (*it2).end(); ++it) { // iterates through each element of the  row
	    		std::cout << *it << ","; // prints each element seperated by a comma
		}
		std::cout << std::endl; // after each row, prints a newline
	}
}

float Matrix::determinant() { // computes the determinant of a square matrix (recursive)
	float det = 0; // initial value
	std::vector<Matrix> minors; // creates a vector of matrices to hold all the minors
	std::vector<float> subDeterminants; // creates a vector of subDeterminants
	std::vector<float> rowVals; // holds the row values
	int order = this->numRows(); // returns the order of the square matrix
	if (!(this->isSquare())) {  // matrix has to be square for this to work
		throw "Non-square matrix";
	} else if((this->numRows()) == 2) { // returns the evaluated determinant for a 2x2 matrix
	       det = (((this->rows[0])[0]) * ((this->rows[1])[1])) - (((this->rows[0])[1]) * ((this->rows[1])[0])); // base case
	} else {
		det = 0;
		rowVals = this->rows[0]; // iterates thru the first row because it doesn't really matter
		int num_colums = rowVals.size(); // returns size of rowVals
		for(int i = 0; i < num_colums; i++) { // iterates thru the matrix
			minors.push_back((this->min(0,i))); // returns minors of the first row
		}
		int j;
		for(j = 0 ; j < order; j++){ // iterates thru the vector of minor matrices
			det = det + (pow((-1), j) * rowVals[j] * minors[j].determinant()); // the recursive determinant formula
		}
	}
	return det;
}

Matrix Matrix::Transpose() { // swaps rows and columns of the matrix
	unsigned int num_rows_init = this->rows.size(); // number of rows
	unsigned int num_cols_init = this->rows[0].size(); // number of columns in the first row
	std::vector<std::vector<float> > ph(num_cols_init, std::vector<float>(num_rows_init));	// initializes an empty vOv floats
	for(std::vector<int>::size_type i = 0; i < num_cols_init; i++) { // iterates through each row
		for(std::vector<int>::size_type j = 0; j < num_rows_init; j++) { // iterates thru elements in each row
			ph[i][j] = this->rows[j][i]; // this swaps rows with column
		}
	}
	Matrix transposed(ph); // creates the actual matrix
	return transposed; // returns the matrix
}

Matrix Matrix::inverse() { // returns the inverse of the matrix;
	float det = this->determinant(); // returns the determinant of this matrix
	float inv_det= 1 / det; // this gives us the inverse of the determinant so we can multiply it by the matrix of cofactors
	Matrix cof_det; // one of the placeholder matrices
	Matrix other_ph; // other placeholder matrix
	std::vector<std::vector<float> > dets; // vOv of all the determinants
	std::vector<float> ph; // a placeholder vector that we can store intermediate values in
	std::vector<std::vector<float> >::iterator it1; // an iterator over the rows of the matrix
	int j = 0; // a counter
	for(it1 = (this->rows).begin(); it1 != (this->rows).end(); ++it1) { // iterates through the rows of this matrix
		for(int i = 0; i < (this->numCols()); i++) { // iterates through the values of this row
			cof_det = this->min(j, i); // creates the minor for each element
			ph.push_back(cof_det.determinant()); // stores the determinant of each minor in the placholder matrix
		}
		dets.push_back(ph); // pushes back each ph for each row
		ph.clear(); // clears the ph each row
		j++; // increments the couner
	}
	other_ph.rows = dets; // creates an intermediate matrix of cofactors
	Matrix inv = (other_ph.Transpose()).scalarMultiply(inv_det); // returns the actual inverse matrix
	return inv; // returns inv to program
}

Matrix Matrix::solution(Matrix b_vec) { // generates the solution for a square matrix
	Matrix inverse = this->inverse(); // takes the inverse of this matrix (why is must be square)
	Matrix sol = inverse.multiply(b_vec); // multiplies the inverse by the provided b vector to return the x vector
	return sol; // returns x vector
}
