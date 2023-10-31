#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

typedef struct _NODE
{
	unsigned int _data;
} Node;

typedef struct _HEAP
{
	int _capacity;
	int _usedsize;
	Node* _nodes;
} Heap;

void CreateHeap(Heap** h, int initSize)
{
	(*h) = (Heap*)malloc(sizeof(Heap));
	(*h)->_capacity = initSize;
	(*h)->_usedsize = 0;
	(*h)->_nodes = (Node*)malloc(sizeof(Node) * (*h)->_capacity);
}

void DestroyHeap(Heap** h)
{
	free((*h)->_nodes);
	free((*h));
}

int GetParent(int index)
{
	return (index - 1) / 2;
}

int GetLeftPosition(int index)
{
	return (2 * index + 1);
}

void SwapNodes(Heap** h, int index1, int index2)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	memcpy(temp, &(*h)->_nodes[index1], sizeof(Node));
	memcpy(&(*h)->_nodes[index1], &(*h)->_nodes[index2], sizeof(Node));
	memcpy(&(*h)->_nodes[index2], temp, sizeof(Node));
	free(temp);
}

void Push(Heap** h, unsigned int newData)
{
	int currentPosition = (*h)->_usedsize;
	int parentPosition = GetParent(currentPosition);

	if ((*h)->_capacity == (*h)->_usedsize)
	{
		(*h)->_capacity *= 2;
		(*h)->_nodes = (Node*)realloc((*h)->_nodes, sizeof(Node) * (*h)->_capacity);
	}

	(*h)->_nodes[currentPosition]._data = newData;

	while (currentPosition > 0 && (*h)->_nodes[currentPosition]._data < (*h)->_nodes[parentPosition]._data)
	{
		SwapNodes(h, currentPosition, parentPosition);
		currentPosition = parentPosition;
		parentPosition = GetParent(currentPosition);
	}

	(*h)->_usedsize++;
}

int GetRootData(Heap** h)
{
	return (*h)->_nodes[0]._data;
}

void Pop(Heap** h)
{
	int currentPosition = 0;
	(*h)->_usedsize--;

	memset(&(*h)->_nodes[0], 0, sizeof(Node));
	SwapNodes(h, 0, (*h)->_usedsize);

	int leftPosition = GetLeftPosition(currentPosition);
	int rightPosition = leftPosition + 1;

	while (1)
	{
		int selectedPosition = 0;
		if (leftPosition >= (*h)->_usedsize)
			break;
		if (rightPosition >= (*h)->_usedsize)
			selectedPosition = leftPosition;
		else
		{
			if ((*h)->_nodes[leftPosition]._data < (*h)->_nodes[rightPosition]._data)
				selectedPosition = leftPosition;
			else
				selectedPosition = rightPosition;
		}
		
		if ((*h)->_nodes[currentPosition]._data > (*h)->_nodes[selectedPosition]._data)
		{
			SwapNodes(h, currentPosition, selectedPosition);
			currentPosition = selectedPosition;
		}
		else
		{
			break;
		}

		leftPosition = GetLeftPosition(currentPosition);
		rightPosition = leftPosition + 1;
	}

	//if ((*h)->_usedsize == ((*h)->_capacity / 2))
	//{
	//	(*h)->_capacity /= 2;
	//	(*h)->_nodes = (Node*)realloc((*h)->_nodes, sizeof(Node) * (*h)->_capacity);
	//}
}


int main(void)
{
	Heap* heap;
	CreateHeap(&heap, 3);
	
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; ++t)
	{
		unsigned int num = 0;
		scanf("%u", &num);
		if (num == 0)
		{
			if (heap->_usedsize == 0)
			{
				printf("0\n");
			}
			else
			{
				printf("%u\n", GetRootData(&heap));
				Pop(&heap);
			}
		}
		else
		{
			Push(&heap, num);
		}
	}


	DestroyHeap(&heap);
	return 0;
}