#ifndef QUEUE_H
#define QUEUE_H

typedef struct Node {
	int* val;
	struct Node* next;
} node;

typedef struct Queue{
	node* head;
	node* tail;
} queue;

queue *new_queue();

int is_empty(queue *q);

void enqueue(queue *q, int item);

int dequeue(queue *q);

int front(const queue *q);

int back(const queue *q);

#endif