# Makefile
# CSE 374 HW 5, Logan Krumholz

t9: t9.o trie.o
	gcc -Wall -g -std=c11 -o t9 t9.o trie.o

trie.o: trie.c trienode.h
	gcc -Wall -g -std=c11 -c trie.c

t9.o: t9.c trienode.h
	gcc -Wall -g -std=c11 -c t9.c

clean:
	rm -f *.o t9 *~
