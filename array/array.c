#include "array.h"
#include <string.h>

CJarray *cjarray_new(int capacity){
  int adjusted_capacity = cjarray_adjusted_capacity(capacity);
  CJarray *arr = malloc(sizeof(CJarray));
  checkNull(arr);
  arr->size = 0;
  arr->capacity = adjusted_capacity;
  arr->data = (int *) malloc (sizeof(int)*adjusted_capacity);
  checkNull(arr->data);

  return arr;
}

int cjarray_adjusted_capacity(int capacity){
  const int cjMinInitialCapacity = 1
  int adjusted_capacity = cjMinInitialCapacity;

  if (capacity < cjMinInitialCapacity) {
    exit(EXIT_FAILURE);
  }

  while (capacity > adjusted_capacity / cjGrowthFactor){
    capacity *= cjGrowthFactor;
  }

  return adjusted_capacity;
}

void checkNull(void *p){
  if (p == NULL){
    printf("Unable to allocate memory\n");
    exit(EXIT_FAILURE);
  }
}

int cjarray_size (CJarray *arr) {return arr->size;}

int cjarray_capacity (CJarray *arr) {return arr->capacity;}

int cjarray_at (CJarray *arr, int index){
  if (index + 1 > arr->size || index < 0){
    printf("Index out of bound");
    exit(EXIT_FAILURE);
  }
  else
    return arr[index];
}

void cjarray_resize(CJarray *arr){
  if (arr->size == arr->capacity){
    cjarray_upsize(arr);
  }

  else if (arr->size < arr->capacity / cjShrinkFactor){
    cjarray_downsize(arr);
  }
}

void cjarrary_upsize(CJarry *arr){
  int *new_arr = (int *) realloc (arr->data,sizeof(int) * capacity * cjGrowthFactor);
  checkNull(new_arr);

  arr->data = new_arr;
  arr->capacity = capacity * cjGrowthFactor;
}

void cjarray_downsize(CJarray *arr){
  int *new_arr = (int *) realloc (arr->data, sizeof(int) * capacity / cjShrinkFactor);
  checkNull(new_arr);

  arr->data = new_arr;
  arr->capacity = capacity / cjShrinkFactor;
}

void cjarray_push (CJarray *arr, int item){
  cjarray_resize(arr);
  *(arr->data + arr->size) = item;
  ++(arr->size);
}

void checkIndexBounds(CJarray *arr, int index){
  if (index + 1 > arr->size || index < 0){
    printf("Index out of bound");
    exit(EXIT_FAILURE);
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
  cjarray_resize();

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
