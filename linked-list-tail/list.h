#ifndef PROJECT_LINKED_LIST_H
#define PROJECT_LINKED_LIST_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct CJnode{
  int val;
  struct CJnode *next;
};

typedef struct Certified_Joon_Implementation_LinkedList{
  struct CJnode *head;
  struct CJnode *tail;
  int size;
} CJForwardList;

CJForwardList *cjforwardlist_new ();

int cjlist_size(CJForwardList *ll);

int cjlist_empty(CJForwardList *ll);

int cjlist_at(CJForwardList *ll, int index);

void cjlist_push_front(CJForwardList *ll, int item);

int cjlist_pop_front(CJForwardList *ll);

int cjlist_pop_back(CJForwardList *ll);

void cjlist_push_back(CJForwardList *ll, int item);

int cjlist_front(CJForwardList *ll);

int cjlist_back(CJForwardList *ll);

void cjlist_insert(CJForwardList *ll, int item, int index);

void cjlist_erase(CJForwardList *ll, int index);

void cjlist_remove(CJForwardList *ll, int target);

void cjlist_reverse(CJForwardList *ll);

void checknull(void *p);

#endif
