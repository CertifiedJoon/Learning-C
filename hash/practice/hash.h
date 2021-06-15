#ifndef HASH_H
#define HASH_H

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

void insert(hashtable *ht, char* key, char* val);

#endif