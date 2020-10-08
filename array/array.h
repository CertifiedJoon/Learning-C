#ifndef PROJECT_ARRAY_H
#define PROJECT_ARRAY_H

#include <assert.h>
#include <stdbool.h>

const int cjGrowthFactor = 2;
const int cjShrinkFactor = 4;
const int cjMinCapacity = 16;

typedef struct C_JoonArray{
  int size;
  int capacity;
  int *data;
} CJarray;

CJarray *cjarray_new(int capacity);

int cjarray_adjusted_capacity(int capacity);

void checkNull(void *p);

int cjarray_size(CJarray *arr);

int cjarray_capacity(CJarray *arr);

int cjarray_at(CJarray *arr, int index);

void cjarray_resize(CJarray *arr);

void cjarray_upsize(CJarray *arr);

void cjarray_downsize(CJarray *arr);

int cjarray_pop(CJarray *arr);

int cjarray_find(CJarray *arr, int item);

void cjarray_push(CJarray *arr, int item);

void cjarray_delete(CJarray *arr, int index);

void cjarray_insert(CJarray *arr, int index, int item);

void cjarray_removeAll(CJarray *arr, int item);

void checkIndexBounds(CJarray *arr, int index);

void cjarray_destroy(CJarray *arr);

void cjarray_print_status(CJarray *arr);

int cjarray_isempty(CJarray *arr);

void run_test();
void test_at();
void test_pop();
void test_find();
void test_size();
void test_push();
void test_delete();
void test_insert();
void test_remove();
void test_prepend();

#endif
