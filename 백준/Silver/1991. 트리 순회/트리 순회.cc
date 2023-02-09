#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Tree{
	char data;
	struct Tree *left, *right;
}Tree;

Tree *makeNode(char n)
{
	Tree* node = (Tree*)malloc(sizeof(Tree));
	node->data = n;
	node->left = NULL;
	node->right = NULL;
	return node;
}

Tree *searchNode(Tree* node, char n)
{
	if (node == NULL)
		return NULL;
	else {
		if (node->data == n)
			return node;
		Tree* tmp = searchNode(node->left, n);
		if (tmp != NULL)
			return tmp;
		else
			return searchNode(node->right, n);
	}
}

void setNode(Tree* node, char mid, char left, char right)
{
	node->data = mid;
	if (left != '.')
		node->left = makeNode(left);
	if (right !='.')
		node->right = makeNode(right);
}

void preorder(Tree* root)
{
	if (root != NULL) {
		printf("%c", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(Tree* root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("%c", root->data);
		inorder(root->right);
	}
}

void postorder(Tree* root)
{
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%c", root->data);
	}
}

int main(void)
{
	int i, N, trash;
	char a, b, c;
	Tree* tree;
	Tree* tree2;

	tree = makeNode(NULL);
	tree2 = (Tree*)malloc(sizeof(Tree));

	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &trash);
		scanf("%c %c %c", &a, &b, &c);
		tree2 = searchNode(tree, a);
		if (tree2 != NULL)
			setNode(tree2, a, b, c);
		else
			setNode(tree, a, b, c);
	}
	preorder(tree);
	printf("\n");
	inorder(tree);
	printf("\n");
	postorder(tree);
	printf("\n");
}