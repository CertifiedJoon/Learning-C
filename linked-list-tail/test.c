#include "test.h"

void run_diagnostics(){
  void test_size();
  void test_at();
  void test_run();
  void test_pop();
  void test_back();
  void test_front();
  void test_empty();
  void test_reverse();
  void test_push_back_front();
}

void cjlist_destroy(CJForwardList *ll){
  struct CJnode *temp;
  while (ll->head != NULL){
    temp = ll->head;
    ll->head = ll->head->next;
    free(temp);
  }
  free(ll);
}

void test_size(){
  CJForwardList *ll = cjforwardlist_new();
  for (int i = 0; i < 10; i++)
    cjlist_push_back(ll, i);
  int size = cjlist_size(ll);
  assert(size == 10);
  cjlist_destroy(ll);
}

void test_empty(){
  CJForwardList *ll = cjforwardlist_new();
  assert(cjlist_empty(ll));
  cjlist_destroy(ll);
}

void test_at(){
  CJForwardList *ll = cjforwardlist_new();
  for (int i = 0; i < 10; i++)
    cjlist_push_front(ll, i);
  assert(cjlist_at(ll, 9) == 0);
  cjlist_destroy(ll);
}

void test_push_back_front(){
  CJForwardList *ll = cjforwardlist_new();
  cjlist_push_back(ll, 5);
  assert(cjlist_at(ll, 0) == 5);
  cjlist_push_front(ll, 4);
  assert(cjlist_at(ll, 0) == 4);
}

void test_pop(){
  CJForwardList *ll = cjforwardlist_new();
  for (int i = 0; i < 10; i++)
    cjlist_push_back(ll, i);

  int pop = cjlist_pop_back(ll);
  assert(pop == 9);
  assert(cjlist_size(ll) == 9);

  pop = cjlist_pop_front(ll);
  assert(pop == 0);
  assert(cjlist_size(ll) == 8);
  cjlist_destroy(ll);
}

void test_front(){
  CJForwardList *ll = cjforwardlist_new();
  for (int i = 0; i < 10; i++)
    cjlist_push_back(ll, i);
  assert(cjlist_front(ll) == 0);
  cjlist_destroy(ll);
}

void test_back(){
  CJForwardList *ll = cjforwardlist_new();
  for (int i = 0; i < 10; i++)
    cjlist_push_back(ll, i);
  assert(cjlist_back(ll) == 9);
  cjlist_destroy(ll);
}

void test_reverse(){
  CJForwardList *ll = cjforwardlist_new();
  for (int i = 0; i < 10; i++)
    cjlist_push_back(ll, i);

  cjlist_reverse(ll);

  for (int i = 9; i >= 0;--i)
    assert(cjlist_pop_front(ll) == i);
}
