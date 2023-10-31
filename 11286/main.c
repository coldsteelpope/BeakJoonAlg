#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

typedef struct _NODE
{
	int _data;
	int _abs_data;
} Node;

typedef struct _HEAP
{
	int _capacity;
	int _usedsize;
	Node* _nodes;
} Heap;

void CreateHeap(Heap** heap, int initSize)
{
	(*heap) = (Heap*)malloc(sizeof(Heap));
	(*heap)->_capacity = initSize;
	(*heap)->_usedsize = 0;
	(*heap)->_nodes = (Node*)malloc(sizeof(Node) * (*heap)->_capacity);
}

int GetParent(int index)
{
	return (index - 1) / 2;
}

int GetLeftPosition(int index)
{
	return 2 * index + 1;
}

void SwapNodes(Heap** heap, int index1, int index2)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	memcpy(temp, &(*heap)->_nodes[index1], sizeof(Node));
	memcpy(&(*heap)->_nodes[index1], &(*heap)->_nodes[index2], sizeof(Node));
	memcpy(&(*heap)->_nodes[index2], temp, sizeof(Node));
	free(temp);
}

void Push(Heap** heap, int newData)
{
	int currentPosition = (*heap)->_usedsize;
	int parentPosition = GetParent(currentPosition);

	if ((*heap)->_capacity == (*heap)->_usedsize)
	{
		(*heap)->_capacity *= 2;
		(*heap)->_nodes = (Node*)realloc((*heap)->_nodes, sizeof(Node) * (*heap)->_capacity);
	}

	(*heap)->_nodes[currentPosition]._data = newData;
	(*heap)->_nodes[currentPosition]._abs_data = abs(newData);

	while (currentPosition > 0 && (*heap)->_nodes[currentPosition]._abs_data <= (*heap)->_nodes[parentPosition]._abs_data)
	{
		if ((*heap)->_nodes[currentPosition]._abs_data == (*heap)->_nodes[parentPosition]._abs_data)
		{
			if ((*heap)->_nodes[currentPosition]._data <= (*heap)->_nodes[parentPosition]._data)
			{
				// Swap Nodes
				SwapNodes(heap, currentPosition, parentPosition);
				currentPosition = parentPosition;
				parentPosition = GetParent(currentPosition);
			}
			else
			{
				break;
			}
		}
		else
		{
			// Swap Nodes
			SwapNodes(heap, currentPosition, parentPosition);
			currentPosition = parentPosition;
			parentPosition = GetParent(currentPosition);
		}
	}
	(*heap)->_usedsize++;
}

Node GetRoot(Heap** heap)
{
	return (*heap)->_nodes[0];
}

void Pop(Heap** heap)
{
	int currentPosition = 0;
	memset(&(*heap)->_nodes[currentPosition], 0, sizeof(Node));
	
	(*heap)->_usedsize--;
	SwapNodes(heap, 0, (*heap)->_usedsize);

	int leftPosition = GetLeftPosition(currentPosition);
	int rightPosition = leftPosition + 1;

	while (1)
	{
		int selectedPosition = 0;
		if (leftPosition >= (*heap)->_usedsize)
			break;
		if (rightPosition >= (*heap)->_usedsize)
			selectedPosition = leftPosition;
		else
		{
			if ((*heap)->_nodes[leftPosition]._abs_data < (*heap)->_nodes[rightPosition]._abs_data)
			{
				selectedPosition = leftPosition;
			}
			else if ((*heap)->_nodes[leftPosition]._abs_data > (*heap)->_nodes[rightPosition]._abs_data)
			{
				selectedPosition = rightPosition;
			}
			else
			{
				if ((*heap)->_nodes[leftPosition]._data <= (*heap)->_nodes[rightPosition]._data)
				{
					selectedPosition = leftPosition;
				}
				else
				{
					selectedPosition = rightPosition;
				}
			}
		}

		if ((*heap)->_nodes[selectedPosition]._abs_data < (*heap)->_nodes[currentPosition]._abs_data)
		{
			SwapNodes(heap, selectedPosition, currentPosition);
			currentPosition = selectedPosition;
		}
		else if((*heap)->_nodes[selectedPosition]._abs_data > (*heap)->_nodes[currentPosition]._abs_data)
		{
			break;
		}
		else if ((*heap)->_nodes[selectedPosition]._abs_data == (*heap)->_nodes[currentPosition]._abs_data)
		{
			if ((*heap)->_nodes[selectedPosition]._data <= (*heap)->_nodes[currentPosition]._data)
			{
				SwapNodes(heap, selectedPosition, currentPosition);
				currentPosition = selectedPosition;
			}
			else
			{
				break;
			}
		}
		leftPosition = GetLeftPosition(currentPosition);
		rightPosition = leftPosition + 1;
	}

	
}

bool Empty(Heap** heap)
{
	return (*heap)->_usedsize == 0;
}

void DestroyHeap(Heap** heap)
{
	while (Empty(heap) == false)
		Pop(heap);
	free((*heap));
}

void PrintHeap(Heap** heap)
{
	printf("Current Heap Status: \n");
	printf("Current Heap UsedSize: %d \n", (*heap)->_usedsize);
	printf("Current Heap Capacity: %d \n", (*heap)->_capacity);
	for (int i = 0; i < (*heap)->_usedsize; ++i)
	{
		printf("%d\t", (*heap)->_nodes[i]);
	}
	printf("\n");
}

int main(void)
{
	int N;
	scanf("%d", &N);

	Heap* heap;
	CreateHeap(&heap, N);
	
	for (int i = 0; i < N; ++i)
	{
		int num;
		scanf("%d", &num);

		if (num == 0)
		{
			if (Empty(&heap) == false)
			{
				Node Root = GetRoot(&heap);
				printf("%d\n", Root._data);
				Pop(&heap);
			}
			else
			{
				printf("0\n");
			}
		}
		else
		{
			Push(&heap, num);
		}

		//PrintHeap(&heap);
	}
	return 0;
}