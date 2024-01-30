#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}Node;

Node* create(int val){
	Node* nn = (Node*)malloc(sizeof(Node));
	nn->data = val;
	nn->left = NULL;
	nn->right = NULL;
	return nn;
}

Node* add(Node* root, int val){
	if (val == -1) return root;
	if (root == NULL){
		root = create(val);
		return root;
	}else if(val >= root->data){
		root->right = add(root->right, val);
	}else if(val < root->data){
		root->left = add(root->left, val);
	}

	return root;
}

int bstSearch(Node* root, int key){
	if (root == NULL) return 0;
	if (key == root->data) return 1;
	if (key < root->data) return bstSearch(root->left, key);
	if (key > root->data) return bstSearch(root->right, key);
	return 0;
}

void inorder(Node* root){
	if (root != NULL){
		inorder(root->left);
		printf(" %d \n", root->data);
		inorder(root->right);
	}
}

void main(){
	Node* root = NULL;

	int input = -1;

	do{
		printf("\n give a user input, -1 to close");
		scanf("%d", &input);
		if (bstSearch(root, input) == 0) root = add(root, input);
		inorder(root);
	}while (input != -1);

}