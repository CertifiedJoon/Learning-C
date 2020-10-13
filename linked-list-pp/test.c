#include "test.h"

void run_diagnostics(){
  printf("testing size\n");
  test_size();
  printf("testing pushback\n");
  test_push_back();
  printf("testing pushfront\n");
  test_push_front();
  printf("testing pop\n");
  test_pop();
  printf("testing erase\n");
  test_erase();
  printf("testing insert\n");
  test_insert();
  printf("testing remove\n");
  test_remove();
  printf("testing reverse\n");
  test_reverse();
  printf("testing success");
}

void destroy_list(cjnode *head){
  cjnode *current = head;
  while(current){
    cjnode *node = current;
    current = current->next;
    free(node);
  }
}

void test_size(){
  cjnode *head = NULL;

  assert(sizeof_cjlist(head) == 0);

  cjnode *first = malloc(sizeof(cjnode));
  first->val = 1;
  first->next = NULL;

  head = first;

  assert(sizeof_cjlist(head) == 1);

  destroy_list (head);
}

void test_push_back(){
  cjnode *head = NULL;
  push_back(&head, 1);
  push_back(&head, 2);
  assert(val_at(head, 1) == 1);
  assert(val_at(head, 2) == 2);
  destroy_list(head);
}

void test_push_front(){
  cjnode *head = NULL;

  push_front(&head, 1);
  push_front(&head, 2);

  assert(val_at(head, 1) == 2);
  assert (val_at(head, 2) == 1);

  destroy_list(head);
}

void test_pop(){
  cjnode *head = NULL;

  push_back(&head, 1);
  push_back(&head, 2);

  assert(pop_front(&head) == 1);
  assert(pop_back(&head) == 2);

  destroy_list(head);
}

void test_insert(){
  cjnode *head = NULL;

  for(int i = 0; i < 10; i++)
    push_back(&head, i);

  insert(&head, 3, 2);
  assert(val_at(head, 3) == 2);

  destroy_list(head);
}

void test_erase(){
  cjnode *head = NULL;
  for(int i = 0; i < 10; i++)
    push_back(&head, i);

  erase(&head, 3);
  assert(val_at(head, 3) == 3);

  destroy_list(head);
}

void test_remove(){
  cjnode *head = NULL;
  for(int i = 0; i < 10; i++)
    push_back(&head, i);

  remove_val(&head, 5);

  assert(val_at(head, 6) == 6);
  destroy_list(head);
}

void test_reverse(){
  cjnode *head1 = NULL;
  for(int i = 0; i < 10; i++)
    push_back(&head1, i);

  cjnode *head2 = NULL;
  for(int i = 0; i< 10; i++)
    push_front(&head2, i);

  reverse(&head2);

  for(int i = 1; i < 11; i++)
    assert(val_at(head1, i) == val_at(head2, i));

  destroy_list(head1);
  destroy_list(head2);
}
