#ifndef COMPRESSHPP
#define COMPRESSHPP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "iolzw.hpp"
#include "table.hpp"

void compress(FILE *inputFile, FILE *outputFile) {
	int prefix = getc(inputFile);
	if (prefix == EOF) {
		return;
	}
	
	int character;
	int code;
	
	TableLzw table;
	
	while ((character = getc(inputFile)) != EOF) {
		if ((code = table.search(prefix, character)) != -1) {
			// if entry (p+c) already exists
			// code is encoded (p+c)
			// the code found is the prefix for the next iteration
			prefix = code;
		} else { // no found entry (p+c) in table
			// prefix is used
			writeCode(outputFile, prefix);
			// add (p+c) to table
			table.add(prefix, character);
			// prefix is now the remaining character
			prefix = character;
		}
	}
	
	writeCode(outputFile, prefix); // encode last char
	
	if(leftover)
		fputc(leftoverBits << 4, outputFile);
}


#endif