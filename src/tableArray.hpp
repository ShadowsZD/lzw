#ifndef TABLEARRAYHPP
#define TABLEARRAYHPP

#include "lzw.hpp"

class TableLzwArr{
public:
	entry arr[tableSizeMax];
	
	TableLzwArr() {}
	
	// add prefix + character to the table
	void add(int prefix, int character, int code) {
		arr[code].prefix = prefix;
		arr[code].character = character;
	}
	
	int prefix(int code) {
		return arr[code].prefix;
	}
	
	int character(int code) {
		return arr[code].character;
	}
};


#endif