CC=g++
CFLAGS = -g -Wall -Wpedantic -std=c++11
main: main.o matrix.o useful.o 
	$(CC) $(CFLAGS) matrix.o main.o useful.o -o run
clean:
	rm -f *.o
	rm -f run
matrix.o: matrix.h matrix.cpp
	$(CC) $(CFLAGS) -c matrix.cpp
main.o: main.cpp matrix.h
	$(CC) $(CFLAGS) -c main.cpp
useful.o: useful.h useful.cpp
	$(CC) $(CFLAGS) -c useful.cpp
memtest: main
	valgrind --leak-check=yes ./run
run: main
	./run
