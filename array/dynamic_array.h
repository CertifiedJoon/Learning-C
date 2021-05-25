#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

typedef struct Array {
	int* data;
	int size;
	int capacity;
} vector;

int vector_size(vector const *v);
int vector_capacity(vector const *v);
vector *new_vector(int capacity);
int new_capacity(int capacity);
void vector_resize(vector *v);
void vector_pushback(vector *v, int val);
int vector_pop(vector *v);
int vector_remove(vector *v, int val);
int vector_find(vector const*v, int val);
int vector_sort(vector *v);
int vector_reverse(vector *v);
bool vector_isempty(vector *v);
int vector_delete(vector *v, int index);
void vector_insert(vector *v, int val, int index);
bool vector_checkBounds(vector const*v, int idnex);
void check_null(void *p));

#endif