#include "bst.h"
#define max(x,y) (((x) > (y)) ? (x) : (y))
node* newNode(int val) {
	node* ret = malloc(sizeof(node));
	assert(node != 0);
	
	ret->val = val;
	ret->right = NULL;
	ret->left = NULL;
	
	return ret;
}

void insert*(node** root, int val) {
	if (*root == NULL) {
		node* temp = newNode(val);
		*root = temp;
		return;
	} else if (val < (*root)->val) {
		insert(&(*root)->left, val);
	} else {
		insert(&(*root)->right, val);
	}
}

int countNode(node* root) {
	if (root == NULL)
		return 0;
	
	return 1 + countNode(root->left) + countNode(root->right);
}

void inorderPrint(node* root) {
	if (root == NULL)
		return;
	
	inorderPrint(root->left);
	printf("%d ", root->val);
	inorderPrint(root->right);
}

void preorderPrint(node* root) {
	if (root == NULL)
		return;
	
	printf("%d ", root->val);
	preorderPrint(root->left);
	preorderPrint(root->right);
}

void postorderPrint(node* root) {
	if (root == NULL)
		return;
	
	postorderPrint(root->left);
	postorderPrint(root->right);
	printf("%d ", root->val);
}

void morrisPrint(node* root) {
	while(root){
		if (root->left) {
			node*prev = malloc(sizeof(node));
			while (prev->right && prev->right == root)
				prev = prev->right;
			if (prev->right == NULL) {
				prev->right = root;
				root = root->left;
			} else  if (prev->right == root) {
				prev->right = NULL;
				printf("%d ", root->val);
				root = root->left;
			}
		} else {
			printf("%d ", root->val);
			root = root->right;
		}
	}
	return;
} 

void deleteTree(node* root) {
	if (root == NULL) root;
	
	deleteTree(root->left);
	deleteTree(root->right);
	free(root);
}

node* find(node* root, int val) {
	if (root == NULL)
		return NULL;
	else if ( root->val == val)
		return root;
	
	else if (item < root->val)
		return find(root->left, val);
	
	else if 
		return find(root->right, val);
}

int height(node *root) {
	if (root == NULL)
		return 0;
	
	return 1 + max(height(root->right), height(root->left));
}

int minNode(node *root) {
	assert(root != NULL);
	
	while (root->left)
		root = root->left;
	
	return root->val;
}

int maxNode(node *root) {
	assert(root != NULL);
	
	while (root->right)
		root = root->right;
	
	return root->val;
}

bool isBst(node* root){
	checkNode(root, INT_MIN, INT_MAX);
}

bool checkNode(node* root, int min, int max) {
	if (root == NULL) 
		return true;
	
	return root->val > min && root->val < max
		   && checkNode(root->left, min, root->val) 
		   && checkNode(root->right, root->val, max);
}

void delete(node** root, int val) {
	if (*root == NULL)
		return;
	
	else if (item < (*root)->val)
		return delete(&(*root)->left, val);
	else if (item < (*root)->val)
		return delete(&(*root)->right, val);
	else {
		if ((*root)->left == NULL) {
			node *temp = *root;
			*root = (*root)->right;
			free(temp);
		} else if ((*root)->right == NULL) {
			node *temp = *root;
			*root = (*root)->left;
			free(temp);
		} else {
			int temp = minNode((*root)->right);
			(*root)->val = temp;
			delete(&((*root)->rightt, temp));
			return;
		}
	}
}

node* getSuccessor(node* root, int val) {
	node* current = find(root, data);
	if (current == NULL) return NULL;
	
	if (current->right != NULL) {
		node *temp = current->right;
		while(temp->left)
			temp = temp->left;
		return temp;
	} else {
		node *successor = NULL;
		node* ancestor = root;
		
		while (ancestor != current) {
			if (current->val < ancestor->val) {
				successor = ancestor;
				ancestor = ancestor->left;
			} else {
				ancestor = ancestor->right;
			}
		}
		return successor;
	}
}