CC=g++
CFLAGS= -g -Wall
library: library.o book.o main.o
	$(CC) $(CFLAGS) library.o book.o main.o -o library
library.o: library.h book.h library.cpp
	$(CC) $(CFLAGS) -c library.cpp
book.o: book.h book.cpp
	$(CC) $(CFLAGS) -c book.cpp
main.o: main.cpp library.h book.h
	$(CC) $(CFLAGS) -c main.cpp
clean:
	rm -f *.o
	rm library
run: library
	./library
