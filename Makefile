CC = gcc
CFLAGS = -Wall -Werror -std=c11

all: t9

t9: t9.o trienode.o
	$(CC) $(CFLAGS) -o t9 t9.o trienode.o

t9.o trienode.o: trienode.h

test: t9
	./t9 dictionary.txt < test.txt

clean:
	rm -f *.o t9

.PHONY: all clean test
