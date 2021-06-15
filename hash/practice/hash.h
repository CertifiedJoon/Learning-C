#ifndef HASH_H
#define HASH_H

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct KeyVal {
	char* key;
	char* val;
} keyval;

typedef struct HashTable {
	keyval** data;
	int size;
	int capacity;
} hashtable;

hashtable* new_table(int capacity);

int hash (char* key);

char* get_val(hashtable *ht, char* key);

void add(hashtable *ht, char* key, char* val);

#endif