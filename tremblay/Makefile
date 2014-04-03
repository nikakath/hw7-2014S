CFLAGS=-Wall
LDFLAGS=-lm
USERNAMES=nystromj-clarkand-tremblay
APPS=column-ui m-sort s-sort name-game reverser shirley
UTESTS=sort-utests index-of-utests largest-utests column-utests string-reverse-utests psp-examples swap-utests

.PHONY: all clean test distclean package


all: $(APPS)


test: $(UTESTS)


clean:
	rm -f *.o *~ *# *.tar *.gz


distclean:
	rm -f *.o *~ *# *.tar *.gz $(APPS) $(UTESTS)


package:$(USERNAMES).hw7.tar.gz

$(USERNAMES).hw7.tar: README.txt *.c *.h *script Makefile
	tar cvf $@ $^

$(USERNAMES).hw7.tar.gz: $(USERNAMES).hw7.tar
	gzip -f $<

column: column.o column-ui.o string-utils.h
	$(CC) $(CFLAGS) $(LDFLAGS) -o column column.o column-ui.o

column-ui: column-ui.o column.o string-utils.h
	$(CC) $(CFLAGS) $(LDFLAGS) -o column-ui column-ui.o column.o

column-utests: column-utests.o column.o string-utils.h
	$(CC) $(CFLAGS) $(LDFLAGS) -o column-utests column-utests.o column.o

index-of-utests: index-of-utests.o index-of.o string-utils.h
	$(CC) $(CFLAGS) $(LDFLAGS) -o index-of-utests index-of-utests.o index-of.o

largest-utests: largest-utests.o largest.o string-utils.h
	$(CC) $(CFLAGS) $(LDFLAGS) -o largest-utests largest-utests.o largest.o

name-game: name-game.o the-name-game.o string-utils.h
	$(CC) $(CFLAGS) $(LDFLAGS) -o name-game the-name-game.o name-game.o

psp-examples: psp-examples.o print-sequential-prefixes.o string-utils.h
	$(CC) $(CFLAGS) $(LDFLAGS) -o psp-examples psp-examples.o print-sequential-prefixes.o

reverser: reverser.o string-reverse.o swap.o string-utils.h
	$(CC) $(CFLAGS) $(LDFLAGS) -o  reverser reverser.o string-reverse.o swap.o

shirley: shirley.o the-name-game.o string-utils.h
	$(CC) $(CFLAGS) $(LDFLAGS) -o  shirley shirley.o the-name-game.o

m-sort: m-sort.o merge-sort.o string-utils.h
	$(CC) $(CFLAGS) $(LDFLAGS) -o  m-sort m-sort.o merge-sort.o

s-sort: s-sort.o index-of-largest.o index-of.o largest.o selection-sort.o swappa.o string-utils.h
	$(CC) $(CFLAGS) $(LDFLAGS) -o  s-sort s-sort.o index-of-largest.o index-of.o largest.o selection-sort.o swappa.o

sort-utests: sort-utests.o index-of-largest.o index-of.o largest.o selection-sort.o merge-sort.o swappa.o string-utils.h
	$(CC) $(CFLAGS) $(LDFLAGS) -o  sort-utests sort-utests.o index-of-largest.o index-of.o largest.o selection-sort.o merge-sort.o swappa.o

string-reverse-utests: string-reverse-utests.o string-reverse.o swap.o string-utils.h
	$(CC) $(CFLAGS) $(LDFLAGS) -o string-reverse-utests string-reverse-utests.o string-reverse.o swap.o

swap-utests: swap-utests.o swap.o swappa.o string-utils.h
	$(CC) $(CFLAGS) $(LDFLAGS) -o swap-utests swap-utests.o swap.o swappa.o
