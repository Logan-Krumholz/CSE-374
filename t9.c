/*
 * t9.c - the main program uses the trieNode for T9 predictive text implementation
 * CSE 374 HW 5, Logan Krumholz
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "trienode.h"

// Pass in dictionary words and build tries accordingly
int main(int argc, char* argv[]) {
  FILE * fp;
  char line[100];
  trieNode * root = build_tree();
  fp = fopen(argv[1], "r");
  if (fp == NULL) {
    fprintf(stderr, "%s", "Could not open the file.\n");
    return 1;
  }
  while (fgets(line, 100, fp) != NULL) {
    build_trie(root, line);
  }
  fclose(fp);
  printf("Enter \"exit\" to quit.\n");
  char number[100];  
  trieNode * current = root;  
  // Runs until user enters "exit"
  while (true) {
    printf("Enter Key Sequence (or \"#\" for next word): \n");
    scanf("%s", number);
    if (strcmp("exit", number) == 0) {
      break;
    }
    if (number[0] == '#') {
      current = current->branch;
      if (current == NULL) {
        printf("There are no more T9onyms\n");
        current = root;
      }
    } else {
      current = find_nodes(current, number);
      if (current == NULL) {
        printf("Not found in current dictionary.\n");
        current = root;
      } else if (current->word) {
        printf("\'%s\'\n", current->word);
      } else {
        printf("No words found with this T9 sequence.\n");
      }
    }
  }
  // Free up malloc 
  free(root);
  return 0;
}
