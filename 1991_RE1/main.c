#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _NODE
{
	char _data;
	struct _NODE* _leftChild;
	struct _NODE* _rightChild;
} Node;

Node nodes[26] = { 0, };

void PreOrder(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		printf("%c", root->_data);
		PreOrder(root->_leftChild);
		PreOrder(root->_rightChild);
	}
}

void InOrder(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		InOrder(root->_leftChild);
		printf("%c", root->_data);
		InOrder(root->_rightChild);
	}
}

void PostOrder(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		PostOrder(root->_leftChild);
		PostOrder(root->_rightChild);
		printf("%c", root->_data);
	}
}

void SetNodes(int N)
{
	for (int n = 0; n < N; ++n)
	{
		char data;
		char left;
		char right;
		scanf("%c %c %c", &data, &left, &right);
		getchar();
		nodes[data - 'A']._data = data;
		nodes[data - 'A']._leftChild = (left == '.') ? NULL : &nodes[left - 'A'];
		nodes[data - 'A']._rightChild = (right == '.') ? NULL : &nodes[right - 'A'];
	}
}

int main(void)
{
	int N;
	scanf("%d", &N);
	getchar();
	SetNodes(N);

	PreOrder(&nodes[0]);
	printf("\n");
	InOrder(&nodes[0]);
	printf("\n");
	PostOrder(&nodes[0]);
	return 0;
}