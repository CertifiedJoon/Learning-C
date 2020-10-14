#include "list.h"

CJForwardList *cjforwardlist_new (){
  CJForwardList *ll = (CJForwardList *) malloc (sizeof(CJForwardList));
  checknull(ll);
  ll->head = NULL;
  return ll;
};

int cjlist_size(CJForwardList *ll){
  struct CJnode *current = ll->head;
  int size = 0;
  while (current != NULL){
    size++;
    current = current->next;
  }
  return size;
}

int cjlist_empty(CJForwardList *ll){
  if (ll->head == NULL)
    return 1;
  else
    return 0;
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
  struct CJnode *front = malloc(sizeof(struct CJnode));
  checknull(front);

  front->val = item;
  front->next = ll->head;
  ll->head = front;
}

int cjlist_pop_front(CJForwardList *ll){
  if (cjlist_empty(ll)) {
    printf("Cannot pop from empty list\n");
    exit(EXIT_FAILURE);
  }
  struct CJnode *temp = malloc(sizeof(struct CJnode));
  temp = ll->head;

  int poped = temp->val;
  ll->head = temp->next;

  free(temp);

  return poped;
}

int cjlist_pop_back(CJForwardList *ll){
  if (cjlist_empty(ll)) {
    printf("Cannot pop from empty list\n");
    exit(EXIT_FAILURE);
  }

  struct CJnode *temp = malloc(sizeof(struct CJnode));
  temp = ll->head;
  struct CJnode *prev;

  while(temp->next != NULL){
    prev = temp;
    temp = temp->next;
  }

  int poped = temp->val;
  prev->next = NULL;

  free(temp);

  return poped;
}

void cjlist_push_back(CJForwardList *ll, int item){
  struct CJnode *current = ll->head;
  struct CJnode *node = malloc(sizeof(struct CJnode));
  node->val = item;

  if (cjlist_empty(ll)){
    current->val = item;
  }

  while(current->next != NULL)
    current = current->next;

  node->next = current->next;
  current->next = node;
}

int cjlist_front(CJForwardList *ll){
  if (cjlist_empty(ll)){
    printf("Cannot access the front of an empty list\n");
    exit(EXIT_FAILURE);
  }
  return ll->head->val;
}

int cjlist_back(CJForwardList *ll){
  if (cjlist_empty(ll)){
    printf("Cannot access the front of an empty list\n");
    exit(EXIT_FAILURE);
  }
  struct CJnode *current = ll->head;
  while (current->next != NULL){
    current = current->next;
  }
  return current->val;
}

void cjlist_insert(CJForwardList *ll, int item, int index){
  int i = 0;
  struct CJnode *current = ll->head;
  struct CJnode *node = malloc(sizeof(struct CJnode));
  node->val = item;

  while (i < index - 1){
    if (current == NULL){
      printf("Index out of bound\n");
    exit(EXIT_FAILURE);
    }
    current = current->next;
    i++;
  }

  node->next = current->next;
  current->next = node->next;
}

void cjlist_erase(CJForwardList *ll, int index){
  int i = 0;
  struct CJnode *current = ll->head;

  while (i < index - 1){
    if (current->next == NULL){
      printf("Index out of bound\n");
    exit(EXIT_FAILURE);
    }
    current = current->next;
    i++;
  }

  struct CJnode *temp = current->next;
  current->next = current->next->next;

  free(temp);
}

void cjlist_remove(CJForwardList *ll, int target){
  struct CJnode *current = ll->head;
  struct CJnode *removed;
  while (current->next != NULL){
    if (current->next->val == target){
      removed = current->next;
      current->next = current->next->next;
      free(removed);
    }
    current = current->next;
  }
}

void cjlist_reverse(CJForwardList *ll){
  struct CJnode *prev = NULL;
  struct CJnode *current = ll->head;
  struct CJnode *next;

  while (current) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  ll->head = prev;
}

int cjlist_value_n_from_end(CJForwardList *ll, int n) {

  struct CJnode *first = ll->head;
  struct CJnode *match = ll->head;

  for (int i = 0; i < n; ++i) {
    if (first) {
      first = first->next;
    } else {
      printf("List not long enough to find nth item from end.");
      exit(EXIT_FAILURE);
    }
  }

  while (first) {
    first = first->next;
    match = match->next;
  }

  return match->data;
}

void checknull(void *p){
  if (p == NULL) {
    printf("Unable to allocate memory\n");
    exit(EXIT_FAILURE);
  }
}
