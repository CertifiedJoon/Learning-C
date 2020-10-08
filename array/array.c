#include "array.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

CJarray *cjarray_new(int capacity){
  int adjusted_capacity = cjarray_adjusted_capacity(capacity);
  CJarray *arr = (CJarray *) malloc(sizeof(CJarray));
  checkNull(arr);
  arr->size = 0;
  arr->capacity = adjusted_capacity;
  arr->data = (int *) malloc (sizeof(int)*adjusted_capacity);
  checkNull(arr->data);

  return arr;
}

int cjarray_adjusted_capacity(int capacity){
  const int cjMinInitialCapacity = 1;
  int adjusted_capacity = cjMinInitialCapacity;

  if (capacity < cjMinInitialCapacity) {
    exit(EXIT_FAILURE);
  }

  while (capacity > adjusted_capacity / cjGrowthFactor){
    adjusted_capacity *= cjGrowthFactor;
  }

  return adjusted_capacity;
}

void checkNull(void *p){
  if (p == NULL){
    printf("Unable to allocate memory\n");
    exit(EXIT_FAILURE);
  }
}

int cjarray_isempty(CJarray *arr){
  if (arr->size == 0)
    return 1;
  return 0;
}

int cjarray_size (CJarray *arr) {return arr->size;}

int cjarray_capacity (CJarray *arr) {return arr->capacity;}

int cjarray_at (CJarray *arr, int index){
  if (index + 1 > arr->size || index < 0){
    printf("Index out of bound");
    exit(EXIT_FAILURE);
  }
  else
    return *(arr->data + index);
}

void cjarray_resize(CJarray *arr){
  if (arr->size >= arr->capacity){
    cjarray_upsize(arr);
  }

  else if (arr->size < (arr->capacity) / cjShrinkFactor){
    cjarray_downsize(arr);
  }
}

void cjarray_upsize(CJarray *arr){
  int oldcapacity = arr->capacity;
  int newcapacity = cjarray_adjusted_capacity(oldcapacity);
  int *new_arr = (int *) realloc (arr->data,sizeof(int) * newcapacity);
  checkNull(new_arr);

  arr->data = new_arr;
  arr->capacity = newcapacity;
}

void cjarray_downsize(CJarray *arr){
  int oldcapacity = arr->capacity;
  int newcapacity = oldcapacity / cjShrinkFactor;
  int *new_arr = (int *) realloc (arr->data, sizeof(int) * newcapacity);
  checkNull(new_arr);

  arr->data = new_arr;
  arr->capacity = arr->capacity / cjShrinkFactor;
}

void cjarray_push (CJarray *arr, int item){
  cjarray_resize(arr);
  *(arr->data + arr->size) = item;
  ++(arr->size);
}

void checkIndexBounds(CJarray *arr, int index){
  if (index >= arr->size || index < 0){
    printf("Index out of bound");
    exit(EXIT_FAILURE);
  }
}

void cjarray_insert(CJarray *arr, int index, int item){
  checkIndexBounds(arr, index);
  cjarray_resize(arr);

  /*for (int * p = arr->data + index; p <= arr->data + arr->size; ++p){
    int temp = *p;
    *p = item;
    item = temp;
  } */
  memmove(arr->data + index + 1, arr->data + index, sizeof(int) * (arr->size - index));
  *(arr->data + index) = item;
  ++(arr->size);
}

void cjarray_delete(CJarray *arr, int index){
  checkIndexBounds(arr, index);
  cjarray_resize(arr);

  memmove(arr->data +index, arr->data + index + 1, sizeof(int) * (arr->size - index - 1));
  (arr->size)--;
}

void cjarray_prepend(CJarray *arr, int item){
  cjarray_insert(arr, 0, item);
}

int cjarray_pop(CJarray *arr){
  checkNull(arr);
  cjarray_resize(arr);

  int popped = *(arr->data + arr->size - 1);
  (arr->size)--;
  return popped;
}

void cjarray_removeAll(CJarray *arr, int item){
  for (int i = 0; i < arr->size; ++i){
    if (*(arr->data + i) == item){
      cjarray_delete(arr, i);
      --i;
    }
  }
}

int cjarray_find(CJarray *arr, int item){
  for (int i = 0; i < arr->size; ++i){
    if (*(arr->data + i) == item){
      return i;
    }
  }
  return -1;
}

void cjarray_print_status(CJarray *arr){
  printf("Size    : %d\n", arr->size);
  printf("Capcity : %d\n", arr->capacity);
  for (int* p = arr->data; p < arr->data + arr->size; p++){
    printf("%d ", *p);
  }
  printf("\n========================================\n");
}

void cjarray_destroy(CJarray *arr){
  free(arr->data);
  free(arr);
}

void run_test(){
  printf("Running Diagnostics: at()\n");
  void test_at();
  printf("Running Diagnostics: pop()\n");
  void test_pop();
  printf("Running Diagnostics: find()\n");
  void test_find();
  printf("Running Diagnostics: size()\n");
  void test_size();
  printf("Running Diagnostics: push()\n");
  void test_push();
  printf("Running Diagnostics: delete()\n");
  void test_delete();
  printf("Running Diagnostics: insert()\n");
  void test_insert();
  printf("Running Diagnostics: remove()\n");
  void test_remove();
  printf("Running Diagnostics: prepend()\n");
  void test_prepend();
}


void test_size(){
  CJarray *arr = cjarray_new(5);
  assert(arr->size == 0);
  cjarray_destroy(arr);
}

void test_push(){
  CJarray *arr = cjarray_new(2);
  cjarray_push(arr, 0);
  cjarray_push(arr, 1);
  int new_size = arr->size;
  assert(new_size == 2);
  cjarray_destroy(arr);
}

void test_at(){
  CJarray *arr = cjarray_new(2);
  cjarray_push(arr, 1);
  cjarray_push(arr, 2);
  assert(*(arr->data + 1) == 2);
  cjarray_destroy(arr);
}

void test_insert(){
  CJarray *arr = cjarray_new(5);
  for (int i = 0; i < 10; ++i){
    cjarray_push(arr, i);
  }
  cjarray_insert(arr,5,0);
  assert((cjarray_at(arr, 5) == 0) && (cjarray_at(arr, 6) == 5));
  cjarray_destroy(arr);
}

void test_delete(){
  CJarray *arr = cjarray_new(5);
  for (int i = 0; i < 10; ++i){
    cjarray_push(arr, i);
  }
  cjarray_delete(arr,5);
  assert(cjarray_at(arr, 5) == 6);
  cjarray_destroy(arr);
}

void test_pop(){
  CJarray *arr = cjarray_new(2);
  cjarray_push(arr, 1);
  cjarray_push(arr, 2);
  int poped = cjarray_pop(arr);
  assert(poped == 2);
  cjarray_destroy(arr);
}

void test_prepend(){
  CJarray *arr = cjarray_new(5);
  for (int i = 0; i < 10; ++i){
    cjarray_push(arr, i);
  }
  cjarray_prepend(arr,0);
  assert((cjarray_at(arr, 0) == 0) && (cjarray_at(arr, 1) == 0));
  cjarray_destroy(arr);
}

void test_remove(){
  CJarray *arr = cjarray_new(5);
  for (int i = 0; i < 10; ++i){
    cjarray_push(arr, i);
  }
  cjarray_prepend(arr,0);
  cjarray_removeAll(arr, 0);
  assert(cjarray_at(arr, 0) == 1);
  cjarray_destroy(arr);
}

void test_find(){
  CJarray *arr = cjarray_new(5);
  for (int i = 0; i < 10; ++i){
    cjarray_push(arr, i);
  }
  assert(cjarray_find(arr, 10) == -1 && cjarray_find(arr, 9) == 9);
  cjarray_destroy(arr);
}
