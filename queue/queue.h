#ifndef PROJECT_Q_H
#define PROJECT_Q_H

struct Node{
  int val;
  struct Node * next;
};

typedef struct{
  struct Node *head;
  struct Node *tail;
} CJqueue;


CJqueue *new_queue();

int is_empty(CJqueue *queue);

void enqueue(CJqueue *queue, int item);

int dequeue(CJqueue *queue);

#endif
