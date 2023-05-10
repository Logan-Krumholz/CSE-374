#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "trienode.h"

// run_session run the on-going decoding interaction with the
// user.  It requires a previously build wordTrie to work.
void run_session(trieNode *wordTrie);

// build_trie builds a trie using the words from dictionary.
// Returns the root node of the trie.
trieNode* build_trie(FILE *dictionary) {
  trieNode *root = create_node();
  char word[MAX_WORD_LEN];

  while (fgets(word, MAX_WORD_LEN, dictionary)) {
    insert_word(root, word);
  }

  return root;
}

int main(int argc, char **argv) {
  FILE *dictionary = NULL;
  trieNode *wordTrie = NULL;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s [DICTIONARY]\n", argv[0]);
    return EXIT_FAILURE;
  } else {
    dictionary = fopen(argv[1], "r");
    if (!dictionary) {
      fprintf(stderr, "Error: Cannot open %s\n", argv[1]);
      return EXIT_FAILURE;
    }
  }

  // Build tries
  wordTrie = build_trie(dictionary);

  // run interactive session
  run_session(wordTrie);

  // Clean
  delete_trie(wordTrie);
  fclose(dictionary);

  return EXIT_SUCCESS;
}
