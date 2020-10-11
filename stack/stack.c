#include <stdlib.h>
#include "stack.h"
#include <stdio.h>

MinStack* minStackCreate() {
  MinStack *stack = malloc(sizeof(MinStack));
  stack->size = 0;
  stack->capacity = 16;
  stack->elem = (int*) malloc (sizeof(int) * (stack->capacity));
  return stack;
}

static void stack_upsize(MinStack* obj){
  int new_capacity = (obj->capacity) * 2;
  int *new_arr = (int *) realloc (obj->elem, sizeof(int) * new_capacity);

  obj->elem = new_arr;
  obj->capacity = new_capacity;
}

static void stack_downsize(MinStack* obj){
  int new_capacity = (obj->capacity) / 4;
  int *new_arr = (int *) realloc (obj->elem, sizeof(int) * new_capacity);

  obj->elem = new_arr;
  obj->capacity = new_capacity;
}

static void stack_resize(MinStack* obj){
  if (obj->size == obj->capacity)
    stack_upsize(obj);

  else if (obj->size <= ((obj->capacity) / 4))
    stack_downsize(obj);
}

void minStackPush(MinStack* obj, int x) {
  stack_resize(obj);
  printf("%d ", x);
  *(obj->elem + obj->size) = x;
  (obj->size)++;
}

void minStackPop(MinStack* obj) {
  stack_resize(obj);
  --(obj->size);
}

int minStackTop(MinStack* obj) {
  return *(obj->elem + obj->size - 1);
}

int minStackGetMin(MinStack* obj) {
  int min = *(obj->elem);
  for(int *p = obj->elem; p < obj->elem + obj->size; p++){
    if (min > *p)
      min = *p;
  }
  return min;
}

void minStackFree(MinStack* obj) {
  free(obj->elem);
  free(obj);
}
