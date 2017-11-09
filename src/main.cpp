
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "compress.hpp"
#include "decompress.hpp"

#define pathMaxLength 4096

int main(int argc, char** argv){
	FILE* inFile = NULL;
	FILE* outFile = NULL;
	char c;
	int len;
	char temp[pathMaxLength];
	
	while (( c = getopt(argc, argv, "c:d:")) != -1) {
		switch (c) {
			case 'c':	//compress
				inFile = fopen(optarg, "r");
				if (inFile == NULL) {
					printf("Error opening input");
					return 0;
				}
				
				outFile = fopen(strcat(optarg, ".lzw"), "w+b");
				if (outFile == NULL) {
					printf("Error creating output");
					fclose(inFile);
					return 0;
				}
				
				compress(inFile, outFile);
				
				break;
				
			case 'd':	//decompress
				len = strlen(optarg);
				if (strcmp(&optarg[len-4], ".lzw") != 0) {
					printf("Invalid input filename, no .lzw ext");
					return 0;
				}
				inFile = fopen(optarg, "rb");
				if (inFile == NULL) {
					printf("Error opening %s", optarg);
					return 0;
				}
				// remove .lzw from file
				len = strlen(optarg) - 4;
				memcpy(temp, optarg, len);
				temp[len] = '\0';
				
				outFile = fopen(temp, "w");
				if (outFile == NULL) {
					printf("Error opening %s", temp);
					fclose(inFile);
					return 0;
				}
				
				decompress(inFile, outFile);
				
				break;
				
			case ':':
			// missing option argument
				fprintf(stderr, "%s: option '-%c' requires an input file\n", argv[0], optopt);
				break;
			default:
				fprintf(stderr, "Usage: %s [-c] [-d] inFile\n", argv[0]);
				exit(EXIT_FAILURE);
			break;
		}
	}
	
	if (inFile != NULL)
		fclose(inFile);
	if (outFile != NULL)
		fclose(outFile);
	
    return 0;
}

