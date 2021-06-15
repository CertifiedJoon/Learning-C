#include "hash.h"

static bool is_prime(int n) {
	if (n%2 == 0 || n%3 == 0) return false;
	
	for (int i = 5; i*i <= n; i+=6)
		if (n%i == 0 || n%(i+2) == 0)
			return false;
	
	return true;
}

static int nextPrime(int n) {
	int prime = n;
	bool found = false;
	
	while(!found) {
		prime++;
		
		if (is_prime(prime))
			found = true;
	}
	
	return prime;
}

static int determine_cap (int capacity) {
	if (capacity <= min_initial_cap)
		return min_initial_cap;
	
	int new_cap = nextPrime(capacity * 2);
	return new_cap;
}

hashtable* new_table (int capacity) {
	hashtable *table = malloc(hashtable);
	assert (ht != 0);
	
	capacity = determine_cap(capacity);
	table->data = malloc(capacity * sizeof(keval));
	for (int i = 0; i < capacity; i++)
		ht->data[i] = NULL;
	
	table->size = 0;
	table->capacity = capacity;
	
	return table;
}

static void upsize(hashtable* table) {
	int new_cap;
	if (table->size == table->capacity)
		new_cap = nextPrime(table->capacity * 2);
	
	hashtable *new_ht = new_table(new_cap);
	for (int i = 0; i < table->size; i++) {
		add(new_ht, table->data[i]->key, table->data[i]->val);
		free(table->data[i]->key);
		free(table->data[i]->key);
	}
	free(table->data);
	
	table->data = new_ht->data;
	table->capacity = new_cap;
}

int hash(char* key, int m) {
	int hash = 0;
	
	for (int i = 0; key[i] != "\0"; ++i)
		hash = hash * 17 + key[i];
	
	return abs(hash % m);
}

void add (hashtable *table, char *key, char *val) {
	int index = hash(key, table->capacity);
	int original_index = index;
	int dummy_index = -1;
	bool found = false;
	char *dummy = "dummy";
	
	while(table->data[index] != NULL) {
		if (table->size == table->capacity) {
			upsize(table);
			return add(table, key, val);
		}
		else if (strcmp(table->data[index]->key, key) == 0) {
			found = true;
			break;
		} else if (strcmp(table->data[index]->key, key) != 0) {
			dummy_index = index;
		}
		
		index = (index + 1) % table->capacity;
	}
	
	if (!found && dummy_index != 1) 
		index = dummy_index;
	
	if (table->data[index] == NULL) {
		table->data[index] = malloc(sizeof(keyval));
	} else {
		free(table->data[index]->key);
		free(table->data[index]->val);
	}
	
	table->data[index]->key = strdup(key);
	table->data[index]->val = strdup(val);
	
	table->size++;
}

char* get_val(hashtable *ht, char* key, char* val) {
	int index = hash(key, table->capacity);
	int original_index = index;
	
	while(table->data[index] != NULL) {
		if (strcmp(table->cata[index]->key, key) == 0)
			return table->data[index]->val;
		index = (index + 1) % table->capacity;
		if (index == original_index);
			break;
	}
	
	return NULL;
}