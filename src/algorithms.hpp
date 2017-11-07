#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.hpp"
#include "file.hpp" // binary file write & read
#include "array.hpp" // a faster array for decompression

// the codes which are taking place of the substrings
#define codeBits 12
#define dictionarySize (0x1 << codeBits) -1 // 2^(codeBits) -1

void compress(FILE *inputFile, FILE *outputFile);
void decompress(FILE *inputFile, FILE *outputFile);
int decode(int code, FILE * outputFile);

void compress(FILE *inputFile, FILE *outputFile) {    
    int prefix = getc(inputFile);
    if (prefix == EOF) {
        return;
    }
	
    int character;
    int nextCode;
    int index;
    
    nextCode = 256;
	
    createDictionary();
    
    while ((character = getc(inputFile)) != (unsigned)EOF) {
        
        //if entry (p+c) already exists, prefix is the found entry
        if ((index = search(prefix, character)) != -1) prefix = index;
        else {
            // encode prefix
            writeBinary(outputFile, prefix);
            
            // add (p+c) to dictionary if it has free entries
            if (nextCode < dictionarySize) insertEntry(prefix, character, nextCode++);
            
            prefix = character;	//swap the prefix
        }
    }

    writeBinary(outputFile, prefix); // encode last char
    
    if (leftover > 0) fputc(leftoverBits << 4, outputFile); //?
    
    dictionaryDestroy();
}

void decompress(FILE * inputFile, FILE * outputFile) {
    int prevCode; 
	int currCode;
    int nextCode = 256;

    int firstChar;
    
    prevCode = readBinary(inputFile);
    if (prevCode == 0) {
        return;
    }
    fputc(prevCode, outputFile);
    
    while ((currCode = readBinary(inputFile)) > 0) {
    
        if (currCode >= nextCode) {  //next code increments everytime a new "code" is found
            fputc(firstChar = decode(prevCode, outputFile), outputFile);
        } else firstChar = decode(currCode, outputFile);
        
        // add a new code to the string table if dictionary still has slots
        if (nextCode < dictionarySize) dictionaryArrayAdd(prevCode, firstChar, nextCode++);
        
        prevCode = currCode;
    }
}

int decode(int index, FILE * outputFile) {
    int character; 
	int temp;

    if (index > 255) {
        character = dictionaryArrayCharacter(index);
        temp = decode(dictionaryArrayPrefix(index), outputFile);  //recursive call
    } else {
        character = index; // ASCII
        temp = index;
    }
    fputc(character, outputFile);
    return temp;
}
