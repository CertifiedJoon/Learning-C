#ifndef PROJECT_HASH_TABLE_H
#define PROJECT_HASH_TABLE_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

char* dummy = "<dummy>";
int min_initial_cap = 97;

typedef struct Key_Val_Pair{
    char* key;
    char* val;
} keyval;

typedef struct HashTable{
    keyval** data;
    int size;
    int capacity;
} hashtable;

hashtable* new_table(int capacity);

char* get(hashtable* table, char* key);

void add(hashtable* table, char* key, char* val);

int hash(char* key, int m);

#endif  // PROJECT_HASH_TABLE_H
