test-clover : test-clover.o clover.o 
	gcc -o test-clover test-clover.o clover.o
test-clover.o : test-clover.c 
	gcc -c test-clover.c
clover.o : clover.c clover.h
	gcc -c clover.c clover.h
