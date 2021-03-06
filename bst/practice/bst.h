#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
typedef struct Node {
	int val;
	struct Node* left;
	struct Node* right;
} node;

node* newNode(int val);

void insert*(node** root, int val);

void countNode(node* root);

void inorderPrint(node* root);

void preorderPrint(node* root);

void postorderPrint(node* root);

void morrisPrint(node* root);

void getHeight(node* root);

void deleteTree(node* root);

bool find(node* root, int val);

int getHeight(node* root);

int minNode(node* root);

int maxNode(node* root);

bool isBst(node* root);

void delete(node **root, int item);

node* getNode(Node* root, int item);

node* getSuccessor(node* root, int data);