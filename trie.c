/* trie implements a trie, made of trieNodes. This includes
   code to build, search, and delete a trie
   CSE374, HW5, 22wi 
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "trienode.h"

// Prototypes for helper functions 
void insert_helper(TrieNode *root, const char *key, const char *value);
char *search_helper(TrieNode *root, const char *key);
int delete_helper(TrieNode **root, const char *key);

// Inserts a new key-value pair into the trie 
void trie_insert(TrieNode *root, const char *key, const char *value) {
    insert_helper(root, key, value);
}

// Searches throiugh trie and returns value
char *trie_search(TrieNode *root, const char *key) {
    return search_helper(root, key);
}

// Deletes a pair from trie if needed 
int trie_delete(TrieNode **root, const char *key) {
    return delete_helper(root, key);
}

// Inserts a key-value into trie
void insert_helper(TrieNode *root, const char *key, const char *value) {
    if (*key == '\0') {
        root->value = strdup(value);
        return;
    }
    int index = *key - 'a';
    if (root->children[index] == NULL) {
        root->children[index] = trie_create_node();
    }
    insert_helper(root->children[index], key + 1, value);
}

// Helper function to search for a key in the trie
char *search_helper(TrieNode *root, const char *key) {
    if (*key == '\0') {
        return root->value;
    }
    int index = *key - 'a';
    if (root->children[index] == NULL) {
        return NULL;
    }
    return search_helper(root->children[index], key + 1);
}

// Helper function to delete a key-value pair from the trie
int delete_helper(TrieNode **root, const char *key) {
    if (*root == NULL) {
        return 0;
    }
    if (*key == '\0') {
        free((*root)->value);
        (*root)->value = NULL;
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if ((*root)->children[i] != NULL) {
                count++;
            }
        }
        if (count == 0) {
            trie_delete_node(*root);
            *root = NULL;
            return 1;
        }
        return 0;
    }
    int index = *key - 'a';
    if ((*root)->children[index] == NULL) {
        return 0;
    }
    int deleted = delete_helper(&((*root)->children[index]), key + 1);
    if (deleted) {
        (*root)->children[index] = NULL;
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if ((*root)->children[i] != NULL) {
                count++;
            }
        }
        if ((*root)->value == NULL && count == 0) {
            trie_delete_node(*root);
            *root = NULL;
            return 1;
        }
    }
    return 0;
}
