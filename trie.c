/*
 * trie.c 
 * CSE 374 HW 5 Logan Krumholz
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "trienode.h"

// Create empty trie 
trieNode * build_tree() {
  trieNode * node = (trieNode *) malloc(sizeof(trieNode));
  node -> word = NULL;
  int i;
  for (i = 0; i < 11; i++) {
    node -> branches[i] = NULL;
  }
  return node;
}

// T9 conversion 
int T9conversion(char letter) {
  switch (tolower(letter)) {
    case 'a': case 'b': case 'c': return 2;
    case 'd': case 'e': case 'f': return 3;
    case 'g': case 'h': case 'i': return 4;
    case 'j': case 'k': case 'l': return 5;
    case 'm': case 'n': case 'o': return 6;
    case 'p': case 'q': case 'r': case 's': return 7;
    case 't': case 'u': case 'v': return 8;
    case 'w': case 'x': case 'y': case 'z': return 9;
    default: return 0;
  }
}

// Translate word by building trie
void build_trie(trieNode * root, char * s) {
  trieNode * current = root;
  int length = strlen(s);
  char * text = (char *) malloc(length);
  if (text != NULL) {
    strncpy(text, s, length - 1);
    text[length - 1] = '\0';
  }
  int i = 0;
  while (s[i] != '\n') {
    int digit = T9conversion(s[i]);
    if (digit == 0) {
      // Remove excess chars not alphabet
      i++;
      continue;
    }
    if (current -> branches[digit] == NULL) {
      current -> branches[digit] = build_tree();
    }
    current = current -> branches[digit];
    i++;
  }
  while (current -> branches[10] != NULL) {
    current = current -> branches[10];
  }
  if (current -> word == NULL) {
    current -> word = text;
  } else {
    current -> branches[10] = build_tree();
    current = current -> branches[10];
    current -> word = text;
  }
}

// Traverse Trie given word
trieNode * find_nodes(trieNode * root, char * number) {
  trieNode * cur = root;
  int i;
  for (i = 0; i < strlen(number); i++) {
    if (number[i] != '#') {
      int digit = number[i] - '0';
      if (digit < 2 || digit > 9) {
        // ignore invalid digits
        continue;
      }
      if (cur -> branches[digit] == NULL) {
        return NULL;
      }
      cur = cur -> branches[digit];
    } else {
      if (cur -> branches[10] == NULL) {
        return NULL;
      }
      cur = cur -> branches[10];
    }
  }
  return cur;
}

// Recursively disconnect by freeing
void malfree(trieNode * root) {
  int i;
  for (i = 0; i < 11; i++) {
    if (root -> branches[i] != NULL) {
      malfree(root -> branches[i]);
      free(root -> branches[i]);
    }
  }
  if (root -> word != NULL) {
    free(root -> word);
  }
}
