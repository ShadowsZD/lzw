#ifndef DICTIONARY
#define DICTIONARY

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <tuple>

#include "lzw.hpp"

class TableLzw {
public:
	std::map<entry, int> map;
	
	ssize_t size(){ return map.size(); }
	
	TableLzw() {
		int i;
		// add ASCII characters
		for (i = 0; i < 256; ++i) {
			add(prefixNULL, i);
		}
	}
	
	void add(int prefix, int character) {
		entry tmp(prefix, character);
		int code = map.size();
		map[tmp] = code;
		//printf("\n(%i) = (%i) + (%i)\n", ent.code, ent.prefix, ent.character);
	}
	
	int search(int prefix, int character) {
		entry tmp(prefix, character);
		auto search = map.find(tmp);
		if ( search != map.end() ) {
			return search->second;
		} else {
			return -1;
		}
	}
};

#endif