#ifndef DECOMPRESSHPP
#define DECOMPRESSHPP

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

#include "iolzw.hpp"
#include "tableArray.hpp"

int decode(TableLzwArr& table, int code, FILE* outputFile);

void decompress(FILE* inputFile, FILE* outputFile) {
	TableLzwArr table;
	int prevCode; 
	int currCode;
	int nextCode = 256;

	int firstChar;

	prevCode = readBinary(inputFile);
	if(prevCode == 0){
		return;
	}
	fputc(prevCode, outputFile);
	
	while ((currCode = readBinary(inputFile)) > 0) {
		if(currCode < nextCode){
			firstChar = decode(table, currCode, outputFile);
		} else { // if the code is not in the table
			fputc(firstChar = decode(table, prevCode, outputFile), outputFile);
		}
		// add new code to the table if not full
		if(nextCode < tableSizeMax){
			table.add(prevCode, firstChar, nextCode);
			nextCode++;
		}
		
		prevCode = currCode;
	}
}

int decode(TableLzwArr& table, int code, FILE* outputFile) {
	char character;
	std::string rdecoded;
	
	while (code > 255) {
		// get the last character of this code
		character = table.character(code);
		rdecoded.push_back(character);
		// continue with the prefix
		code = table.prefix(code);
	}
	// code is now ASCII
	rdecoded.push_back(code);
	// rdecoded contains reverse the string equivalent to the code
	for(ssize_t c = rdecoded.size()-1; c > -1; --c)
		fputc(rdecoded.at(c), outputFile);
	
	return code;
}


#endif