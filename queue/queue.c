#include "queue.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

CJqueue* new_queue (){
  CJqueue *queue = malloc (sizeof(CJqueue));
  queue->head = NULL;
  queue->tail = NULL;

  return queue;
}

int is_empty(CJqueue *queue){
  return (queue->head == NULL);
}

void enqueue(CJqueue *queue, int item){
  struct Node *node = malloc (sizeof(struct Node));
  node->val = item;
  node->next = NULL;

  if (is_empty(queue)){
    queue->head = node;
    queue->tail = node;
  }

  else{
    queue->tail->next = node;
    queue->tail = node;
  }
}

int dequeue(CJqueue *queue){
  if(is_empty(queue)){
    printf("Cannot dequeue from empty queue\n");
    exit(EXIT_FAILURE);
  }

  struct Node *node = queue->head;
  int res = node->val;

  queue->head = node->next;

  free(node);
  return res;
}
