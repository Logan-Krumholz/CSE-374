CC = gcc
CFLAGS = -Wall -Werror -std=c11
OBJS = t9.o trienode.o

all: t9

t9: $(OBJS)
	$(CC) $(CFLAGS) -o t9 $(OBJS)

t9.o: t9.c trienode.h
	$(CC) $(CFLAGS) -c t9.c

trienode.o: trienode.c trienode.h
	$(CC) $(CFLAGS) -c trienode.c

test: t9
	./t9 dictionary.txt < test.txt

clean:
	rm -f *.o t9

.PHONY: all clean test
