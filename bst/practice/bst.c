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

bool find(node* root, int val) {
	if (root == NULL)
		return false;
	else if ( root->val == val)
		return true;
	
	else if (item < root->val)
		return find(root->left, val);
	
	else if 
		return find(root->right, val);
}

int height(node *root) {
	return
}