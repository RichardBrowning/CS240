// Kristopher Mensing, Fall2016, IUPUI CSCI240
// HW 3, C++ OOP
// Horse Racing Assignment
// Copyright 2016 (to satisfy Cpplint)
#include <time.h> // imports the C time library
#include <iostream> // gives us the ability to input/output stuff to terminal
#include <cstdlib> // gives us srand and stuff

const int defaultRaceLength = 24; // change this to change the race length
const int defaultNumberHorses = 5; // change this to change the default number of horses

class Horse{
 private:
     int position; // this tracks the position the horse is in on the track
 public:
     Horse(); // constructor
     void advance(); // the randomized advance function
     int getPosition(); // returns the position of the horse
};

Horse::Horse() { // constructor
    Horse::position = 0; // defaults by placing the horse at zero
}

void Horse::advance() {
    int chance = rand() % 2; // gives either random 1 or 0 (flipping a coin basically)
    if ( chance == 1 ) { // tests if the horse can advance
        position++; // if yes, then advance the horse
    }
}

int Horse::getPosition() {
    return position; // literally just advances he horse
}

class Race{ // the race class
 private:
     Horse h[defaultNumberHorses]; // the "stable" array of horses
 public:
     int length; // the length of the race
     Race(); // race constructor
     explicit Race(int length); // race constructor with alternate length (I get warnings from my linter unless it's marked explicit)
     void printLane(int horseNum); // prints the lane of each horse during each turn
     void start(); // starts the racing process
};

Race::Race() { // the race constructor
    length = defaultRaceLength; // sets the race to default length
}

Race::Race(int length) { // the alternate race constructor
    Race::length = length; // sets the race length to whatever length is input to this function
}

void Race::printLane(int horseNum) { // prints each horses lane
    for (int i = 0; i < length; i++) { // iterates over the length of the race
        int loc = h[horseNum].getPosition(); // returns the location of each horse
        if (i == loc) { // tests to see if the horse is at the position we're iterating through
		std::cout << horseNum + 1; // if yes, then prints the horse's number
        } else {
		std::cout << "."; // prints a period to represent empty track elsewise
        }
    }
    std::cout << std::endl; // creates a newline
}

void Race::start() {
    bool continueon = true; // this keeps track whether the race is finished
    for (int n = 0; n < defaultNumberHorses; n++) { // iterates through the stable of horses at the beginning of the race
        printLane(n); // prints the lane of the horse that we have an n for
    }

    std::cout << "\nReadysetgo" << std::endl; // prints out at the start of the race
    std::cin.ignore(); // gets an enter from the CLI

    while (continueon) { // this tests whether the race is finished
        for (int number = 0;  number < defaultNumberHorses; number++) { // iterates through the stable
            h[number].advance(); // runs the advance function
            printLane(number); // prints the lane of each horse
            if (h[number].getPosition() == (length)) { // tests true if a horse has finished the race
                continueon = false; // sets the variable to false and kills the while loop
		std::cout << "Horse " << number + 1 << " is winner" << std::endl; // prints which horse is the winner
            }
        }
	std::cout << "\nPress enter for another turn" << std::endl; // prompts for input at the end of each turn
	std::cin.ignore(); // gets the enter
    }
}

int main() {
    srand(time(NULL)); // seeds random
    std::cout << "Press Enter to begin" << std::endl; // prompts for user input
    std::cin.ignore(); // gets the enter
    Race race; // initializes the race object
    race.start(); // activates the start function
    std::cout << "End of race" << std::endl; // prints that the race is over
    std::cin.ignore(); // gets an enter
    return(0);
}

