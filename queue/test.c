#include "test.h"

void run_diagnostics(){
  test_empty();
  test_enqueue_dequeue();
}

static void destroy_queue(CJqueue *queue){
  struct Node *temp;
  while(queue->head != NULL){
    temp = queue->head;
    queue->head = queue->head->next;
    free(temp);
  }
  free(queue);
}

void test_empty(){
  CJqueue *queue = new_queue();
  assert(is_empty(queue) == 1);

  enqueue(queue, 1);
  assert(is_empty(queue) == 0);

  destroy_queue(queue);
}

void test_enqueue_dequeue(){
  CJqueue *queue = new_queue();
  enqueue(queue, 1);
  assert(dequeue(queue) == 1);

  destroy_queue(queue);
}
