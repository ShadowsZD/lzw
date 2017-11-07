#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "algorithms.hpp"

FILE *inputFile;
FILE *outputFile;

#define pathMaxLength 4096

int main(int argc, char** argv){
	char c;
	int length;
	char temp[pathMaxLength];
	
	while (( c = getopt(argc, argv, "c:d:")) != -1){
		switch (c){
			case 'c':	//compress
			
				inputFile = fopen(optarg, "r");
				if(inputFile == NULL){
					printf("Error opening input");
					return 0;
				}
				
				outputFile = fopen(strcat(optarg, ".lzw"), "w+b");
				if(outputFile == NULL){
					printf("Error creating output");
					fclose(inputFile);
					return 0;
				}
				
				compress(inputFile, outputFile);

				break;
			case 'd':	//decompress
				inputFile = fopen(optarg, "rb");
				if(inputFile == NULL){
					printf("Error opening input");
					return 0;
				}
				
				length = strlen(optarg) - 4;	//-4 removes .lzw from file
				strncpy(temp, optarg, length);	
				temp[length] = '\0';
				outputFile = fopen(temp, "w"); 
				if(outputFile == NULL){
					printf("Error creating output");
					fclose(inputFile);
					return 0;
				}
				
				decompress(inputFile, outputFile);
				
				break;
			case ':':
			// missing option argument
				fprintf(stderr, "%s: option '-%c' requires an input file\n", argv[0], optopt);
				break;
			default:
				fprintf(stderr, "Usage: %s [-c] [-d] inputFile\n", argv[0]);
				exit(EXIT_FAILURE);
			break;
		}
	}
	
	fclose(inputFile); 
	fclose(outputFile);
	
    return 0;
}

