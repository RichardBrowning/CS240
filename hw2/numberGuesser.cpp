#include <iostream>
#include <string>
// To satisfy cpplint:
// Copyright 2016 Kristopher Mensing
// inverse of Andy's number guessing program
// User thinks of a number
// Computer guesses a number (randomly at first)
// user respeonds with "high" "low" or "correct"
// continue until computer has guessed the number
// should be able to succeed in 7 attempts
// range is between 1 and 100 inclusive
// Kristopher Mensing, CS240 HW2

int main() {
        int guess;                                       // initalizes the guess integer
        int maximum = 100;                               // sets the maximum value for the guessing range
        int minimum = 1;                                 // sets the minimum value for the guessing range
        bool keepgoing = true;                           // sets the logic variable so that the do/while loop will work
        int turn = 0;                                    // sets the turn counter to 0 so that we can accurately count the number of tries it takes
        std::string user_input;                          // initalizes the user input string so that we can tell whether we're high, low, or correct
        std::cout << "Choose a number between " << minimum << " and " << maximum << std::endl; // prints the prompt
        do {                                             // do/while is just something I prefer more than just a while loop
           turn++;                                       // increments the turn counter
           guess = minimum + (maximum - minimum)/2;      // guesses directly between the maximum and minimum
           std::cout << "My guess is: " << guess << std::endl;          // prints the guess out
           std::cout << "\n Is it high, low, or correct?" << std::endl; // asks whether the guess is correct
           std::cin >> user_input;                                      // gets user input
           if (user_input.compare("high") == 0)                         // is true if the user inputs that the number is high
	   {
               std::cout << "My guess was high!" << std::endl;          // prints out that the computer's guess was high
               maximum = guess - 1;                                     // changes the new maximum to one less than the guess
           }
           else if (user_input.compare("low") == 0)                     // is true if the user inputs that the number is low
	   {
               std::cout << "My guess was low!" << std::endl;           // prints out that the computer's guess was high
               minimum = guess + 1;                                     // changes the new minimum to one more than the guess
           }
           else if (user_input.compare("correct") == 0)                 // is true if the user inputs correcet 
	   {
               keepgoing = false;                                       // this changes the logic variable so that the do/while will terminate
               std::cout << "I guessed correctly!" << std::endl;        //prints out that the computer guessed right
           }
           else                                                         // in case the user inputs something not in my other conditions 
	   {
               std::cout << "invalid input" << std::endl;               // prints out that the user inputted invalid statement
               break;                                                   // stops everything
           }
               
        } while (keepgoing);
        std::cout << "It took " << turn << " turns for me to guess the right number." << std::endl; // prints out how many turns it took
}
