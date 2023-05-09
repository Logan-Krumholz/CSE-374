CC = gcc
CFLAGS = -Wall -Werror -std=c11

all: tnine

tnine: tnine.o trienode.o
	$(CC) $(CFLAGS) -o tnine tnine.o trienode.o

tnine.o: tnine.c trienode.h
	$(CC) $(CFLAGS) -c tnine.c

trienode.o: trienode.c trienode.h
	$(CC) $(CFLAGS) -c trienode.c

test: tnine
	./tnine dictionary.txt < test.txt

clean:
	rm -f *.o tnine

.PHONY: all clean test
