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

	int lastChar;

	prevCode = readBinary(inputFile);
	if(prevCode == 0){
		return;
	}
	fputc(prevCode, outputFile);

	while ((currCode = readBinary(inputFile)) > 0) {

		if(currCode >= nextCode){
			//next code increments everytime a new "code" is found
			fputc(lastChar = decode(table, prevCode, outputFile), outputFile);
		} else lastChar = decode(table, currCode, outputFile);
		
		// add a new code to the string table if table still has slots
		if(nextCode < tableSizeMax)
			table.add(prevCode, lastChar, nextCode++);
		
		prevCode = currCode;
	}
}

int decode(TableLzwArr& table, int code, FILE* outputFile) {
	char character; 
	int temp;

	if (code > 255) {
		character = table.character(code);
		temp = decode(table, table.prefix(code), outputFile);  //recursive call
	} else {
		character = code; // ASCII
		temp = code;
	}
	fputc(character, outputFile);
	return temp;
}


#endif