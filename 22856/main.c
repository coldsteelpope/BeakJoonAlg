#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _NODE
{
	int _data;
	struct _NODE* _leftChild;
	struct _NODE* _rightChild;
} Node;

Node tree[100001] = { 0, };
int parents[100001] = { 0, };
int visited[100001] = { 0, };

int count = 0;
int seq = 0;
int inorderFinalValue = 0;

void InorderTraversal(Node* root)
{
	if (root == NULL)
		return;
	InorderTraversal(root->_leftChild);
	inorderFinalValue = root->_data;
	InorderTraversal(root->_rightChild);
}

void NewInorderTraversal(Node* root)
{
	if (root->_leftChild != NULL && visited[root->_leftChild->_data] == 0)
	{
		++count;
		visited[root->_leftChild->_data] = 1;
		NewInorderTraversal(&tree[root->_leftChild->_data]);
	}
	else if (root->_rightChild != NULL && visited[root->_rightChild->_data] == 0)
	{
		++count;
		visited[root->_rightChild->_data] = 1;
		NewInorderTraversal(&tree[root->_rightChild->_data]);
	}
	else if (root->_data == inorderFinalValue)
	{
		return;
	}
	else if (parents[root->_data] != 0)
	{
		++count;
		NewInorderTraversal(&tree[parents[root->_data]]);
	}
}

int main(void)
{
	int N;
	scanf("%d", &N);
	
	parents[1] = 1;
	for (int n = 0; n < N; ++n)
	{
		int root, left, right;
		scanf("%d%d%d", &root, &left, &right);
		tree[root]._data = root;
		
		if (left != -1)
		{
			tree[root]._leftChild = &tree[left];
			parents[left] = root;
		}

		if (right != -1)
		{
			tree[root]._rightChild = &tree[right];
			parents[right] = root;
		}
	}

	
	InorderTraversal(&tree[1]);
	NewInorderTraversal(&tree[1]);
	printf("%d\n", count);
	return 0;
}