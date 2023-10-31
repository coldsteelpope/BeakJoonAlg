#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _NODE
{
	int _data;
	struct _NODE* _left;
	struct _NODE* _right;
} Node;

Node* CreateNode(int data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->_data = data;
	newNode->_left = NULL;
	newNode->_right = NULL;
	return newNode;
}

void DestroyNode(Node** node)
{
	free((*node));
}

void DestroyTree(Node** tree)
{
	if ((*tree)->_right != NULL)
		DestroyTree(&(*tree)->_right);
	if ((*tree)->_left != NULL)
		DestroyTree(&(*tree)->_left);
	(*tree)->_left = NULL;
	(*tree)->_right = NULL;
	DestroyNode(tree);
}

void Insert(Node** tree, Node** child)
{
	if ((*tree)->_data < (*child)->_data)
	{
		if ((*tree)->_right == NULL)
			(*tree)->_right = (*child);
		else
			Insert(&(*tree)->_right, child);
	}
	else
	{
		if ((*tree)->_left == NULL)
			(*tree)->_left = (*child);
		else
			Insert(&(*tree)->_left, child);
	}
}

void GetPostOrderTraverse(Node** Tree)
{
	if ((*Tree) == NULL)
		return;

	GetPostOrderTraverse(&(*Tree)->_left);
	GetPostOrderTraverse(&(*Tree)->_right);
	printf("%d ", (*Tree)->_data);
}

int main(void)
{
	int num;
	Node* Tree;
	int count = 0;
	while (scanf("%d", &num) != EOF)
	{
		if (count == 0)
			Tree = CreateNode(num);
		else
		{
			Node* newNode = CreateNode(num);
			Insert(&Tree, &newNode);
		}
		++count;
	}
	GetPostOrderTraverse(&Tree);
	DestroyTree(&Tree);
	return 0;
}