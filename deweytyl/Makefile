# Citation: Makefile by Henry Walker 20 April 2008                              

# Compiler:                                                                     
CC=gcc

# Compilation flags:                                                            
CFLAGS= -ansi -lMyroC

# build rules:                                                                  
all:

# program components:                                                           
project100: project100.o
        $(CC) -o main project100.o
project100o: project100.c
        $(CC) -c project100.c

# cleanup rules:                                                                
clean:
        rm -f *.o *~ core*
