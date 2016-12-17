// matrix.h
// Copyright 2016 K. Mensing
#ifndef MATRIX_H_EXISTS
#define MATRIX_H_EXISTS
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
// The matrix does basic matrix operations and math, similar to what you'd expect from linear algebra class

class Matrix {
	private:
		int numRows(); // returns the number of rows the matrix has
		int numCols(); // returns the number of columns the matrix has
		bool rowsMatch(); // determines whether the dimension of the rows matches
		bool isSquare(); // determines if the matrix is square
		std::vector<float> Row(int); // returns a row given an index
		std::vector<float> Column(int); // returns a column given an index
		void setRows(std::vector<std::vector<float> >); // sets rows to a vector of vectors of type float
		Matrix min(int i, int j); // returns the minor matrix given the position that you want the minor for
		void rowSwap(int, int); // swaps rows
		bool rowIsZeroes(int); // determines if a row is completely zeroes
		std::vector<float> vectorMultiply(float, std::vector<float>); // multiplies a vector of floats by a float

	public:
		Matrix(); // default constructor (empty)
		Matrix(std::vector<std::vector<float> >); // constructor that takes a vector of vectors of float type
		~Matrix(); // default destrutor
		std::vector<std::vector<float> > rows; // the primary field of interest in this object, the rows
		Matrix scalarMultiply(float); // a scalar multiplication function that multiplies each element by the inputted float
		Matrix multiply(Matrix); // multiplies the current matrix (A) by the inputted matrix (B), e.g. A*B = result
		float determinant(); // takes the determinant if the matrix is square
		float dotProduct(std::vector<float>, std::vector<float>); // takes the dot product of two matching vectors
		void printToFile(std::string); // prints the matrix to a CSV file with the inputted string as the name
		std::vector<float> crossProduct(std::vector<float>, std::vector<float>); // takes the cross product of two vectors in R3
		void print(); // prints the matrix to the screen, seperated by commas
		Matrix Transpose(); // returns the transpose of the matrix
		Matrix inverse(); // returns the inverse of a square matrix
		Matrix solution(Matrix); // returns the solution vector (x), given matrix A and b, e.g. A*x=b, where b is a column vector of 
					// floats and A is square
};
#endif
