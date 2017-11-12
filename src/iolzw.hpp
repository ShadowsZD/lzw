#ifndef IOLZWHPP
#define IOLZWHPP

#include <stdio.h>
#include <stdbool.h>

bool leftover = false;
char leftoverBits;

// Simulation of 2 writeCode calls
// writeCode(123);
	// print (12)
	// letfoverBits = 3

// writeCode(456)
	// leftoverAndCode = 34
	// print(34)
	// print(56)

void writeCode(FILE * output, int code) {
    if(leftover){
        char leftoverAndCode = (leftoverBits << 4) + (code >> 8);
		// code has 3 hexes, 12 bits
		// code = (MS hex) + (hex) + (LS hex)
		// leftoverAndCode = (leftoverBits) + (code MS hex)
        fputc(leftoverAndCode, output);
		// leftover written
        leftover = false;
		
		// code = (hex) + (LS hex)
		code = code & 0xff;
		
        fputc(code, output);
    } else {
		// leftoverBits is the last hex of code that couldn't get written with fputc
		// since fputc writes 2 hexes (1 char, 8 bits)
		// leftoverBits = (LS hex)
        leftoverBits = code & 0xF;
        leftover = true;
		
		//write: code >> 4
		//      00001111
		//write: leftover << 4 + code >> 8
		//write: code & 0xff
        
		// 321 452 478
		// code = (MS hex) + (hex)
        fputc(code >> 4, output);
    }
}

//12 34 56
// codf1 = 12
// tmp = 34
// codf2 = 56
// cod1 = tmp >> 4
// cod2 = tmp & 0xf
// codf1 = codf1 << 4 + cod1
// codf2 = cod2 << 8 + codf2
int readBinary(FILE * input) {
    int code = fgetc(input);    
    if (code == EOF) return 0;

    if (leftover > 0) {
		//shift 8 left because code = 8 + 4 = 12 bits
        code = (leftoverBits << 8) + code;
        leftover = 0;
    } else {
        int nextCode = fgetc(input);
        // save leftover, the LS hex
        leftoverBits = nextCode & 0xF;
        leftover = 1;
        
        code = (code << 4) + (nextCode >> 4);
    }
    return code;
}

void writeRemainder(FILE * output){
	if(leftover){
		printf("Tem leftover /n");
		fputc(leftoverBits << 4, output);
	}
}

#endif