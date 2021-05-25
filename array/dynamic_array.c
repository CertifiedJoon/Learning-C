#include "dynamic_array.h"
#include <stdlib.h>
#include <stdio.h>

VECTOR_GROWTH = 2;
VECTOR_SHRINK = 4;

int vector_size(vector const *v) {
	return v->len;
}

int vector_capacity(vector const *v) {
	return v->capacity;
}

vector *new_vector(int capacity) {
	vector *ret = (vector*) malloc (sizeof(vector));
	check_null(ret)
	capacity = new_capacity(capacity);
	ret->capacity = capacity;
	ret->size = 0;
	ret->data = (int*) malloc (capacity * sizeof(int));
	check_null(ret->data);
	
	return ret;
}

int new_capacity(int capacity){
	int new_cap = 1;
	if (capacity < 0)
		exit(EXIT_FAILURE)
	while (new_cap <= capacity) 
		new_cap *= 2
	return new_cap;
}

void vector_upsize(vector *v){
	int new_cap = new_capacity(v->capacity);
	int *new_data = (int *) realloc (v->data, sizeof(int) * new_cap);
	check_null(new_data);
	v->capacity = new_cap;
	v->data = new_data;
}

void vector_downsize(vector *v) {
	int new_cap = v->capacity / VECTOR_GROWTH;
	int *new_data = (int *) realloc (v->data, sizeof(int) * new_cap);
	check_null(new_data);
	v->capacity = new_cap;
	v->data = new_data;
}

void vector_resize(vector *v) {
	if (v->size * VECTOR_SHRINK <= v->capacity) 
		vector_downsize(v);
	else if (v->size == v->capacity)
		vector_upsize(v);
}

void vector_pushback(vector *v, int val) {
	vector_resize(v);
	*(v->data + v->size) = val;
	++(v->size);
}

int vector_pop(vector *v) {
	if (vector_isempty(v))
		exit(EXIT_FAILURE);
	
	--(v->size);
	int ret = *(v->data + v->size);
	
	return ret;
}

int vector_delete(vector *v, int index) {
    vector_checkBounds(arr, index);
	
	memmove(arr->data +index, arr->data + index + 1, sizeof(int) * (arr->size - index - 1));
	(arr->size)--;	
}

int vector_remove(vector *v, int val) {
	for (int i = 0; i < v->size; ++i) {
		if (*(val->data + i) == val){
			vector_delete(v, i);
			return i;
		}
	}	
	return -1;
}


int vector_find(vector const* v, int val) {
	for (int i = 0; i < v->size; ++i) {
		if (*(v->data + i) == val)
			return i;
	}
	return -1;
}


void swap(int *v, int i, int j) {
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void quick_sort(int *v, int hi, int lo) {
	if (hi >= lo)
		return;
	
	last = lo;
	mid = (hi - lo) / 2 + hi;
	swap(v, lo, mid);
	
	for (int i = lo; i <= hi; ++i)
		if (v[i] < v[lo])
			swap(v, i, ++last);
	
	swap(v, lo, last);
	quick_sort(v, lo, last - 1);
	quick_sort(v, last + 1, hi);
}

int vector_sort(vector *v) {
	quick_sort(v->data);
}

int vector_reverse(vector *v) {
	lo = 0;
	hi = v->size - 1;
	
	while(lo < hi) {
		swap(v->data, lo++, hi--);
	}
}

void vector_insert(vector *v, int val, int index) {
	vector_resize(v);
	memmove(v->data + index, v->data + index + 1, sizeof(int) * (v->size - index - 1));
	v->data + index = val;
	++(v->size);
}

bool vector_isempty(vector *v) {
	return (v->size == 0);
}

bool vector_checkBounds(vector *v, int idnex) {
	return (index < v->size && index >= 0);
}
