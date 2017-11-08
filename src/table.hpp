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

class Table {
	public:
	struct Node *table, *tail;
	
	void create() {
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
		if (this->table != NULL) this->tail->next = node;
		else this->table = node;
		this->tail = node;
		node->next = NULL;
	}
	
	void freeTable() {
		struct Node* aux;
		while (this->table != NULL) {
			aux = this->table;
			this->table = this->table->next;
			free(aux);
		}
	}
	
	int search(int prefix, int character) {
		struct Node *node;
		for (node = this->table; node != NULL; node = node->next) { // ...traverse forward
			if (node->prefix == prefix && node->character == character) return node->index;
		}
		return -1;
	}
	
	
	int returnPrefix(int index) {
		struct Node *node;
		for (node = this->table; node != NULL; node = node->next) { // ...traverse forward
			if (node->index == index) return node->prefix;
		}
		return -1;
	}
	
	int returnCharacter(int index) {
		struct Node *node;
		for (node = this->table; node != NULL; node = node->next) { // ...traverse forward
			if (node->index == index) {
				//printf("\nNODE %i %i %i\n", node->value, node->prefix, node->character);
				return node->character;
			}
		}
		return -1;
	}
	
	void insertEntry(int prefix, int character, int index) {
		struct Node *node;
		node = (struct Node *)malloc(sizeof(struct Node));
		node->index = index;
		node->prefix = prefix;
		node->character = character;
		//printf("\n(%i) = (%i) + (%i)\n", node->value, node->prefix, node->character);
		addNode(node);
	}
};

#endif