#ifndef DICTIONARY
#define DICTIONARY
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int index;
    int prefix;
    int character;
    struct Node *next;
};

void createDictionary();
void addNode(struct Node *node);
void freeDictionary();
int search(int prefix, int character);
int returnPrefix(int index);
int returnCharacter(int index);
void insertEntry(int prefix, int character, int index);

struct Node *dictionary, *tail;

void createDictionary() {
    int i;
    struct Node *node;
    for (i = 0; i < 256; i++) {
        node = (struct Node *)malloc(sizeof(struct Node));
        node->prefix = -1;
        node->character = i;
        addNode(node);
    }       
}

void addNode(struct Node *node) {
    if (dictionary != NULL) tail->next = node;
    else dictionary = node;
    tail = node;
    node->next = NULL;
}

void freeDictionary() {
	struct Node* aux;
    while (dictionary != NULL) {
		aux = dictionary;
        dictionary = dictionary->next;
		free(aux);
    }
}

int search(int prefix, int character) {
    struct Node *node;
    for (node = dictionary; node != NULL; node = node->next) { // ...traverse forward
        if (node->prefix == prefix && node->character == character) return node->value;
    }
    return -1;
}

int returnPrefix(int index) {
    struct Node *node;
    for (node = dictionary; node != NULL; node = node->next) { // ...traverse forward
        if (node->index == index) return node->prefix;
    }
    return -1;
}

int returnCharacter(int index) {
    struct Node *node;
    for (node = dictionary; node != NULL; node = node->next) { // ...traverse forward
        if (node->index == index) {
            //printf("\nNODE %i %i %i\n", node->value, node->prefix, node->character);
            return node->character;
        }
    }
    return -1;
}

// add prefix + character to the dictionary
void insertEntry(int prefix, int character, int index) {
    struct Node *node;
    node = (struct Node *)malloc(sizeof(struct Node));
    node->index = index;
    node->prefix = prefix;
    node->character = character;
    //printf("\n(%i) = (%i) + (%i)\n", node->value, node->prefix, node->character);
    addNode(node);
}

#endif