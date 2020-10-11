#include "stack.h"
#include "stack.c"
#include <stdio.h>

int main(){
  MinStack* stack = minStackCreate();
  for (int i = 0; i < 18; i++){
    minStackPush(stack, i);
  }
  minStackPop(stack);
  printf("%d\n", minStackTop(stack));
  printf("%d", minStackGetMin(stack));
  minStackFree(stack);
}
