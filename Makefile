# Makefile - responsible for compiling and running program t9, as well as clean after executed
# CSE 374 HW 5, Logan Krumholz
# 5/10/23

t9: t9.o trie.o
	gcc -Wall -g -std=c11 -o t9 t9.o trie.o

t9.o: t9.c trienode.h
	gcc -Wall -g -std=c11 -c t9.c	

trie.o: trie.c trienode.h
	gcc -Wall -g -std=c11 -c trie.c


clean:
	rm -f *.o t9 *~
