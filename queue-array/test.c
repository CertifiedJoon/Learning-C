#include "test.h"

void run_diagnostics(){

}

static void destroy_queue(CJqueue *queue){
  free(queue->elem);
  free(queue);
}

void test_empty(){
  CJqueue *queue = new_queue(10);
  assert(is_empty(queue));

  enqueue(queue, 1);
  assert(! is_empty(queue));

  destroy_queue(queue);
}

void test_enqueue_dequeue(){
  CJqueue *queue = new_queue(10);
  for(int i = 0; i < 9; i++)
    enqueue(queue, i);

  for(int i = 0; i < 9; i++)
    assert(dequeue(queue) == i);

  destroy_queue(queue);
}
