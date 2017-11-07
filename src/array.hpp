#ifndef ARRAY
#define ARRAY

typedef struct{
    int prefix;
    int character; // the last char of string
} Entry;

void tableArrayAdd(int prefix, int character, int index);
int tableArrayPrefix(int index);
int tableArrayCharacter(int index);

Entry tableArray[4095];

// add prefix + character to the table
void tableArrayAdd(int prefix, int character, int index) {
    tableArray[index].prefix = prefix;
    tableArray[index].character = character;
}

int tableArrayPrefix(int index) {
    return tableArray[index].prefix;
}

int tableArrayCharacter(int index) {
    return tableArray[index].character;
}

#endif