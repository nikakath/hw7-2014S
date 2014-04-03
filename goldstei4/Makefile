CC=gcc
CFLAGS=-Wall

all : encoding decoding

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

% : %.o
	$(CC) $(CFLAGS) -o $@ $<

