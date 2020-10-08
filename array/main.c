#include "array.h"
#include "array.c"
#include <stdio.h>
#include <stdlib.h>

void example_run();

int main(void){
  run_test();
  example_run();
  return EXIT_SUCCESS;
}

void example_run(){
  int capacity;

  printf("Enter how many elements you would like to store:");
  scanf("%d", &capacity);
  printf("Creating Certified_Joon's vector of capacity %d\n", capacity);
  CJarray *arr = cjarray_new(capacity);

  for (int i = 0; i < capacity; ++i)
    cjarray_push(arr, i);

  int intpre = 999;
  printf("Prepending new element %d\n", intpre);
  cjarray_prepend(arr, intpre);
  printf("Prepend Complete:\n");
  cjarray_print_status(arr);

  int intins = 888;
  int index = 8;
  printf("Inserting new element %d at %d\n", intins, index);
  cjarray_insert(arr, index, intins);
  printf("Insertion Complete:\n");
  cjarray_print_status(arr);

  printf("Popping");
  int popped = cjarray_pop(arr);
  printf("Popping Complete: %d\n", popped);
  cjarray_print_status(arr);

  int intrm = 999;
  printf("Remeoving all %d\n", intrm);
  cjarray_removeAll(arr, intrm);
  printf("Removing Complete:\n");
  cjarray_print_status(arr);
}
