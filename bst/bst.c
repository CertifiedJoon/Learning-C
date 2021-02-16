#define max(x,y) (((x) > (y)) ? (x) : (y))

Node* new_node(int val){
    Node* node = malloc(sizeof(Node));
    assert(node != 0);
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void insert(Node** root, int item){
    if (*root == NULL){
        Node* node = new_node(item);
        *root = node;
        return;
    }

    else if(item < (*root)->val){
        insert(&((*root)->left), item);
    }

    else{
        insert(&((*root)->right), item);
    }
}

int get_node_count(Node* root){
    if (root == NULL){
        return 0;
    }

    return 1 + get_node_count(root->left) + get_node_count(root->right);
}

void print_tree_in(Node* root){
    if(root == NULL){
        return;
    }

    print_tree_in(root->left);
    printf("%d ", root->val);
    print_tree_in(root->right);
}

void morristraversal(Node* root){
    while(root){
        if(root->left){
            Node* pre = root->left;
            while(pre->right && pre->right != root)
                pre = pre->right;
            if(!pre->right){
                pre->right = root;
                root = root->left;
            } else {
                pre->right = NULL;
                printf("%d ", root->val);
                root = root->right;
            }
        } else {
            printf("%d ", root->val);
            root = root->right;
        }
    }
    return;
}

void print_tree_pre(Node *node){
    if (node == NULL)
        return;

    printf("%d ", node->val);
    print_tree_pre(node->left);
    print_tree_pre(node->right);
}

void print_tree_post(Node *root){
    if (root == NULL);
        return;

    print_tree_post(root->left);
    print_tree_post(root->right);
    printf("%d ",root->val);
}

void print_tree_in(Node *root){
    if (root == NULL);
        return;

    print_tree_post(root->left);
    printf("%d ",root->val);
    print_tree_post(root->right);
}

void delete_tree(Node* root){
    if (root == NULL) return;

    delete_tree(root->left);
    delete_tree(root->right);
    free(root);
}

bool in_tree(Node* root, int item){
    if (root == NULL)
        return false;

    else if (root->val == item)
        return true;

    else if (item < root->val)
        return in_tree(root->left, item);

    else if (item > root->val)
        return in_tree(root->right, item);
}

int get_height(Node * root){
    if (root == NULL)
        return -1;

    return 1 + max(get_height(root->left), get_height(root->right));
}

int min_node(Node* root){
    if (root == NULL){
        printf("Tree empty\n");
        exit(EXIT_FAILURE);
    }

    while (root->left != NULL)
        root = root->left;

    return root->val;
}

int max_node(Node *root){
    if(root == NULL){
        printf("Tree empty\n");
        exit(EXIT_FAILURE);
    }

    while(root->right != NULL)
        root = root->right;

    return root->val;
}

bool is_bst (Node* root){
    return node_check(root, INT_MIN, INT_MAX);
}

bool node_check(Node* root, int min, int max){
    if (root == NULL)
        return true;

    return root->val > min && root->val < max
            && node_check(root->left, min, root->val)
            && node_check(root->right, root->val, max);
}

void delete(Node **root, int item){
    if (*root == NULL)
        return;

    else if(item < (*root)->val)
        delete(&((*root)->left), item);
    else if(item > (*root)->val)
        delete(&((*root)->right), item);
    else{
        if ((*root)->left == NULL && (*root)->right == NULL){
            free(*root);
            return;
        }
        else if ((*root)->left == NULL){
            Node *node = *root;
            *root = (*root)->right;
            free(node);
            return;
        }
        else if ((*root)->right == NULL){
            Node* node = *root;
            *root = (*root)->left;
            free(node);
            return;
        }
        else{
            int temp = min_node((*root)->right);
            (*root)->val = temp;
            delete(&((*root)->right), temp);
            return;
        }
    }
}

Node* find(Node* root, int item){
    if (root == NULL)
        return NULL;

    else if (root->val == item)
        return root;

    else if (item < root->val)
        return find(root->left, item);

    else if (item > root->val)
        return find(root->right, item);
}

Node* get_successor(Node* root, int data){
    Node* current = find(root, data);
    if (current == NULL) return NULL;

    //HAS A RIGHT SUBTREE FIND,FIND LEFT MOST NODE OF THE RIGHT SUBTREE;
    if (current->right != NULL){
        Node* temp = current->right;
        while(temp->left)
            temp = temp->left;
        return temp;
    }
    //HAS NO RIGHT SUBTREE, FIND NEAREST ANCESTER FOR WHICH  CURRENT NODE IS IN ITS LEFT SUBTREE;
    else {
        Node* successor = NULL;
        Node* ancestor = root;

        while(ancestor != current){
            if (current->val < ancestor->val){
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else{
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}
