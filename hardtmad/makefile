# Citation: Makefile by Henry Walker 20 April 2008 

# Use the gcc compiler
CC = gcc

# Set compilation flags
CFLAGS = -ansi

# Build rules

all:

# List of program components, what other files they depend on and how to compile each 

program: program.o header.o
	$(CC) -o main main.o procedures.o

program.o: program.c header.h
	$(CC) 4(CFLAGS) -c program.c

header.o: header.c header.h
	$(CC) $CFLAGS) -c header.c

# Rules for cleaning up
# "make clean" invokes this command
# Cleans directory (deletes object files, old emacs source versions, and core dumps)

clean: 
	rm -f *.o *- core*
