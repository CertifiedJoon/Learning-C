#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
CJqueue* new_queue(int size){
  CJqueue *queue = malloc(sizeof(CJqueue));
  queue->elem = (int *) malloc(sizeof(int) * size);
  queue->read = 0;
  queue->write = 0;
  queue->size = size;
  return queue;
}

int is_empty(CJqueue *queue){
  return (queue->read == queue->write);
}

static int checkfull(int r, int w){
  return (r != w);
}

void enqueue(CJqueue *queue, int item){
  if(checkfull(queue->read, (queue->write + 1) % queue->size))
      queue->write == (queue->write + 1) % queue->size;
  else{
    printf("Cannot enqueue, Queue is full\n");
    exit(EXIT_FAILURE);
  }
  *(queue->elem + queue->write) = item;
  (queue->write)++;
}

int dequeue(CJqueue* queue){
  if (is_empty(queue)){
    printf("Cannot dequeue from empty queue\n");
    exit(EXIT_FAILURE);
  }
  return(*(queue->elem + ((queue->read)++)));
}
