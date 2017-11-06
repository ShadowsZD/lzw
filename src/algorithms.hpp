#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.hpp"
#include "file.hpp" // binary file write & read
#include "array.hpp" // a faster array for decompression

enum {
    dictionarySize = 4095,
    codeLength = 12, // the codes which are taking place of the substrings
    maxValue = dictionarySize - 1
};

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
	
    dictionaryInit();
    
    while ((character = getc(inputFile)) != (unsigned)EOF) {
        
        // check to see if entry (p+c) already exists
        if ((index = dictionaryLookup(prefix, character)) != -1) prefix = index;
        else { // ...no, try to add it
            // encode s to output file
            writeBinary(outputFile, prefix);
            
            // add prefix+character to dictionary
            if (nextCode < dictionarySize) dictionaryAdd(prefix, character, nextCode++);
            
            // prefix = character
            prefix = character; //... output the last string after adding the new one
        }
    }
    // encode s to output file
    writeBinary(outputFile, prefix); // output the last code
    
    if (leftover > 0) fputc(leftoverBits << 4, outputFile);
    
    // free the dictionary here
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
    
        if (currCode >= nextCode) {
            fputc(firstChar = decode(prevCode, outputFile), outputFile); // S+C+S+C+S exception
            //printf("%c", firstChar);
            //appendCharacter(firstChar = decode(previousCode, outputFile));
        } else firstChar = decode(currCode, outputFile); // first character returned! [1.]
        
        // add a new code to the string table
        if (nextCode < dictionarySize) dictionaryArrayAdd(prevCode, firstChar, nextCode++);
        
        prevCode = currCode;
    }
}

int decode(int code, FILE * outputFile) {
    int character; int temp;

    if (code > 255) {
        character = dictionaryArrayCharacter(code);
        temp = decode(dictionaryArrayPrefix(code), outputFile); // recursion
    } else {
        character = code; // ASCII
        temp = code;
    }
    fputc(character, outputFile);
    //printf("%c", character);
    //appendCharacter(character);
    return temp;
}
