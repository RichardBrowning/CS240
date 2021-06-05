## Unix
- Overview of linux command line
- connection to ssh
- navigating directories
- basic vim cammands
* Using tabs and windows
* Moving quickly through a file
* Searching and replacing
* Macros
* Folding
* Indentation
* Operating System commands
* Mapping and Commands
- SFTP file transfer
## Git
- Basic commands
## Intro to C
- stdio.h
- pointers, * and &
- pointers and arrays
## C pointer string
- pointers and strings
- pass by referencing vs. pass by value
- c-style input and output
- reading a full-line string

## derived data
- struct
- type definitiaon
- unions
- enumerations
- definition, declaration, implementation
- classes
- 
## gdb
- GDB CLI debugger
- compiling with symbol table
- setting a breakpoint
- viewing the list
- stepping throught with Next and Step
- testing variables with print and watch

## Intro to C++
- transition form c
- iostream
- cin cout
- function prototypes
- C++ string 
- std namespace and using

## C++ concepts
- constants and pointers
- references
- pass by ref/value in C++
- string comparison in c++
- scope resolution

## OOP
- Introduction
- basic UML
- classes
- constructors
- private data members
- ublic methods
- access methods
- implementation of class in C++
- testing class

- working with multiple classes
- instance of one class in another
- association and aggregation
- testing classes in isolation
- building classes from UML

## Heaps and Stacks
- Difference between heap and stack memory allocation
- Using new keyword
- heap memory, stack pointers
- deleting heap memory
- using valgrind to test for memory leaks

## CPP ref
- strings in cpp
- using c libraries in c++
- cpp strings
- concatenation
- + and == operator overloading
- cpp references

## CPP inheritance
- Inheritance in C++
- setting data members to protected
- Indicating inheritance in header
- Creating a new constructor
- Creating new methods
- Overriding methods
- Inheritance, encapsulation, and polymorphism

## IO streams
- Overview of the ios and iostream classes
- Using getline and ignore for input
- Working with the input buffer
- output streams and filters
- Use of the stringstream object

## File I/O C++
- importing fstream library
- Opening a file for output
- Writing text files
- Getting input from files via a loop
- Using sstream for data type conversion
- Reading CSV data

##Deep Copy
- Creating a class with instance variables on the stack
- Shallow copy and stack data members
- Shallow copy and heap data members
- Why shallow copy can lead to tricky bugs
- implementing deep copy with a copy constructor in C++

# Overloading OP
- Friend functions in C++
- Overloaded operators
- Creating a custom numerical type
- Overloading addition
- Overloading output

# static members
- static data members in C++
- static methods in C++
- static keyword and class-level
- use of static elements to share between members of a class

#C++ templates
- Basic idea of templates
- indicating a dynamic data type
- Using standard collection templates
- Using standard algorithm templates

## sort custom
- using std::sort with custom class arrays
- building a custom class
- writing the boolean sort functions
- calling std::sort with custom functions

## managed ptrs exceptions
- Exception handling in c++
- unique pointers
- shared pointers
- compiler flag to force c++ 11

## Intro java
- Introduction to Java for C++ programmers
- import vs [#include]
- File-naming conventions
- public static void main(String[] args)
- Building a constructor
- Use of packages
- Review of Crypto in Java
- Compiling and Interpreting Java programs

## java inheritance
- Overview of creating a class in Java
- Building a subclass
- Overriding methods
- java and makefiles
- java and jdb

NOTE: My mistake in jdb was I was breaking on Critter.run, and it never got there because I was running GlitterCritter.  Had I set the breakpoint like this:

stop in GlitterCritter.main

It would have worked fine.

## Java File IO
- Exception-handling in Java
- Writing to a text file
- Reading from a text file
- Using object serialization
- Saving and loading a serializable object
- Saving and loading arrays of objects

## Java Packages 
- Namespaces and subdirectories
- Creating a jar file from the command line
- Writing a manifest file
- Specifying classpath and main class

## java abstraction
- overview of abstraction
- abstract classes
- abstract methods
- interfaces

## abstract of java
- Enumerations
- abstract classes
- abstract methods
- interfaces
- inheriting abstract classes
- implementing interfaces
- abstraction and polymorphism

## abstract of C++
- abstraction in c++
- virtual methods
- pure virtual methods
- creating an abstract class
- implementing abstract class
- simulating Java interfaces with purely abstract classes

## big O
- Computer science as an experimental science
- Looking at sorting algorithms
- comparint bubble, selection, insertion sorts
- The n^2 nature of these sorts
- Looking at merge and quick sort
- Moving to an nLog(n) behavior
- big-O notation and code efficiency
- Estimating the efficiency of an algorithm

## LinkedList
- Concepts of Linked Lists
- Linked List Nodes
- Creating a basic LL
- Traversing
- Appending nodes to the end of the list
- Inserting and Deleting nodes
- Building a LinkedList class

## Linked List variants
- Reviewing Linked lists in multiple languages
- Creating a double-linked list
- Creating a double-linked node
- Working with Queues
- Working with Stacks

## linkedlist CPP
- Creating a Linked List in C++
- Creating a Node header / class
- Crating a LinkedList header / class
- Storing Nodes on the heap
- Writing a destructor for a linked list
- Exploring linked lists in c and Python

## MultiList generics
- Building a simple multi-list
- Creating a generic node
- building a generic linked list
- building a linked list with a custom class

## java recursion
- Recursion.
- Basic tail-call recursion examples in Java including Collatz conjecture,
- counting iterations, memory analysis in jdb, a number-guesser example, and recursively traversing a linked list

## java binary trees
- Trees, basic binary search trees, tree traversal algorithms.

##X11
- Using a local version of JDK
- Adding xming / xquartz for X11 support
- Installing Java on Linux Subsystem for Windows
- Setting the display variable
- Using putty with X11 forwarding