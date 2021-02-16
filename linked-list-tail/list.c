#include "list.h"

CJForwardList *cjforwardlist_new (){
  CJForwardList *ll = (CJForwardList *) malloc (sizeof(CJForwardList));
  checknull(ll);
  ll->head = NULL;
  ll->tail = NULL;
  ll->size = 0;
  return ll;
};

int cjlist_size(CJForwardList *ll){
  return ll->size;
}

int cjlist_empty(CJForwardList *ll){
  return (ll->head == NULL);
}

int cjlist_at(CJForwardList *ll, int index){
  int i = 0;
  struct CJnode *current = ll->head;
  while (i < index){
    if (current == NULL){
      printf("Index out of bound\n");
      exit(EXIT_FAILURE);
    }
    current = current->next;
    i++;
  }
  return current->val;
}

void cjlist_push_front(CJForwardList *ll, int item){
  struct CJnode *node = malloc(sizeof(struct CJnode));
  node->val = item;
  node->next = ll->head;
  ll->head = node;
  (ll->size)++;
}

int cjlist_pop_front(CJForwardList *ll){
  if ((cjlist_size(ll)) == 0){
    printf("Cannot pop from empty list\n");
    exit(EXIT_FAILURE);
  }

  struct CJnode *node = ll->head;
  int pop = node->val;

  ll->head = node->next;
  free(node);
  (ll->size)--;

  return pop;
}

int cjlist_pop_back(CJForwardList *ll){
  if ((cjlist_size(ll)) == 0){
    printf("Cannot pop from an empty list\n");
    exit(EXIT_FAILURE);
  }

  struct CJnode *current = ll->head;

  while (current->next != ll->tail)
    current = current->next;

  struct CJnode *node = ll->tail;
  int pop = node->val;

  current->next = NULL;
  ll->tail = current;
  free (node);
  (ll->size)--;

  return pop;
}

void cjlist_push_back(CJForwardList *ll, int item){
  struct CJnode *node = malloc (sizeof(struct CJnode));
  node->val = item;

  ll->tail->next = node;
  ll->tail = node;

  (ll->size)++;
}

int cjlist_front(CJForwardList *ll){
  return (ll->head->val);
}

int cjlist_back(CJForwardList *ll){
  return (ll->tail->val);
}

void cjlist_insert(CJForwardList *ll, int item, int index){
  struct CJnode *node = malloc(sizeof(struct CJnode));
  struct CJnode *current = ll->head;
  node->val = item;

  if(index >= cjlist_size(ll)){
    printf("Index out of bound");
    exit(EXIT_FAILURE);
  }

  if(index == 0)
    return cjlist_push_front(ll, item);

  if(index == cjlist_size(ll) - 1)
    return cjlist_push_back(ll, item);

  while(index > 1){
    current = current->next;
    index--;
  }

  node->next = current->next;
  current->next = node;
  (ll->size)++;
}

void cjlist_erase(CJForwardList *ll, int index){
  if (index >= cjlist_size(ll)){
    printf("Index out of bounds\n");
    exit(EXIT_FAILURE);
  }
  else if (index == 0){
    int _ = cjlist_pop_front(ll);
    return;
  }
  else if (index == cjlist_size(ll) - 1){
    int _ = cjlist_pop_back(ll);
    return;
  }

  struct CJnode *current = ll->head;
  while(index > 1){
    current = current->next;
    index--;
  }
  struct CJnode *node = current->next;
  current->next = node->next;
  free(node);

  (ll->size)--;
}

void cjlist_remove(CJForwardList *ll, int target){
  struct CJnode *current = ll->head;
  int index = 0;
  while(current != NULL){
    if(current->val == target){
      cjlist_erase(ll, index);
    }
    current = current->next;
    index++;
  }
}

void cjlist_reverse(CJForwardList *ll){
  struct CJnode *prev, *next, *current;
  current = ll->head;
  prev = NULL;

  ll->tail = ll->head;

  while(current){
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

   ll->head = prev;
}

void checknull(void *p){
  if (p == NULL) {
    printf("Unable to allocate memory\n");
    exit(EXIT_FAILURE);
  }
}
