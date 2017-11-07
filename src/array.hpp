#ifndef ARRAY
#define ARRAY

typedef struct{
    int prefix;
    int character; // the last char of string
} Entry;

void dictionaryArrayAdd(int prefix, int character, int index);
int dictionaryArrayPrefix(int index);
int dictionaryArrayCharacter(int index);

Entry dictionaryArray[4095];

// add prefix + character to the dictionary
void dictionaryArrayAdd(int prefix, int character, int index) {
    dictionaryArray[index].prefix = prefix;
    dictionaryArray[index].character = character;
}

int dictionaryArrayPrefix(int index) {
    return dictionaryArray[index].prefix;
}

int dictionaryArrayCharacter(int index) {
    return dictionaryArray[index].character;
}

#endif