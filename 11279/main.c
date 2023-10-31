#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

typedef struct _NODE
{
	int _data;
} Node;

typedef struct _MAXHEAP
{
	int _capacity;
	int _usedsize;
	Node* _nodes;
} MaxHeap;

void CreateMaxHeap(MaxHeap** heap, int initSize)
{
	(*heap) = (MaxHeap*)malloc(sizeof(MaxHeap));
	(*heap)->_capacity = initSize;
	(*heap)->_usedsize = 0;
	(*heap)->_nodes = (Node*)malloc(sizeof(Node) * (*heap)->_capacity);
}

void DestroyMaxHeap(MaxHeap** heap)
{
	free((*heap)->_nodes);
	free((*heap));
}

int GetParentPosition(int index)
{
	return (index - 1) / 2;
}

int GetLeftChildrenPosition(int index)
{
	return 2 * index + 1;
}

void SwapNodes(MaxHeap** heap, int index1, int index2)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	memcpy(temp, &(*heap)->_nodes[index1], sizeof(Node));
	memcpy(&(*heap)->_nodes[index1], &(*heap)->_nodes[index2], sizeof(Node));
	memcpy(&(*heap)->_nodes[index2], temp, sizeof(Node));
}

void Push(MaxHeap** heap, int newData)
{
	int currentPosition = (*heap)->_usedsize;
	int parentPosition = GetParentPosition(currentPosition);
	
	if ((*heap)->_usedsize == (*heap)->_capacity)
	{
		(*heap)->_capacity *= 2;
		(*heap)->_nodes = (Node*)realloc((*heap)->_nodes, sizeof(Node) * (*heap)->_capacity);
	}

	(*heap)->_nodes[currentPosition]._data = newData;
	while (currentPosition > 0 && (*heap)->_nodes[currentPosition]._data > (*heap)->_nodes[parentPosition]._data)
	{
		SwapNodes(heap, currentPosition, parentPosition);
		currentPosition = parentPosition;
		parentPosition = GetParentPosition(currentPosition);
	}

	(*heap)->_usedsize++;
}

int GetRootData(MaxHeap** heap)
{
	return (*heap)->_nodes[0]._data;
}

void Pop(MaxHeap** heap)
{
	int currentPosition = 0;
	
	memset(&(*heap)->_nodes[currentPosition], 0, sizeof(Node));
	
	(*heap)->_usedsize--;
	SwapNodes(heap, currentPosition, (*heap)->_usedsize);
	int leftChildrenPosition = GetLeftChildrenPosition(currentPosition);
	int rightChildrenPosition = leftChildrenPosition + 1;

	while (1)
	{
		int selectedPosition = 0;
		if (leftChildrenPosition >= (*heap)->_usedsize)
		{
			break;
		}

		if (rightChildrenPosition >= (*heap)->_usedsize)
		{
			selectedPosition = leftChildrenPosition;
		}
		else
		{
			if ((*heap)->_nodes[leftChildrenPosition]._data > (*heap)->_nodes[rightChildrenPosition]._data)
			{
				selectedPosition = leftChildrenPosition;
			}
			else
			{
				selectedPosition = rightChildrenPosition;
			}
		}

		if ((*heap)->_nodes[selectedPosition]._data > (*heap)->_nodes[currentPosition]._data)
		{
			SwapNodes(heap, selectedPosition, currentPosition);
			currentPosition = selectedPosition;
		}
		else
		{
			break;
		}
		leftChildrenPosition = GetLeftChildrenPosition(currentPosition);
		rightChildrenPosition = leftChildrenPosition + 1;
	}
}

int main(void)
{
	MaxHeap* heap;
	CreateMaxHeap(&heap, 3);
	int N;
	scanf("%d", &N);
	
	for (int t = 0; t < N; ++t)
	{
		int num = 0;
		scanf("%d", &num);

		if (num == 0)
		{
			if (heap->_usedsize == 0)
			{
				printf("%d\n", 0);
			}
			else
			{
				printf("%d\n", GetRootData(&heap));
				Pop(&heap);
			}
		}
		else
		{
			Push(&heap, num);
		}
	}
	return 0;
}