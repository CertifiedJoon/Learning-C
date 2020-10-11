#ifndef PROJECT_QR_H
#define PROJECT_QR_H
#include <stdbool.h>
typedef struct{
  int *elem;
  int read;
  int write;
  int size;
} CJqueue;

CJqueue *new_queue(int size);

int is_empty(CJqueue *queue);

void enqueue(CJqueue *queue, int item);

int dequeue(CJqueue *queue);


#endif
