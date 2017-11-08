#ifndef ARRAY
#define ARRAY

typedef struct{
    int prefix;
    int character; // the last char of string
} EntryArr;

EntryArr tableArray[4095];

// add prefix + character to the table
void tableArrayAdd(int prefix, int character, int code) {
    tableArray[code].prefix = prefix;
    tableArray[code].character = character;
}

int tableArrayPrefix(int code) {
    return tableArray[code].prefix;
}

int tableArrayCharacter(int code) {
    return tableArray[code].character;
}

#endif