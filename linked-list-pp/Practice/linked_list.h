#ifndef PROJECT_LINKEDLIST_H
#define PROJECT_LINKEDLIST_H

struct Node {
	int val;
	struct Node *next = nullptr;
};

//Accesssor
size_t size_list(Node *head);
Node* front(Node *head);
Node* back(Node *back);
Node* find(Node *head, val);
void print_list(Node *head);

//Mutators
void push_front(Node **head, val);
void push(Node **head, val);
int pop_front(Node **head);
int pop(Node **head);
void reverse(Node **head);
void remove(Node **head);
void insert(Node **head, size_t index, int val);


#endif