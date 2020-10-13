#ifndef PROJECT_LLPP_H
#define PROJECT_LLPP_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct Node{
  int val;
  struct Node *next;
} cjnode;

void print_cjlist(cjnode *head);

int sizeof_cjlist(cjnode *head);

void push_back(cjnode **head, int item);

void push_front(cjnode **head, int item);

int pop_back(cjnode **head);

int pop_front(cjnode **head);

int val_at(cjnode *head, int at);

int front(cjnode *head);

int back(cjnode *head);

void insert(cjnode **head, int index, int item);

void remove_val(cjnode **head, int item);

void reverse(cjnode **head);

#endif
