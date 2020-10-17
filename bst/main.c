#include "bst.h"
#include "bst.c"

int main() {
  Node* root = NULL;

  insert(&root, 4);
  insert(&root, 12);
  insert(&root, 3);
  insert(&root, 11);
  insert(&root, 16);

  // print_tree(root);
  assert(get_node_count(root) == 5);

  assert(in_tree(root, 3));
  assert(in_tree(root, 11));
  assert(in_tree(root, 16));
  assert(!in_tree(root, 0));
  assert(!in_tree(root, -1));

  assert(get_height(root) == 2);
  insert(&root, 5);
  assert(get_height(root) == 3);

  assert(min_node(root) == 3);
  insert(&root, 2);
  assert(min_node(root) == 2);

  assert(max_node(root) == 16);
  insert(&root, 32);
  assert(max_node(root) == 32);

  assert(is_bst(root));

  // make bad tree
  Node* bad_root = malloc(sizeof(Node));
  bad_root->val = 10;
  bad_root->left = NULL;
  bad_root->right = malloc(sizeof(Node));
  bad_root->right->val = 9;
  bad_root->right->left = NULL;
  bad_root->right->right = NULL;

  assert(!is_bst(bad_root));

  delete(&root, 4);
  assert(!in_tree(root, 4));

  insert(&root, 4);

  assert(get_successor(root, 3)->val == 4);   // 4 is right child of 3
  assert(get_successor(root, 2)->val == 3);   // 3 is parent of 2, 2 is left child
  assert(get_successor(root, 4)->val == 5);   // 5 is root, 4 is right child of 3
  assert(get_successor(root, 5)->val == 4);  // 11 is min in right subtree of 5

  delete_tree(root);
  delete_tree(bad_root);

  return 0;
}
