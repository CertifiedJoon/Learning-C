#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>
#include <assert.h>

typedef struct tree{
    int val;
    struct tree *left;
    struct tree *right;
} Node;

Node* new_node(int val);

void insert(Node** root, int item);

int get_node_count(Node* root);

void print_tree_in(Node* root);

void print_tree_pre(Node *node);

void print_tree_post(Node *node);

void delete_tree(Node* root);

bool in_tree(Node* root, int item);

int get_height(Node * root);

int min_node(Node* root);

int max_node(Node *node);

bool is_bst (Node* root);

bool node_check(Node* root, int min, int max);

void delete (Node **root, int item);

Node* find(Node* root, int item);

Node* get_successor(Node* root, int data);
