#include "linkedlist.h"

void print_cjlist (cjnode *head){
  cjnode *current = head;
  while(current!=NULL){
    printf("%d -> ",current->val);
    current = current->next;
  }
  printf("\n");
}

int sizeof_cjlist (cjnode *head){
  cjnode *current = head;
  int size = 0;

  while(current != NULL){
    size++;
    current = current->next;
  }

  return size;
}

int val_at (cjnode *head, int at){
  cjnode *current = head;
  int index = 1;

  while (current != NULL){
    if (index == at){
      return current->val;
    }
    current = current->next;
    index++;
  }

  printf("Index out of bounds\n");
  exit(EXIT_FAILURE);
}

void push_front(cjnode **head, int item){
  cjnode *node = malloc(sizeof(cjnode));
  node->val = item;
  node->next = *head;

  *head = node;
}

int pop_front(cjnode **head){
  if (*head == NULL){
    printf("Cannot pop from empty list\n");
    exit(EXIT_FAILURE);
  }
  cjnode *node = *head;
  int pop = node->val;

  *head = node->next;
  free(node);

  return pop;
}

void push_back(cjnode **head, int item){
  cjnode *node = malloc(sizeof(cjnode));
  node->val = item;
  node->next = NULL;

  if(*head == NULL){
    *head = node;
    return;
  }

  cjnode *current = *head;

  while(current->next){
    current = current->next;
  }

  current->next = node;
}

int pop_back(cjnode **head){
  if (*head == NULL){
    printf("Cannot pop from an empty list\n");
    exit(EXIT_FAILURE);
  }

  cjnode *current = *head;
  cjnode *prev = NULL;

  while(current->next != NULL){
    prev = current;
    current = current->next;
  }

  int pop = current->val;

  if (prev)
    prev->next = NULL;
  else
    *head = NULL;
  free(current);

  return pop;
}

int front(cjnode *head){
  if(head == NULL){
    printf("List Empty\n");
    exit(EXIT_FAILURE);
  }
  return head->val;
}

int back(cjnode *head){
  if(head == NULL){
    printf("List Empty\n");
    exit(EXIT_FAILURE);
  }
  cjnode *current = head;
  while(current->next != NULL){
    current = current->next;
  }

  return current->val;
}

void insert(cjnode **head, int at, int item){
  cjnode *node = malloc(sizeof(cjnode));
  node->val = item;

  if (at == 1){
    node->next = *head;
    *head = node;
    return;
  }

  cjnode *current = *head;

  int index = 1;

  while(current != NULL){
    if (index == at-1){
      node->next = current->next;
      current->next = node;
      return;
    }
    current = current->next;
    index++;
  }

  printf("Index out of bound\n");
  exit(EXIT_FAILURE);
}

void erase(cjnode **head, int at){
  cjnode *current = *head;
  cjnode *prev = NULL;
  int index = 1;

  if(at == 1){
    prev = current;
    *head = current->next;
    free(prev);
  }

  while(current != NULL){
    if(index == at){
      prev->next = current->next;
      free(current);
      return;
    }
    prev = current;
    current = current->next;
    index++;
  }

  printf("Index out of bound\n");
  exit(EXIT_FAILURE);
}

void reverse(cjnode **head){
  cjnode *current = *head;
  cjnode *prev = NULL;
  cjnode *next = *head;

  while(current != NULL){
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  *head = prev;
}

void remove_val(cjnode **head, int item){
  cjnode *current = *head;
  cjnode *prev = NULL;

  while (current){
    if(current->val == item){
      if (prev){
        prev->next = current->next;
      } else {
        *head = current->next;
        prev = head;
      }

      free(current);

      current = prev->next;
    } else {
      prev = current;
      current = current->next;
    }
  }
}
