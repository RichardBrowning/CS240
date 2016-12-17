//bubble.c
//famous bubble sort
//implement the swap algorithm with pointers
//Kristopher Mensing, IUPUI CSCI 240, Fall 2016 HW1
//2016-08-29

#include <stdio.h>                                 // imports the standard input/output library
#define MAX 9                                      // the maximum size of the array

int values[] = {7, 3, 9, 4, 6, 1, 2, 8, 5};        //the array we start with

//function prototypes
				
void swap(int* a, int* b){                         // the function that takes 2 pointers to integers and swaps the values between them
	int temp = *a;                             //assigns the start value of "a" to a temporary variable for safekeeping
	*a = *b;                                   //assigns "b" value to the "a" address
	*b = temp;                                 //assigns the old version of "a" that was kept safe in the placeholder to the "b" address
}


void printValues(){                                // the function that prints out the array
	int counter3;                              // initializes the counter for the upcoming for loop
	printf("(");                               // prints the opening bracket in the terminal
	for (counter3 = 0; counter3 < MAX; counter3++){  // Begins the for loop that starts at the 0th element, continues by counting integerwise to the end
		printf("%d", values[counter3]);          // Prints the integer that exists at the array indexed at the value of the counter
	}
	printf(")\n");                             // Prints the close bracket, creates a newline character
}

void sort(){                                       // function that sorts te array
	int counter1, counter2;                    // initializes the two counters for the nested for loops
	for (counter1 = 0; counter1 < (MAX - 1); counter1++){ // this for loop starts at the beginning of the array, and continues until the 2nd to last element
		for (counter2 = 0; counter2 < (MAX - 1); counter2++){ // this loop starts at the beginning of the array, and continues until the 2nd to last element
			if (values[counter2] > values[counter2 + 1]) { // this conditional statement evaluates if the left value is greater than the right value
				swap(&values[counter2], &values[counter2 + 1]); // this function swaps the values if the previous condition is true
				printValues();     // prints out the current state of the array
			}
		}
	}
}


int main(){
	printf("Before: \n");                     // prints out "Before: " and then creates a newline
	printValues();                            // prints out the original array
	sort();                                   // calls the sort function, sorting the array
	printf("After: \n");                      // prints out "After: " and creates a newline
	printValues();                            // prints out the final array
	return(0);                                // if main is successfully completed, returns 0 as is convention
} // end main
