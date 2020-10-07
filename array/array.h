#ifndef PROJECT_ARRAY_H
#define PROJECT_ARRAY_H

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

void cjarray_pop(CJarray *arr);

void cjarray_find(CJarray *arr, int item);

void cjarray_push(CJarray *arr, int item);

void cjarray_delete(CJarray *arr, int index);

void cjarray_insert(CJarray *arr, int index, int item);

void cjarray_removeAll(CJarray *arr, int item);

void checkIndexBounds(CJarray *arr, int index);
