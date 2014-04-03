CFLAGS = -Wall
.PHONY : clean

stopwatch : stopwatch.o
	$(CC) $(CFLAGS) -o stopwatch stopwatch.o

stopwatch.o : stopwatch.c
	$(CC) $(CFLAGS) -c stopwatch.c

clean:
	-rm -f *.o *~
