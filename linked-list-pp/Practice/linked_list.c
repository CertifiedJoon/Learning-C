#include "linked_list.h"

size_t size_list(Node *head) {
	size_t c = 0;
	while(head) {
		++c;
		head = head->next;
	}
	return c;
}

Node* front(Node *head) {
	if (head == NULL){
		printf("list empty");
		exit(EXIT_FAILURE);
	}
	
	return head;
}

Node* back(Node *head) {
	if (head == NULL){
		printf("list empty");
		exit(EXIT_FAILURE);
	}

	while(head->next)
		head = head->next;
		
	return head;
}

Node* find(Node *head) {
	while(head) {
		if (head->val == val)
			return head;
	}
	return NULL;
}

void print_list(Node *head) {
	while (head) {
		printf("%d -> ", head->val);
		head = head->next;
	}
	printf("\n");
}

void push_front(Node **head, val) {
	Node *node = (Node *) malloc (sizeof(Node));
	node->val = val;
	node->next = *head;
	*head = node;
}

void push(Node **head, val) {
	
	Node *node = (Node *) malloc (sizeof(Node));
	node->val = val;
	
	if (*head = NULL){
		*head = node;
		return;
	}
	
	Node *end = back(*head);
	end->next = node;
}

int pop_front(Node **head) {
	if (*head == NULL)
		exit(EXIT_FAILURE);
	
	int ret = *head->val;
	
	Node * curr = *head;
	*head = *head->next;
	
	free(curr);
}

int pop_back(Node**head) {
	if (*head == NULL)
		exit(EXIT_FAILURE);
	
	Node *curr = *head;
	while(curr->next) {
		prev = curr;
		curr = curr->next;
	}
	
	prev->next = NULL;
	int ret = curr->val;
	free(curr);
	
	return ret;
}

void insert(Node **head, size_t index, int val) {
	if (index == 0)
		push_front(head, val);
	
	Node *node = malloc(sizeof(Node));
	node->val = val;
	
	Node *curr = *head;
	int i = 1;
	while(curr) {
		if (i == index){
			curr->next = node;
			node->next = curr->next;
			return;
		}
		curr = curr->next;
		++i;
	}
	
	exit(EXIT_FAILURE);
}

void reverse(Node **head) {
	Node* curr = *head;
	Node *prev = NULL;
	
	while(curr) {
		Node* next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	
	*head = prev;
}