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
		primte++;
		
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
	
}

