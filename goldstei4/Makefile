CC=gcc
CFLAGS=-Wall

all : encoding decoding

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

encoding : encoding.o
	$(CC) $(CFLAGS) -o encoding encoding.o

decoding : decoding.o
	$(CC) $(CFLAGS) -o decoding decoding.o
