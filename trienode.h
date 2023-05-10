/* trienode.h contains structure and function declarations for 
 * a trie implementation
 * CSE374, HW5, Logan Krumholz 
 * 5/10/23
*/

#ifndef TRIENODE_H
#define TRIENODE_H

#include <stdio.h>

#define MAXLEN 50
#define BRANCHES 11

// trieNode is one node in an 9-tree, where branches correspond to
// # and the T9 alphabet.
typedef struct trieNode {
  struct trieNode * branches[BRANCHES];
  char *word;
} trieNode;

// given a word list (dict), build a trie that holds
// each word.  Return pointer to the root node.
trieNode * build_tree();

// given a pattern, return the word stored in the
// appropriate trieNode
char* get_word(trieNode *root, char *pattern);
int T9conversion(char letter);
void build_trie(trieNode * root, char * s);
trieNode * find_nodes(trieNode * root, char * number);
// deletes the entire tree branching from root
void malfree(trieNode *root);


#endif
