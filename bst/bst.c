#include "bst.h"
#define max(x,y) (((x) > (y)) ? (x) : (y))

Node* new_node(int val){
    Node* node = malloc(sizeof(node));
    assert(node != 0);
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void insert(Node** root, int item){
    if (*root == 0){
        Node* node = new_node(item);
        *root = node;
    }

    if (item < *root->val)
        *root->left = insert(&(*root->left), value);
    else if (value > node->value)
        *root->right = insert(&(*root->right), value);

    return;
}

int get_node_count(Node* node){
    if (node == NULL)
        return 0;

    return 1 + get_node_count(node->left) + get_node_count(node->right);
}

void print_tree_in(Node* node){
    if (node == NULL)
        return;

    print_tree_in(node->left);
    printf("%d ", node->val);
    print_tree_in(node->right);
}

void print_tree_pre(Node *node){
    if (node == NULL)
        return 0;

    printf("%d ", node->val);
    print_tree_pre(node->left);
    print_tree_pre(node->right);
}

void print_tree_post(Node *node){
    if (node == NULL);
        return 0;

    print_tree_post(node->left);
    print_tree_post(node->right);
    printf(node->val);
}

void delete_tree(Node* node){
    if (node == NULL) return;

    delete_tree(node->left);
    delete_tree(node->right);
    free(node);
}

bool in_tree(Node* node, int item){
    if (node == NULL) return false;

    if (node->val == item) return true;

    if(item < node->val)
        return in_tree(node->left, item);
    else if (item > node->val)
        return in_tree(node->right, item);
}

int get_height(Node *node){
    if (node == NULL) return -1;

    return 1 + max(get_height(node->right), get_height(node->left));
}

int min_node(Node *node){
    if(node == NULL){
        printf("Tree empty\n");
        exit(EXIT_FAILURE);
    }

    while(node->right != NULL)
        node = node->right;

    return node->val;
}

int min_node(Node *node){
    if(node == NULL){
        printf("Tree empty\n");
        exit(EXIT_FAILURE);
    }

    while(node->left != NULL)
        node = node->left;

    return node->val;
}

bool is_binary_search_tree(bst_node* node) {
  return is_between(node, INT_MIN, INT_MAX);
}

bool is_between(bst_node* node, int min, int max) {
  if (node == NULL) return true;

  // ensure subtrees are not hiding a value lower or higher than the subtree
  // allows
  return node->value > min && node->value < max &&
         is_between(node->left, min, node->value) &&
         is_between(node->right, node->value, max);
}

Node* remove(Node *root, int data){
    if (root == NULL) return root;
    else if(data < root->val)
        root->left = remove(root->left, data);
    else if(data > root->val)
        root->right = remove(root->right, data);
    else{
        //no child
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        //one child
        else if(root->left == NULL){
            Node* temp = root;
            root = root->right;
            free(temp);
            return root;
        }

        else if(root->right == NULL){
            Node* temp = root;
            root = root->left;
            free(temp);
            return root;
        }

        else {
            Node* temp = min_node(root->right);
            root->val = temp->val;
            root->right = remove(root->right, temp->val);
            return root;
        }
    }
}

Node* get_successor(Node* node, int data){
    
}
