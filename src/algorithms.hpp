#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "table.hpp"
#include "iolzw.hpp" // binary file write & read
#include "array.hpp" // a faster array for decompression

int decode(TableLzwArr& table, int code, FILE* outputFile);

void compress(FILE *inputFile, FILE *outputFile) {
	int prefix = getc(inputFile);
	if (prefix == EOF) {
		return;
	}
	
	int character;
	int code;
	
	TableLzw table;
	
	while ((character = getc(inputFile)) != (unsigned)EOF) {
		
		//if entry (p+c) already exists, prefix is the found entry
		if ((code = table.search(prefix, character)) != -1)
			prefix = code;
		else {
			// encode prefix
			writeCode(outputFile, prefix);
			
			// add (p+c) to table if it has free entries
			if (table.size() < tableSizeMax)
				table.add(prefix, character);
			
			prefix = character;	//swap the prefix
		}
	}
	
	writeCode(outputFile, prefix); // encode last char
	
	if(leftover)
		fputc(leftoverBits << 4, outputFile);
}

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
    int character; 
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
