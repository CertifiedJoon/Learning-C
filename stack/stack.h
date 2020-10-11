#ifndef PROJECT_STACK_H
#define PROJECT_STACK_H

typedef struct{
  int *elem;
  int capacity;
  int size;
} MinStack;

MinStack* minStackCreate();

void minStackPush(MinStack* obj, int x);

void minStackPop(MinStack* obj);

int minStackTop(MinStack* obj);

int minStackGetMin(MinStack* obj);

void minStackFree(MinStack* obj);

#endif
