#ifndef DICTIONARY
#define DICTIONARY

#include <iostream>
#include <stdio.h>
#include <stdlib.h>	

struct Entry {
	int code;
	int prefix;
	int character;
};

class TableLzw {
public:
	ssize_t size;
	Entry arr[4096];
	
	TableLzw() {
		size = 0;
		Entry ent;
		int i;
		for (i = 0; i < 256; ++i) {
			ent.prefix = -1;
			ent.character = i;
			ent.code = i;
			add(ent);
		}
	}
	
	void add(Entry ent) {
		arr[size] = ent;
		size++;
	}
	
	void add(int prefix, int character) {
		Entry ent;
		ent.code = size;
		ent.prefix = prefix;
		ent.character = character;
		//printf("\n(%i) = (%i) + (%i)\n", ent.code, ent.prefix, ent.character);
		add(ent);
	}
	
	int search(int prefix, int character) {
		for (int i = 0; i < size; ++i) {
			if (arr[i].prefix == prefix && arr[i].character == character){
				if(i != arr[i].code)
					std::cout << "found diff " << i << ":" << arr[i].code << std::endl;
				return arr[i].code;
			}
		}
		return -1;
	}
	
	
	int prefix(int code) {
		for (int i = 0; i < size; ++i) {
			if (arr[i].code == code)
				return arr[i].prefix;
		}
		return -1;
	}
	
	int character(int code) {
		for (int i = 0; i < size; ++i) {
			if (arr[i].code == code) {
				//printf("\nEntry %i %i %i\n", arr[i].code, arr[i].prefix, arr[i].character);
				return arr[i].character;
			}
		}
		return -1;
	}
};

#endif