CFLAGS = gcc -Wall -ggdb3

all: upperToLower

upperToLower : upperToLower.c charUtils.o charUtils.h
	${CFLAGS} -o upperToLower upperToLower.c charUtils.o

charUtils.o : charUtils.c charUtils.h
	${CFLAGS} -c charUtils.c
